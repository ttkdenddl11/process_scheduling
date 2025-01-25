
namespace winformProcessSceheduling
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.dgInputData = new System.Windows.Forms.DataGridView();
            this.tboxName = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.tboxAt = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.tboxBt = new System.Windows.Forms.TextBox();
            this.btnAdd = new System.Windows.Forms.Button();
            this.btnRun = new System.Windows.Forms.Button();
            this.rdoFCFS = new System.Windows.Forms.RadioButton();
            this.rdoRR = new System.Windows.Forms.RadioButton();
            this.tboxTimequntum = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.rdoPcore = new System.Windows.Forms.RadioButton();
            this.rdoEcore = new System.Windows.Forms.RadioButton();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.btnCoreAdd = new System.Windows.Forms.Button();
            this.dgOutputData = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.dgInputData)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgOutputData)).BeginInit();
            this.SuspendLayout();
            // 
            // dgInputData
            // 
            this.dgInputData.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgInputData.Location = new System.Drawing.Point(32, 12);
            this.dgInputData.Name = "dgInputData";
            this.dgInputData.RowTemplate.Height = 23;
            this.dgInputData.Size = new System.Drawing.Size(483, 447);
            this.dgInputData.TabIndex = 0;
            // 
            // tboxName
            // 
            this.tboxName.Location = new System.Drawing.Point(536, 44);
            this.tboxName.Name = "tboxName";
            this.tboxName.Size = new System.Drawing.Size(100, 21);
            this.tboxName.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(537, 24);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(81, 12);
            this.label1.TabIndex = 2;
            this.label1.Text = "프로세스 이름";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(537, 91);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(57, 12);
            this.label2.TabIndex = 4;
            this.label2.Text = "도착 시간";
            // 
            // tboxAt
            // 
            this.tboxAt.Location = new System.Drawing.Point(536, 111);
            this.tboxAt.Name = "tboxAt";
            this.tboxAt.Size = new System.Drawing.Size(100, 21);
            this.tboxAt.TabIndex = 3;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(537, 150);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(53, 12);
            this.label3.TabIndex = 6;
            this.label3.Text = "실행시간";
            // 
            // tboxBt
            // 
            this.tboxBt.Location = new System.Drawing.Point(536, 170);
            this.tboxBt.Name = "tboxBt";
            this.tboxBt.Size = new System.Drawing.Size(100, 21);
            this.tboxBt.TabIndex = 5;
            // 
            // btnAdd
            // 
            this.btnAdd.Location = new System.Drawing.Point(539, 206);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(97, 43);
            this.btnAdd.TabIndex = 7;
            this.btnAdd.Text = "프로세스 담기";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
            // 
            // btnRun
            // 
            this.btnRun.Location = new System.Drawing.Point(536, 416);
            this.btnRun.Name = "btnRun";
            this.btnRun.Size = new System.Drawing.Size(97, 43);
            this.btnRun.TabIndex = 8;
            this.btnRun.Text = "실행";
            this.btnRun.UseVisualStyleBackColor = true;
            this.btnRun.Click += new System.EventHandler(this.btnRun_Click);
            // 
            // rdoFCFS
            // 
            this.rdoFCFS.AutoSize = true;
            this.rdoFCFS.Checked = true;
            this.rdoFCFS.Location = new System.Drawing.Point(14, 20);
            this.rdoFCFS.Name = "rdoFCFS";
            this.rdoFCFS.Size = new System.Drawing.Size(54, 16);
            this.rdoFCFS.TabIndex = 9;
            this.rdoFCFS.TabStop = true;
            this.rdoFCFS.Text = "FCFS";
            this.rdoFCFS.UseVisualStyleBackColor = true;
            // 
            // rdoRR
            // 
            this.rdoRR.AutoSize = true;
            this.rdoRR.Location = new System.Drawing.Point(14, 55);
            this.rdoRR.Name = "rdoRR";
            this.rdoRR.Size = new System.Drawing.Size(91, 16);
            this.rdoRR.TabIndex = 10;
            this.rdoRR.TabStop = true;
            this.rdoRR.Text = "RoundRobin";
            this.rdoRR.UseVisualStyleBackColor = true;
            // 
            // tboxTimequntum
            // 
            this.tboxTimequntum.Location = new System.Drawing.Point(536, 376);
            this.tboxTimequntum.Name = "tboxTimequntum";
            this.tboxTimequntum.Size = new System.Drawing.Size(100, 21);
            this.tboxTimequntum.TabIndex = 11;
            this.tboxTimequntum.Text = "2";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(537, 356);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(87, 12);
            this.label4.TabIndex = 12;
            this.label4.Text = "Time quantum";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.rdoRR);
            this.groupBox1.Controls.Add(this.rdoFCFS);
            this.groupBox1.Location = new System.Drawing.Point(521, 266);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(120, 77);
            this.groupBox1.TabIndex = 13;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "알고리즘 선택";
            // 
            // rdoPcore
            // 
            this.rdoPcore.AutoSize = true;
            this.rdoPcore.Location = new System.Drawing.Point(14, 55);
            this.rdoPcore.Name = "rdoPcore";
            this.rdoPcore.Size = new System.Drawing.Size(71, 16);
            this.rdoPcore.TabIndex = 10;
            this.rdoPcore.TabStop = true;
            this.rdoPcore.Text = "P-CORE";
            this.rdoPcore.UseVisualStyleBackColor = true;
            // 
            // rdoEcore
            // 
            this.rdoEcore.AutoSize = true;
            this.rdoEcore.Checked = true;
            this.rdoEcore.Location = new System.Drawing.Point(14, 20);
            this.rdoEcore.Name = "rdoEcore";
            this.rdoEcore.Size = new System.Drawing.Size(71, 16);
            this.rdoEcore.TabIndex = 9;
            this.rdoEcore.TabStop = true;
            this.rdoEcore.Text = "E-CORE";
            this.rdoEcore.UseVisualStyleBackColor = true;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.rdoPcore);
            this.groupBox2.Controls.Add(this.rdoEcore);
            this.groupBox2.Location = new System.Drawing.Point(341, 465);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(159, 77);
            this.groupBox2.TabIndex = 14;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "코어 추가";
            // 
            // btnCoreAdd
            // 
            this.btnCoreAdd.Location = new System.Drawing.Point(506, 499);
            this.btnCoreAdd.Name = "btnCoreAdd";
            this.btnCoreAdd.Size = new System.Drawing.Size(97, 43);
            this.btnCoreAdd.TabIndex = 15;
            this.btnCoreAdd.Text = "코어 추가";
            this.btnCoreAdd.UseVisualStyleBackColor = true;
            this.btnCoreAdd.Click += new System.EventHandler(this.btnCoreAdd_Click);
            // 
            // dgOutputData
            // 
            this.dgOutputData.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgOutputData.Location = new System.Drawing.Point(647, 12);
            this.dgOutputData.Name = "dgOutputData";
            this.dgOutputData.RowTemplate.Height = 23;
            this.dgOutputData.Size = new System.Drawing.Size(483, 447);
            this.dgOutputData.TabIndex = 16;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1142, 551);
            this.Controls.Add(this.dgOutputData);
            this.Controls.Add(this.btnCoreAdd);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.tboxTimequntum);
            this.Controls.Add(this.btnRun);
            this.Controls.Add(this.btnAdd);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.tboxBt);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.tboxAt);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tboxName);
            this.Controls.Add(this.dgInputData);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            ((System.ComponentModel.ISupportInitialize)(this.dgInputData)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgOutputData)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dgInputData;
        private System.Windows.Forms.TextBox tboxName;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox tboxAt;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox tboxBt;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.Button btnRun;
        private System.Windows.Forms.RadioButton rdoFCFS;
        private System.Windows.Forms.RadioButton rdoRR;
        private System.Windows.Forms.TextBox tboxTimequntum;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton rdoPcore;
        private System.Windows.Forms.RadioButton rdoEcore;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button btnCoreAdd;
        private System.Windows.Forms.DataGridView dgOutputData;
    }
}

