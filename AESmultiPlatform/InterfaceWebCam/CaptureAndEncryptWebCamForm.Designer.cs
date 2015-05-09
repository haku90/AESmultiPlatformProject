namespace InterfaceWebCam
{
    partial class uxKey
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
            this.userControl11 = new WebCamCapture.UserControl1();
            this.btnStart = new System.Windows.Forms.Button();
            this.btnStop = new System.Windows.Forms.Button();
            this.uxKeyEncrypt = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.uxKeyForDecrypt = new System.Windows.Forms.TextBox();
            this.userControl12 = new WebCamCapture.UserControl1();
            this.SuspendLayout();
            // 
            // userControl11
            // 
            this.userControl11.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.userControl11.Key = null;
            this.userControl11.KeyForDecrypt = null;
            this.userControl11.Location = new System.Drawing.Point(12, 12);
            this.userControl11.Name = "userControl11";
            this.userControl11.Size = new System.Drawing.Size(260, 179);
            this.userControl11.TabIndex = 0;
            // 
            // btnStart
            // 
            this.btnStart.Location = new System.Drawing.Point(32, 222);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(75, 38);
            this.btnStart.TabIndex = 1;
            this.btnStart.Text = "Start";
            this.btnStart.UseVisualStyleBackColor = true;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // btnStop
            // 
            this.btnStop.Location = new System.Drawing.Point(161, 222);
            this.btnStop.Name = "btnStop";
            this.btnStop.Size = new System.Drawing.Size(75, 38);
            this.btnStop.TabIndex = 2;
            this.btnStop.Text = "Koniec";
            this.btnStop.UseVisualStyleBackColor = true;
            this.btnStop.Click += new System.EventHandler(this.btnStop_Click);
            // 
            // uxKeyEncrypt
            // 
            this.uxKeyEncrypt.Location = new System.Drawing.Point(392, 205);
            this.uxKeyEncrypt.Name = "uxKeyEncrypt";
            this.uxKeyEncrypt.Size = new System.Drawing.Size(232, 20);
            this.uxKeyEncrypt.TabIndex = 3;
            this.uxKeyEncrypt.Text = "0123456789abcdef";
            this.uxKeyEncrypt.TextChanged += new System.EventHandler(this.uxKeyEncrypt_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(350, 208);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(36, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "Klucz:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(268, 240);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(121, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "Klucz do odszyfrowania:";
            // 
            // uxKeyForDecrypt
            // 
            this.uxKeyForDecrypt.Location = new System.Drawing.Point(392, 240);
            this.uxKeyForDecrypt.Name = "uxKeyForDecrypt";
            this.uxKeyForDecrypt.Size = new System.Drawing.Size(232, 20);
            this.uxKeyForDecrypt.TabIndex = 6;
            this.uxKeyForDecrypt.Text = "0123456789abcdef";
            this.uxKeyForDecrypt.TextChanged += new System.EventHandler(this.uxKeyForDecrypt_TextChanged);
            // 
            // userControl12
            // 
            this.userControl12.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.userControl12.Key = null;
            this.userControl12.KeyForDecrypt = null;
            this.userControl12.Location = new System.Drawing.Point(364, 12);
            this.userControl12.Name = "userControl12";
            this.userControl12.Size = new System.Drawing.Size(260, 179);
            this.userControl12.TabIndex = 7;
            // 
            // uxKey
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(674, 296);
            this.Controls.Add(this.userControl12);
            this.Controls.Add(this.uxKeyForDecrypt);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.uxKeyEncrypt);
            this.Controls.Add(this.btnStop);
            this.Controls.Add(this.btnStart);
            this.Controls.Add(this.userControl11);
            this.Name = "uxKey";
            this.Text = "Szyfrowanie Obrazu z Kamery";
            this.Load += new System.EventHandler(this.uxKey_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private WebCamCapture.UserControl1 userControl11;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Button btnStop;
        private System.Windows.Forms.TextBox uxKeyEncrypt;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox uxKeyForDecrypt;
        private WebCamCapture.UserControl1 userControl12;
    }
}

