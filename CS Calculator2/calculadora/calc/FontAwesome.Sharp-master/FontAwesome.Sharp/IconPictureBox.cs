using System;
using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;

namespace FontAwesome.Sharp
{
    public class IconPictureBox : PictureBox, IFormsIcon
    {
        private static readonly IconCache IconCache = new IconCache();

        private const IconChar DefaultIconChar = IconChar.Star;
        private const int DefaultIconSize = 32;

        public new static Size DefaultSize = new Size(DefaultIconSize, DefaultIconSize);
        public new static Color DefaultForeColor = Color.Black;
        public new static Color DefaultBackColor = Color.White;

        private IconChar _iconChar = DefaultIconChar;
        private IconChar _lastIconChar = DefaultIconChar;

        private int _iconSize = DefaultIconSize;
        private int _lasticonSize = DefaultIconSize;

        private double _rotation;
        private double _lastRotation;

        private FlipOrientation _flip = FlipOrientation.Normal;
        private FlipOrientation _lastFlip = FlipOrientation.Normal;

        private Color _lastBgColor;
        private Color _lastFontColor;

        public IconPictureBox()
        {
            Size = DefaultSize;

            SetStyle(
                ControlStyles.AllPaintingInWmPaint |
                ControlStyles.UserPaint |
                ControlStyles.DoubleBuffer,
                true
            );

            Invalidated += Draw;
            SizeChanged += IconPictureBox_SizeChanged;
            Disposed += IconPictureBox_Disposed;
            Draw();
        }

        [Category("FontAwesome")]
        [Description(
            "Enable or disable icons caching. Usefull, when you have several controls with same large size icon and you want to save some memory. Also usefull for color change and simple fast animations. Icons is caching by icon, size, 2 colors, rotation, flip.")]
        [DefaultValue(false)]
        public bool UseIconCache { get; set; }

        [Category("FontAwesome")]
        public Color IconColor { get => ForeColor; set => ForeColor = value; }

        [Category("FontAwesome")]
        [DefaultValue(FlipOrientation.Normal)]
        public FlipOrientation Flip
        {
            get => _flip;
            set
            {
                if (_flip == value) return;
                _flip = value;
                Invalidate();
            }
        }

        [Category("FontAwesome")]
        [DefaultValue(0.0)]
        public double Rotation
        {
            get => _rotation;
            set
            {
                var v = value % 360.0;
                if (Math.Abs(_rotation - v) < 0.5) return;
                _rotation = v;
                Invalidate();
            }
        }

        [Category("FontAwesome")]
        [DefaultValue(DefaultIconChar)]
        public IconChar IconChar
        {
            get => _iconChar;
            set
            {
                if (value == _iconChar) return;
                _iconChar = value;
                char.ConvertFromUtf32((int) _iconChar);
                Invalidate();
            }
        }

        [Category("FontAwesome")]
        [Description(
            "Can be used only in AutoSize or CenterImage SizeMode. in other modes depends on Width and Height: `Math.Min(Width, Height)`.")]
        [DefaultValue(DefaultIconSize)]
        public int IconSize
        {
            get => _iconSize;
            set
            {
                if (value == _iconSize) return;
                _iconSize = value;
                Invalidate();
            }
        }

        // override fore/back color attributes to make them designer-visible (PictureBox hides them)
        [EditorBrowsable(EditorBrowsableState.Always)]
        [Browsable(true)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Visible)]
        [Bindable(true)]
        public new Color ForeColor
        {
            get => base.ForeColor;
            set
            {
                if (base.ForeColor == value) return;
                base.ForeColor = value;
                Invalidate();
            }
        }

        [EditorBrowsable(EditorBrowsableState.Always)]
        [Browsable(true)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Visible)]
        [Bindable(true)]
        public new Color BackColor
        {
            get => base.BackColor;
            set
            {
                if (base.BackColor == value) return;
                base.BackColor = value;
                Invalidate();
            }
        }

        // Define default attributes for designer serialization.
        // Note: Use DefaultValueAttribute or ShouldSerialize/Reset-methods for a property. Don't use both!
        // cf.: https://docs.microsoft.com/en-us/dotnet/framework/winforms/controls/defining-default-values-with-the-shouldserialize-and-reset-methods
        public bool ShouldSerializeImage() { return false; }
        public bool ShouldSerializeForeColor() { return base.ForeColor != DefaultBackColor; }
        public new void ResetForeColor() { ForeColor = DefaultBackColor; }
        public bool ShouldSerializeBackColor() { return base.BackColor != DefaultForeColor; }
        public new void ResetBackColor() { ForeColor = DefaultForeColor; }

        // hide Image in designer (we want only icon)
        [ReadOnly(true), Browsable(false), EditorBrowsable(EditorBrowsableState.Never)]
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public new Image Image
        {
            get => base.Image;
            set => base.Image = value;
        }

        public void Draw(object sender = null, InvalidateEventArgs e = null)
        {
            if (base.Image != null)
            {
                var changed = _iconSize != _lasticonSize ||
                        base.BackColor != _lastBgColor ||
                        base.ForeColor != _lastFontColor ||
                        _iconChar != _lastIconChar ||
                        _flip != _lastFlip ||
                        Math.Abs(_rotation - _lastRotation) >= 0.5;
                if (!changed) return;

                if (!UseIconCache)
                    base.Image.Dispose(); // Dispose old image - in other case we will have memory leaks
            }

            _lasticonSize = _iconSize;
            _lastBgColor = base.BackColor;
            _lastFontColor = base.ForeColor;
            _lastIconChar = _iconChar;
            _lastFlip = _flip;
            _lastRotation = _rotation;

            Image = UseIconCache
                ? IconCache.Get(_iconChar, _iconSize, IconColor, BackColor)
                : _iconChar.ToBitmapGdi(IconSize, base.ForeColor, base.BackColor);
        }

        private void IconPictureBox_Disposed(object sender, EventArgs e)
        {
            base.Image = null; // In some cases, catch errors in forms constructor with image
        }

        private void IconPictureBox_SizeChanged(object sender, EventArgs e)
        {
            if (SizeMode != PictureBoxSizeMode.AutoSize)
                IconSize = Math.Min(Width, Height);
            Invalidate();
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            var graphics = e.Graphics;

            Draw();

            graphics.Flip(Flip, Width, Height);
            graphics.Rotate(Rotation, Width, Height);

            base.OnPaint(e);

            if (!Focused) return;
            var rc = ClientRectangle;
            rc.Inflate(-2, -2);
            ControlPaint.DrawFocusRectangle(e.Graphics, rc);
        }
    }
}
