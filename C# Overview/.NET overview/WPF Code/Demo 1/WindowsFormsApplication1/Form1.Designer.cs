namespace WindowsFormsApplication1
{
    partial class Form1
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
            this.txtMagshimim = new System.Windows.Forms.TextBox();
            this.btnCngTxt = new System.Windows.Forms.Button();
            this.picAce = new System.Windows.Forms.PictureBox();
            this.btnAddCards = new System.Windows.Forms.Button();
            this.btnOpenAnotherForm = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.picAce)).BeginInit();
            this.SuspendLayout();
            // 
            // txtMagshimim
            // 
            this.txtMagshimim.Location = new System.Drawing.Point(12, 12);
            this.txtMagshimim.Name = "txtMagshimim";
            this.txtMagshimim.Size = new System.Drawing.Size(141, 20);
            this.txtMagshimim.TabIndex = 0;
            this.txtMagshimim.Text = "Magshimim";
            // 
            // btnCngTxt
            // 
            this.btnCngTxt.Location = new System.Drawing.Point(12, 38);
            this.btnCngTxt.Name = "btnCngTxt";
            this.btnCngTxt.Size = new System.Drawing.Size(75, 23);
            this.btnCngTxt.TabIndex = 1;
            this.btnCngTxt.Text = "changeText";
            this.btnCngTxt.UseVisualStyleBackColor = true;
            this.btnCngTxt.Click += new System.EventHandler(this.btnCngTxt_Click);
            // 
            // picAce
            // 
            this.picAce.Image = global::WindowsFormsApplication1.Properties.Resources.ace_black;
            this.picAce.Location = new System.Drawing.Point(172, 12);
            this.picAce.Name = "picAce";
            this.picAce.Size = new System.Drawing.Size(100, 114);
            this.picAce.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.picAce.TabIndex = 2;
            this.picAce.TabStop = false;
            // 
            // btnAddCards
            // 
            this.btnAddCards.Location = new System.Drawing.Point(12, 103);
            this.btnAddCards.Name = "btnAddCards";
            this.btnAddCards.Size = new System.Drawing.Size(124, 23);
            this.btnAddCards.TabIndex = 3;
            this.btnAddCards.Text = "Add Cards in Runtime";
            this.btnAddCards.UseVisualStyleBackColor = true;
            this.btnAddCards.Click += new System.EventHandler(this.btnAddCards_Click);
            // 
            // btnOpenAnotherForm
            // 
            this.btnOpenAnotherForm.Location = new System.Drawing.Point(12, 67);
            this.btnOpenAnotherForm.Name = "btnOpenAnotherForm";
            this.btnOpenAnotherForm.Size = new System.Drawing.Size(109, 23);
            this.btnOpenAnotherForm.TabIndex = 4;
            this.btnOpenAnotherForm.Text = "Open New Form";
            this.btnOpenAnotherForm.UseVisualStyleBackColor = true;
            this.btnOpenAnotherForm.Click += new System.EventHandler(this.btnOpenAnotherForm_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 361);
            this.Controls.Add(this.btnOpenAnotherForm);
            this.Controls.Add(this.btnAddCards);
            this.Controls.Add(this.picAce);
            this.Controls.Add(this.btnCngTxt);
            this.Controls.Add(this.txtMagshimim);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.picAce)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtMagshimim;
        private System.Windows.Forms.Button btnCngTxt;
        private System.Windows.Forms.PictureBox picAce;
        private System.Windows.Forms.Button btnAddCards;
        private System.Windows.Forms.Button btnOpenAnotherForm;
    }
}

