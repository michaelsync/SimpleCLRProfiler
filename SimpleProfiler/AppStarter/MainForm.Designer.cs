namespace AppStarter
{
    partial class MainForm
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
            this.pickAppButton = new System.Windows.Forms.Button();
            this.appPathTextBox = new System.Windows.Forms.TextBox();
            this.startButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // pickAppButton
            // 
            this.pickAppButton.Location = new System.Drawing.Point(392, 30);
            this.pickAppButton.Name = "pickAppButton";
            this.pickAppButton.Size = new System.Drawing.Size(56, 23);
            this.pickAppButton.TabIndex = 0;
            this.pickAppButton.Text = "...";
            this.pickAppButton.UseVisualStyleBackColor = true;
            this.pickAppButton.Click += new System.EventHandler(this.pickAppButton_Click);
            // 
            // appPathTextBox
            // 
            this.appPathTextBox.Location = new System.Drawing.Point(13, 33);
            this.appPathTextBox.Name = "appPathTextBox";
            this.appPathTextBox.Size = new System.Drawing.Size(359, 20);
            this.appPathTextBox.TabIndex = 1;
            // 
            // startButton
            // 
            this.startButton.Location = new System.Drawing.Point(212, 78);
            this.startButton.Name = "startButton";
            this.startButton.Size = new System.Drawing.Size(75, 23);
            this.startButton.TabIndex = 2;
            this.startButton.Text = "Start";
            this.startButton.UseVisualStyleBackColor = true;
            this.startButton.Click += new System.EventHandler(this.startButton_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(479, 127);
            this.Controls.Add(this.startButton);
            this.Controls.Add(this.appPathTextBox);
            this.Controls.Add(this.pickAppButton);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button pickAppButton;
        private System.Windows.Forms.TextBox appPathTextBox;
        private System.Windows.Forms.Button startButton;
    }
}

