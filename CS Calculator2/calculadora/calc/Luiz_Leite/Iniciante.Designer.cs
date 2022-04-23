namespace Luiz_Leite
{
    partial class Iniciante
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
            this.MTBiniciante = new MetroFramework.Controls.MetroTabControl();
            this.tabvm = new MetroFramework.Controls.MetroTabPage();
            this.btnlimpar = new FontAwesome.Sharp.IconButton();
            this.lblresultado = new MetroFramework.Controls.MetroLabel();
            this.btncalcular = new FontAwesome.Sharp.IconButton();
            this.txttempo = new MetroFramework.Controls.MetroTextBox();
            this.txtespaco = new MetroFramework.Controls.MetroTextBox();
            this.tabsoma = new System.Windows.Forms.TabPage();
            this.iconButton1 = new FontAwesome.Sharp.IconButton();
            this.lblsoma = new MetroFramework.Controls.MetroLabel();
            this.btnsomatoria = new FontAwesome.Sharp.IconButton();
            this.txtsoma = new MetroFramework.Controls.MetroTextBox();
            this.btnHOME = new FontAwesome.Sharp.IconButton();
            this.MTBiniciante.SuspendLayout();
            this.tabvm.SuspendLayout();
            this.tabsoma.SuspendLayout();
            this.SuspendLayout();
            // 
            // MTBiniciante
            // 
            this.MTBiniciante.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.MTBiniciante.Controls.Add(this.tabvm);
            this.MTBiniciante.Controls.Add(this.tabsoma);
            this.MTBiniciante.Location = new System.Drawing.Point(64, 150);
            this.MTBiniciante.Name = "MTBiniciante";
            this.MTBiniciante.SelectedIndex = 1;
            this.MTBiniciante.ShowToolTips = true;
            this.MTBiniciante.Size = new System.Drawing.Size(983, 539);
            this.MTBiniciante.TabIndex = 0;
            this.MTBiniciante.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.MTBiniciante.Theme = MetroFramework.MetroThemeStyle.Dark;
            this.MTBiniciante.UseSelectable = true;
            // 
            // tabvm
            // 
            this.tabvm.BackColor = System.Drawing.Color.White;
            this.tabvm.Controls.Add(this.btnlimpar);
            this.tabvm.Controls.Add(this.lblresultado);
            this.tabvm.Controls.Add(this.btncalcular);
            this.tabvm.Controls.Add(this.txttempo);
            this.tabvm.Controls.Add(this.txtespaco);
            this.tabvm.Font = new System.Drawing.Font("Microsoft Sans Serif", 19.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tabvm.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.tabvm.HorizontalScrollbarBarColor = true;
            this.tabvm.HorizontalScrollbarHighlightOnWheel = false;
            this.tabvm.HorizontalScrollbarSize = 10;
            this.tabvm.Location = new System.Drawing.Point(4, 38);
            this.tabvm.Name = "tabvm";
            this.tabvm.Size = new System.Drawing.Size(975, 497);
            this.tabvm.TabIndex = 0;
            this.tabvm.Text = "VM";
            this.tabvm.ToolTipText = "Calcular a Velocidade Média";
            this.tabvm.VerticalScrollbarBarColor = true;
            this.tabvm.VerticalScrollbarHighlightOnWheel = false;
            this.tabvm.VerticalScrollbarSize = 10;
            // 
            // btnlimpar
            // 
            this.btnlimpar.BackColor = System.Drawing.Color.Teal;
            this.btnlimpar.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
            this.btnlimpar.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnlimpar.IconChar = FontAwesome.Sharp.IconChar.Eraser;
            this.btnlimpar.IconColor = System.Drawing.Color.White;
            this.btnlimpar.IconSize = 32;
            this.btnlimpar.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnlimpar.Location = new System.Drawing.Point(32, 303);
            this.btnlimpar.Name = "btnlimpar";
            this.btnlimpar.Rotation = 0D;
            this.btnlimpar.Size = new System.Drawing.Size(212, 93);
            this.btnlimpar.TabIndex = 6;
            this.btnlimpar.Text = "Limpar";
            this.btnlimpar.UseVisualStyleBackColor = false;
            this.btnlimpar.Click += new System.EventHandler(this.btnlimpar_Click);
            // 
            // lblresultado
            // 
            this.lblresultado.AutoSize = true;
            this.lblresultado.FontSize = MetroFramework.MetroLabelSize.Tall;
            this.lblresultado.FontWeight = MetroFramework.MetroLabelWeight.Bold;
            this.lblresultado.Location = new System.Drawing.Point(500, 58);
            this.lblresultado.Name = "lblresultado";
            this.lblresultado.Size = new System.Drawing.Size(66, 25);
            this.lblresultado.TabIndex = 5;
            this.lblresultado.Text = "VM = ";
            this.lblresultado.WrapToLine = true;
            // 
            // btncalcular
            // 
            this.btncalcular.BackColor = System.Drawing.Color.Teal;
            this.btncalcular.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
            this.btncalcular.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btncalcular.IconChar = FontAwesome.Sharp.IconChar.InfoCircle;
            this.btncalcular.IconColor = System.Drawing.Color.White;
            this.btncalcular.IconSize = 32;
            this.btncalcular.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btncalcular.Location = new System.Drawing.Point(32, 204);
            this.btncalcular.Name = "btncalcular";
            this.btncalcular.Rotation = 0D;
            this.btncalcular.Size = new System.Drawing.Size(212, 93);
            this.btncalcular.TabIndex = 4;
            this.btncalcular.Text = "Calcular";
            this.btncalcular.UseVisualStyleBackColor = false;
            this.btncalcular.Click += new System.EventHandler(this.btncalcular_Click);
            // 
            // txttempo
            // 
            // 
            // 
            // 
            this.txttempo.CustomButton.Image = null;
            this.txttempo.CustomButton.Location = new System.Drawing.Point(262, 1);
            this.txttempo.CustomButton.Name = "";
            this.txttempo.CustomButton.Size = new System.Drawing.Size(43, 43);
            this.txttempo.CustomButton.Style = MetroFramework.MetroColorStyle.Blue;
            this.txttempo.CustomButton.TabIndex = 1;
            this.txttempo.CustomButton.Theme = MetroFramework.MetroThemeStyle.Light;
            this.txttempo.CustomButton.UseSelectable = true;
            this.txttempo.CustomButton.Visible = false;
            this.txttempo.FontSize = MetroFramework.MetroTextBoxSize.Medium;
            this.txttempo.Lines = new string[0];
            this.txttempo.Location = new System.Drawing.Point(32, 124);
            this.txttempo.MaxLength = 32767;
            this.txttempo.Multiline = true;
            this.txttempo.Name = "txttempo";
            this.txttempo.PasswordChar = '\0';
            this.txttempo.PromptText = "Insira o tempo(em s)...";
            this.txttempo.ScrollBars = System.Windows.Forms.ScrollBars.None;
            this.txttempo.SelectedText = "";
            this.txttempo.SelectionLength = 0;
            this.txttempo.SelectionStart = 0;
            this.txttempo.ShortcutsEnabled = true;
            this.txttempo.Size = new System.Drawing.Size(306, 45);
            this.txttempo.TabIndex = 3;
            this.txttempo.Theme = MetroFramework.MetroThemeStyle.Dark;
            this.txttempo.UseSelectable = true;
            this.txttempo.WaterMark = "Insira o tempo(em s)...";
            this.txttempo.WaterMarkColor = System.Drawing.Color.FromArgb(((int)(((byte)(109)))), ((int)(((byte)(109)))), ((int)(((byte)(109)))));
            this.txttempo.WaterMarkFont = new System.Drawing.Font("Segoe UI", 10.8F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            // 
            // txtespaco
            // 
            // 
            // 
            // 
            this.txtespaco.CustomButton.Image = null;
            this.txtespaco.CustomButton.Location = new System.Drawing.Point(262, 1);
            this.txtespaco.CustomButton.Name = "";
            this.txtespaco.CustomButton.Size = new System.Drawing.Size(43, 43);
            this.txtespaco.CustomButton.Style = MetroFramework.MetroColorStyle.Blue;
            this.txtespaco.CustomButton.TabIndex = 1;
            this.txtespaco.CustomButton.Theme = MetroFramework.MetroThemeStyle.Light;
            this.txtespaco.CustomButton.UseSelectable = true;
            this.txtespaco.CustomButton.Visible = false;
            this.txtespaco.FontSize = MetroFramework.MetroTextBoxSize.Medium;
            this.txtespaco.Lines = new string[0];
            this.txtespaco.Location = new System.Drawing.Point(32, 38);
            this.txtespaco.MaxLength = 32767;
            this.txtespaco.Multiline = true;
            this.txtespaco.Name = "txtespaco";
            this.txtespaco.PasswordChar = '\0';
            this.txtespaco.PromptText = "Insira o espaço percorrido...";
            this.txtespaco.ScrollBars = System.Windows.Forms.ScrollBars.None;
            this.txtespaco.SelectedText = "";
            this.txtespaco.SelectionLength = 0;
            this.txtespaco.SelectionStart = 0;
            this.txtespaco.ShortcutsEnabled = true;
            this.txtespaco.Size = new System.Drawing.Size(306, 45);
            this.txtespaco.TabIndex = 2;
            this.txtespaco.Theme = MetroFramework.MetroThemeStyle.Dark;
            this.txtespaco.UseSelectable = true;
            this.txtespaco.WaterMark = "Insira o espaço percorrido...";
            this.txtespaco.WaterMarkColor = System.Drawing.Color.FromArgb(((int)(((byte)(109)))), ((int)(((byte)(109)))), ((int)(((byte)(109)))));
            this.txtespaco.WaterMarkFont = new System.Drawing.Font("Segoe UI", 10.8F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            // 
            // tabsoma
            // 
            this.tabsoma.BackColor = System.Drawing.Color.White;
            this.tabsoma.Controls.Add(this.iconButton1);
            this.tabsoma.Controls.Add(this.lblsoma);
            this.tabsoma.Controls.Add(this.btnsomatoria);
            this.tabsoma.Controls.Add(this.txtsoma);
            this.tabsoma.Location = new System.Drawing.Point(4, 38);
            this.tabsoma.Name = "tabsoma";
            this.tabsoma.Size = new System.Drawing.Size(975, 497);
            this.tabsoma.TabIndex = 0;
            this.tabsoma.Text = "Somatória";
            this.tabsoma.ToolTipText = "Calcular a somatória";
            // 
            // iconButton1
            // 
            this.iconButton1.BackColor = System.Drawing.Color.Teal;
            this.iconButton1.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
            this.iconButton1.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.iconButton1.ForeColor = System.Drawing.Color.White;
            this.iconButton1.IconChar = FontAwesome.Sharp.IconChar.Eraser;
            this.iconButton1.IconColor = System.Drawing.Color.White;
            this.iconButton1.IconSize = 32;
            this.iconButton1.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.iconButton1.Location = new System.Drawing.Point(32, 202);
            this.iconButton1.Name = "iconButton1";
            this.iconButton1.Rotation = 0D;
            this.iconButton1.Size = new System.Drawing.Size(212, 93);
            this.iconButton1.TabIndex = 7;
            this.iconButton1.Text = "Limpar";
            this.iconButton1.UseVisualStyleBackColor = false;
            this.iconButton1.Click += new System.EventHandler(this.iconButton1_Click);
            // 
            // lblsoma
            // 
            this.lblsoma.AutoSize = true;
            this.lblsoma.FontSize = MetroFramework.MetroLabelSize.Tall;
            this.lblsoma.FontWeight = MetroFramework.MetroLabelWeight.Bold;
            this.lblsoma.Location = new System.Drawing.Point(500, 58);
            this.lblsoma.Name = "lblsoma";
            this.lblsoma.Size = new System.Drawing.Size(122, 25);
            this.lblsoma.TabIndex = 6;
            this.lblsoma.Text = "Somatória =";
            this.lblsoma.WrapToLine = true;
            // 
            // btnsomatoria
            // 
            this.btnsomatoria.BackColor = System.Drawing.Color.Teal;
            this.btnsomatoria.Flip = FontAwesome.Sharp.FlipOrientation.Normal;
            this.btnsomatoria.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnsomatoria.ForeColor = System.Drawing.Color.White;
            this.btnsomatoria.IconChar = FontAwesome.Sharp.IconChar.InfoCircle;
            this.btnsomatoria.IconColor = System.Drawing.Color.White;
            this.btnsomatoria.IconSize = 32;
            this.btnsomatoria.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnsomatoria.Location = new System.Drawing.Point(32, 100);
            this.btnsomatoria.Name = "btnsomatoria";
            this.btnsomatoria.Rotation = 0D;
            this.btnsomatoria.Size = new System.Drawing.Size(212, 93);
            this.btnsomatoria.TabIndex = 5;
            this.btnsomatoria.Text = "Calcular";
            this.btnsomatoria.UseVisualStyleBackColor = false;
            this.btnsomatoria.Click += new System.EventHandler(this.btnsomatoria_Click);
            // 
            // txtsoma
            // 
            // 
            // 
            // 
            this.txtsoma.CustomButton.Image = null;
            this.txtsoma.CustomButton.Location = new System.Drawing.Point(262, 1);
            this.txtsoma.CustomButton.Name = "";
            this.txtsoma.CustomButton.Size = new System.Drawing.Size(43, 43);
            this.txtsoma.CustomButton.Style = MetroFramework.MetroColorStyle.Blue;
            this.txtsoma.CustomButton.TabIndex = 1;
            this.txtsoma.CustomButton.Theme = MetroFramework.MetroThemeStyle.Light;
            this.txtsoma.CustomButton.UseSelectable = true;
            this.txtsoma.CustomButton.Visible = false;
            this.txtsoma.FontSize = MetroFramework.MetroTextBoxSize.Medium;
            this.txtsoma.ForeColor = System.Drawing.Color.White;
            this.txtsoma.Lines = new string[0];
            this.txtsoma.Location = new System.Drawing.Point(32, 38);
            this.txtsoma.MaxLength = 32767;
            this.txtsoma.Multiline = true;
            this.txtsoma.Name = "txtsoma";
            this.txtsoma.PasswordChar = '\0';
            this.txtsoma.PromptText = "Insira um número...";
            this.txtsoma.ScrollBars = System.Windows.Forms.ScrollBars.None;
            this.txtsoma.SelectedText = "";
            this.txtsoma.SelectionLength = 0;
            this.txtsoma.SelectionStart = 0;
            this.txtsoma.ShortcutsEnabled = true;
            this.txtsoma.Size = new System.Drawing.Size(306, 45);
            this.txtsoma.TabIndex = 3;
            this.txtsoma.Theme = MetroFramework.MetroThemeStyle.Dark;
            this.txtsoma.UseSelectable = true;
            this.txtsoma.WaterMark = "Insira um número...";
            this.txtsoma.WaterMarkColor = System.Drawing.Color.FromArgb(((int)(((byte)(109)))), ((int)(((byte)(109)))), ((int)(((byte)(109)))));
            this.txtsoma.WaterMarkFont = new System.Drawing.Font("Segoe UI", 10.8F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
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
            this.btnHOME.Location = new System.Drawing.Point(967, 91);
            this.btnHOME.Name = "btnHOME";
            this.btnHOME.Rotation = 0D;
            this.btnHOME.Size = new System.Drawing.Size(76, 53);
            this.btnHOME.TabIndex = 16;
            this.btnHOME.UseVisualStyleBackColor = true;
            this.btnHOME.Click += new System.EventHandler(this.btnHOME_Click);
            // 
            // Iniciante
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1104, 737);
            this.Controls.Add(this.btnHOME);
            this.Controls.Add(this.MTBiniciante);
            this.Name = "Iniciante";
            this.Text = "Iniciante";
            this.Theme = MetroFramework.MetroThemeStyle.Dark;
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.btnHOME_Click);
            this.MTBiniciante.ResumeLayout(false);
            this.tabvm.ResumeLayout(false);
            this.tabvm.PerformLayout();
            this.tabsoma.ResumeLayout(false);
            this.tabsoma.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private MetroFramework.Controls.MetroTabControl MTBiniciante;
        private MetroFramework.Controls.MetroTabPage tabvm;
        private System.Windows.Forms.TabPage tabsoma;
        private MetroFramework.Controls.MetroTextBox txttempo;
        private MetroFramework.Controls.MetroTextBox txtespaco;
        private MetroFramework.Controls.MetroLabel lblresultado;
        private FontAwesome.Sharp.IconButton btncalcular;
        private FontAwesome.Sharp.IconButton btnlimpar;
        private MetroFramework.Controls.MetroTextBox txtsoma;
        private FontAwesome.Sharp.IconButton iconButton1;
        private MetroFramework.Controls.MetroLabel lblsoma;
        private FontAwesome.Sharp.IconButton btnsomatoria;
        private FontAwesome.Sharp.IconButton btnHOME;
    }
}