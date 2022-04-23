namespace Luiz_Leite
{
    partial class Avancado
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.MTCavancado = new MetroFramework.Controls.MetroTabControl();
            this.MTPcronograma = new MetroFramework.Controls.MetroTabPage();
            this.btnzerar = new FontAwesome.Sharp.IconButton();
            this.btnvolta = new FontAwesome.Sharp.IconButton();
            this.btnpausar = new FontAwesome.Sharp.IconButton();
            this.btninicio = new FontAwesome.Sharp.IconButton();
            this.RTBvoltas = new System.Windows.Forms.RichTextBox();
            this.lblcronograma = new System.Windows.Forms.Label();
            this.MTBSlideavancado = new MetroFramework.Controls.MetroTabPage();
            this.metroLabel1 = new MetroFramework.Controls.MetroLabel();
            this.CBintervalo = new MetroFramework.Controls.MetroComboBox();
            this.btniniciar = new FontAwesome.Sharp.IconButton();
            this.btnparar = new FontAwesome.Sharp.IconButton();
            this.btnescolher = new FontAwesome.Sharp.IconButton();
            this.PBslide = new System.Windows.Forms.PictureBox();
            this.btnHOME = new FontAwesome.Sharp.IconButton();
            this.Ttempo = new System.Windows.Forms.Timer(this.components);
            this.SFDtempo = new System.Windows.Forms.SaveFileDialog();
            this.OFDimagens = new System.Windows.Forms.OpenFileDialog();
            this.Timagens = new System.Windows.Forms.Timer(this.components);
            this.MTCavancado.SuspendLayout();
            this.MTPcronograma.SuspendLayout();
            this.MTBSlideavancado.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.PBslide)).BeginInit();
            this.SuspendLayout();
            // 
            // MTCavancado
            // 
            this.MTCavancado.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.MTCavancado.Controls.Add(this.MTPcronograma);
            this.MTCavancado.Controls.Add(this.MTBSlideavancado);
            this.MTCavancado.Location = new System.Drawing.Point(17, 102);
            this.MTCavancado.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.MTCavancado.Name = "MTCavancado";
            this.MTCavancado.SelectedIndex = 1;
            this.MTCavancado.Size = new System.Drawing.Size(986, 532);
            this.MTCavancado.TabIndex = 0;
            this.MTCavancado.Theme = MetroFramework.MetroThemeStyle.Dark;
            this.MTCavancado.UseSelectable = true;
            // 
            // MTPcronograma
            // 
            this.MTPcronograma.Controls.Add(this.btnzerar);
            this.MTPcronograma.Controls.Add(this.btnvolta);
            this.MTPcronograma.Controls.Add(this.btnpausar);
            this.MTPcronograma.Controls.Add(this.btninicio);
            this.MTPcronograma.Controls.Add(this.RTBvoltas);
            this.MTPcronograma.Controls.Add(this.lblcronograma);
            this.MTPcronograma.HorizontalScrollbarBarColor = true;
            this.MTPcronograma.HorizontalScrollbarHighlightOnWheel = false;
            this.MTPcronograma.HorizontalScrollbarSize = 8;
            this.MTPcronograma.Location = new System.Drawing.Point(4, 38);
            this.MTPcronograma.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.MTPcronograma.Name = "MTPcronograma";
            this.MTPcronograma.Size = new System.Drawing.Size(978, 490);
            this.MTPcronograma.TabIndex = 0;
            this.MTPcronograma.Text = "Cronograma        ";
            this.MTPcronograma.Theme = MetroFramework.MetroThemeStyle.Light;
            this.MTPcronograma.ToolTipText = "Um cronograma simples que grava suas voltas";
            this.MTPcronograma.VerticalScrollbarBarColor = true;
            this.MTPcronograma.VerticalScrollbarHighlightOnWheel = false;
            this.MTPcronograma.VerticalScrollbarSize = 8;
            // 
            // btnzerar
            // 
            this.btnzerar.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
            this.btnzerar.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnzerar.IconChar = FontAwesome.Sharp.IconChar.Stop;
            this.btnzerar.IconColor = System.Drawing.Color.Black;
            this.btnzerar.IconSize = 32;
            this.btnzerar.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnzerar.Location = new System.Drawing.Point(768, 403);
            this.btnzerar.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.btnzerar.Name = "btnzerar";
            this.btnzerar.Rotation = 0D;
            this.btnzerar.Size = new System.Drawing.Size(210, 72);
            this.btnzerar.TabIndex = 7;
            this.btnzerar.Text = "Zerar";
            this.btnzerar.UseVisualStyleBackColor = true;
            this.btnzerar.Click += new System.EventHandler(this.btnzerar_Click);
            // 
            // btnvolta
            // 
            this.btnvolta.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
            this.btnvolta.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnvolta.IconChar = FontAwesome.Sharp.IconChar.Edit;
            this.btnvolta.IconColor = System.Drawing.Color.Black;
            this.btnvolta.IconSize = 32;
            this.btnvolta.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnvolta.Location = new System.Drawing.Point(768, 251);
            this.btnvolta.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.btnvolta.Name = "btnvolta";
            this.btnvolta.Rotation = 0D;
            this.btnvolta.Size = new System.Drawing.Size(210, 147);
            this.btnvolta.TabIndex = 6;
            this.btnvolta.Text = "Volta";
            this.btnvolta.UseVisualStyleBackColor = true;
            this.btnvolta.Click += new System.EventHandler(this.btnvolta_Click);
            // 
            // btnpausar
            // 
            this.btnpausar.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
            this.btnpausar.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnpausar.IconChar = FontAwesome.Sharp.IconChar.Pause;
            this.btnpausar.IconColor = System.Drawing.Color.Black;
            this.btnpausar.IconSize = 32;
            this.btnpausar.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnpausar.Location = new System.Drawing.Point(768, 99);
            this.btnpausar.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.btnpausar.Name = "btnpausar";
            this.btnpausar.Rotation = 0D;
            this.btnpausar.Size = new System.Drawing.Size(210, 147);
            this.btnpausar.TabIndex = 5;
            this.btnpausar.Text = "Pausar";
            this.btnpausar.UseVisualStyleBackColor = true;
            this.btnpausar.Click += new System.EventHandler(this.btnpausar_Click);
            // 
            // btninicio
            // 
            this.btninicio.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
            this.btninicio.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btninicio.IconChar = FontAwesome.Sharp.IconChar.Play;
            this.btninicio.IconColor = System.Drawing.Color.Black;
            this.btninicio.IconSize = 32;
            this.btninicio.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btninicio.Location = new System.Drawing.Point(768, 23);
            this.btninicio.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.btninicio.Name = "btninicio";
            this.btninicio.Rotation = 0D;
            this.btninicio.Size = new System.Drawing.Size(210, 72);
            this.btninicio.TabIndex = 4;
            this.btninicio.Text = "Iniciar";
            this.btninicio.UseVisualStyleBackColor = true;
            this.btninicio.Click += new System.EventHandler(this.btninicio_Click);
            // 
            // RTBvoltas
            // 
            this.RTBvoltas.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.RTBvoltas.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.RTBvoltas.Location = new System.Drawing.Point(236, 23);
            this.RTBvoltas.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.RTBvoltas.Name = "RTBvoltas";
            this.RTBvoltas.Size = new System.Drawing.Size(528, 452);
            this.RTBvoltas.TabIndex = 3;
            this.RTBvoltas.Text = "";
            // 
            // lblcronograma
            // 
            this.lblcronograma.AutoSize = true;
            this.lblcronograma.BackColor = System.Drawing.Color.White;
            this.lblcronograma.Font = new System.Drawing.Font("Segoe UI", 72F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblcronograma.Location = new System.Drawing.Point(61, 167);
            this.lblcronograma.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lblcronograma.Name = "lblcronograma";
            this.lblcronograma.Size = new System.Drawing.Size(94, 128);
            this.lblcronograma.TabIndex = 2;
            this.lblcronograma.Text = "-";
            this.lblcronograma.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // MTBSlideavancado
            // 
            this.MTBSlideavancado.Controls.Add(this.metroLabel1);
            this.MTBSlideavancado.Controls.Add(this.CBintervalo);
            this.MTBSlideavancado.Controls.Add(this.btniniciar);
            this.MTBSlideavancado.Controls.Add(this.btnparar);
            this.MTBSlideavancado.Controls.Add(this.btnescolher);
            this.MTBSlideavancado.Controls.Add(this.PBslide);
            this.MTBSlideavancado.HorizontalScrollbarBarColor = true;
            this.MTBSlideavancado.HorizontalScrollbarHighlightOnWheel = false;
            this.MTBSlideavancado.HorizontalScrollbarSize = 8;
            this.MTBSlideavancado.Location = new System.Drawing.Point(4, 38);
            this.MTBSlideavancado.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.MTBSlideavancado.Name = "MTBSlideavancado";
            this.MTBSlideavancado.Size = new System.Drawing.Size(978, 490);
            this.MTBSlideavancado.TabIndex = 1;
            this.MTBSlideavancado.Text = "   Slides    ";
            this.MTBSlideavancado.ToolTipText = "Selecione um grupo de imagens para exibir";
            this.MTBSlideavancado.VerticalScrollbarBarColor = true;
            this.MTBSlideavancado.VerticalScrollbarHighlightOnWheel = false;
            this.MTBSlideavancado.VerticalScrollbarSize = 8;
            // 
            // metroLabel1
            // 
            this.metroLabel1.AutoSize = true;
            this.metroLabel1.FontSize = MetroFramework.MetroLabelSize.Tall;
            this.metroLabel1.Location = new System.Drawing.Point(800, 382);
            this.metroLabel1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.metroLabel1.Name = "metroLabel1";
            this.metroLabel1.Size = new System.Drawing.Size(86, 25);
            this.metroLabel1.TabIndex = 7;
            this.metroLabel1.Text = "Intervalo :";
            // 
            // CBintervalo
            // 
            this.CBintervalo.Enabled = false;
            this.CBintervalo.FontSize = MetroFramework.MetroComboBoxSize.Tall;
            this.CBintervalo.FormattingEnabled = true;
            this.CBintervalo.ItemHeight = 29;
            this.CBintervalo.Items.AddRange(new object[] {
            "1 segundo",
            "2 segundos",
            "3 segundos",
            "4 segundos",
            "5 segundos",
            "6 segundos",
            "7 segundos",
            "8 segundos",
            "9 segundos",
            "10 segundos"});
            this.CBintervalo.Location = new System.Drawing.Point(800, 420);
            this.CBintervalo.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.CBintervalo.Name = "CBintervalo";
            this.CBintervalo.Size = new System.Drawing.Size(179, 35);
            this.CBintervalo.TabIndex = 6;
            this.CBintervalo.UseSelectable = true;
            this.CBintervalo.SelectedIndexChanged += new System.EventHandler(this.CBintervalo_SelectedIndexChanged);
            // 
            // btniniciar
            // 
            this.btniniciar.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.btniniciar.Enabled = false;
            this.btniniciar.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
            this.btniniciar.Font = new System.Drawing.Font("Segoe UI", 22.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btniniciar.IconChar = FontAwesome.Sharp.IconChar.Play;
            this.btniniciar.IconColor = System.Drawing.Color.Black;
            this.btniniciar.IconSize = 40;
            this.btniniciar.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btniniciar.Location = new System.Drawing.Point(668, 251);
            this.btniniciar.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.btniniciar.Name = "btniniciar";
            this.btniniciar.Rotation = 0D;
            this.btniniciar.Size = new System.Drawing.Size(310, 120);
            this.btniniciar.TabIndex = 5;
            this.btniniciar.Text = "Iniciar";
            this.btniniciar.UseVisualStyleBackColor = false;
            this.btniniciar.Click += new System.EventHandler(this.btniniciar_Click);
            // 
            // btnparar
            // 
            this.btnparar.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.btnparar.Enabled = false;
            this.btnparar.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
            this.btnparar.Font = new System.Drawing.Font("Segoe UI", 22.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnparar.IconChar = FontAwesome.Sharp.IconChar.Stop;
            this.btnparar.IconColor = System.Drawing.Color.Black;
            this.btnparar.IconSize = 40;
            this.btnparar.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnparar.Location = new System.Drawing.Point(668, 130);
            this.btnparar.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.btnparar.Name = "btnparar";
            this.btnparar.Rotation = 0D;
            this.btnparar.Size = new System.Drawing.Size(310, 120);
            this.btnparar.TabIndex = 4;
            this.btnparar.Text = "Parar";
            this.btnparar.UseVisualStyleBackColor = false;
            this.btnparar.Click += new System.EventHandler(this.btnparar_Click);
            // 
            // btnescolher
            // 
            this.btnescolher.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.btnescolher.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Teal;
            this.btnescolher.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.btnescolher.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
            this.btnescolher.Font = new System.Drawing.Font("Segoe UI", 22.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnescolher.IconChar = FontAwesome.Sharp.IconChar.Search;
            this.btnescolher.IconColor = System.Drawing.Color.Black;
            this.btnescolher.IconSize = 40;
            this.btnescolher.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnescolher.Location = new System.Drawing.Point(668, 5);
            this.btnescolher.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.btnescolher.Name = "btnescolher";
            this.btnescolher.Rotation = 0D;
            this.btnescolher.Size = new System.Drawing.Size(310, 124);
            this.btnescolher.TabIndex = 3;
            this.btnescolher.Text = "Escolher";
            this.btnescolher.UseVisualStyleBackColor = false;
            this.btnescolher.Click += new System.EventHandler(this.btnescolher_Click);
            // 
            // PBslide
            // 
            this.PBslide.BackColor = System.Drawing.Color.White;
            this.PBslide.Location = new System.Drawing.Point(4, 5);
            this.PBslide.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.PBslide.Name = "PBslide";
            this.PBslide.Size = new System.Drawing.Size(600, 488);
            this.PBslide.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.PBslide.TabIndex = 2;
            this.PBslide.TabStop = false;
            // 
            // btnHOME
            // 
            this.btnHOME.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnHOME.FlatAppearance.BorderSize = 0;
            this.btnHOME.FlatAppearance.MouseDownBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.btnHOME.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Teal;
            this.btnHOME.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnHOME.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
            this.btnHOME.IconChar = FontAwesome.Sharp.IconChar.Home;
            this.btnHOME.IconColor = System.Drawing.Color.White;
            this.btnHOME.IconSize = 40;
            this.btnHOME.Location = new System.Drawing.Point(944, 55);
            this.btnHOME.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.btnHOME.Name = "btnHOME";
            this.btnHOME.Rotation = 0D;
            this.btnHOME.Size = new System.Drawing.Size(57, 43);
            this.btnHOME.TabIndex = 16;
            this.btnHOME.UseVisualStyleBackColor = true;
            this.btnHOME.Click += new System.EventHandler(this.btnHOME_Click);
            // 
            // Ttempo
            // 
            this.Ttempo.Interval = 1000;
            this.Ttempo.Tick += new System.EventHandler(this.Ttempo_Tick);
            // 
            // SFDtempo
            // 
            this.SFDtempo.Filter = "Arquivo de texto|*.txt";
            // 
            // OFDimagens
            // 
            this.OFDimagens.FileName = "Imagens";
            this.OFDimagens.Filter = "Imagens |*.jpg";
            this.OFDimagens.Multiselect = true;
            // 
            // Timagens
            // 
            this.Timagens.Interval = 1000;
            this.Timagens.Tick += new System.EventHandler(this.Timagens_Tick);
            // 
            // Avancado
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1021, 653);
            this.Controls.Add(this.btnHOME);
            this.Controls.Add(this.MTCavancado);
            this.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Name = "Avancado";
            this.Padding = new System.Windows.Forms.Padding(15, 49, 15, 16);
            this.Text = "Avancado";
            this.Theme = MetroFramework.MetroThemeStyle.Dark;
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.btnHOME_Click);
            this.Load += new System.EventHandler(this.Avancado_Load);
            this.MTCavancado.ResumeLayout(false);
            this.MTPcronograma.ResumeLayout(false);
            this.MTPcronograma.PerformLayout();
            this.MTBSlideavancado.ResumeLayout(false);
            this.MTBSlideavancado.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.PBslide)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private MetroFramework.Controls.MetroTabControl MTCavancado;
        private MetroFramework.Controls.MetroTabPage MTPcronograma;
        private FontAwesome.Sharp.IconButton btnHOME;
        private FontAwesome.Sharp.IconButton btnzerar;
        private FontAwesome.Sharp.IconButton btnvolta;
        private FontAwesome.Sharp.IconButton btnpausar;
        private FontAwesome.Sharp.IconButton btninicio;
        private System.Windows.Forms.RichTextBox RTBvoltas;
        private System.Windows.Forms.Label lblcronograma;
        private System.Windows.Forms.Timer Ttempo;
        private System.Windows.Forms.SaveFileDialog SFDtempo;
        private MetroFramework.Controls.MetroTabPage MTBSlideavancado;
        private MetroFramework.Controls.MetroLabel metroLabel1;
        private MetroFramework.Controls.MetroComboBox CBintervalo;
        private FontAwesome.Sharp.IconButton btniniciar;
        private FontAwesome.Sharp.IconButton btnparar;
        private FontAwesome.Sharp.IconButton btnescolher;
        private System.Windows.Forms.PictureBox PBslide;
        private System.Windows.Forms.OpenFileDialog OFDimagens;
        private System.Windows.Forms.Timer Timagens;
    }
}