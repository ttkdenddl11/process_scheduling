using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace winformProcessSceheduling
{
    public partial class Form1 : Form
    {
        const string sName = "Name";
        const string sAT = "Arrive Time";
        const string sBT = "Burst Time";

        DataTable dt = null;
        DataTable dtOut = null;

        int iCoreCount = 1;
        List<int> coreType = new List<int>();

        XMLControl xml = null;

        public Form1()
        {
            InitializeComponent();
            createDataTable();
        }

        public void createDataTable()
        {
            DataColumn colName = new DataColumn(sName, typeof(string));
            DataColumn colAT = new DataColumn(sAT, typeof(int));
            DataColumn colBT = new DataColumn(sBT, typeof(int));

            dt = new DataTable("InputProcess");
            dtOut = new DataTable("OutputProcess");
            dt.Columns.Add(colName);
            dt.Columns.Add(colAT);
            dt.Columns.Add(colBT);


        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            if(tboxName.Text != "" && tboxAt.Text != "" && tboxBt.Text != "")
            {
                DataRow row = dt.NewRow();
                row[sName] = tboxName.Text;
                row[sAT] = int.Parse(tboxAt.Text);
                row[sBT] = int.Parse(tboxBt.Text);
                dt.Rows.Add(row);
                dgInputData.DataSource = dt;
            }
            else
            {
                MessageBox.Show("제대로 입력해주세요.");
            }
        }

        
        private void btnCoreAdd_Click(object sender, EventArgs e)
        {
            string colName = string.Format("CORE{0}", iCoreCount);
            if (rdoEcore.Checked) {
                colName += " - E";
                DataColumn core = new DataColumn(colName, typeof(string));
                dtOut.Columns.Add(core);

                //1일시 E코어
                coreType.Add(1);
            }
            else
            {
                colName += " - P";
                DataColumn core = new DataColumn(colName, typeof(string));
                dtOut.Columns.Add(core);

                //0일시 P코어
                coreType.Add(0);
            }
            dgOutputData.DataSource = dtOut;

            iCoreCount++;
        }

        private void btnRun_Click(object sender, EventArgs e)
        {
            if(dt.Rows.Count == 0 || dtOut.Columns.Count == 0)
            {
                MessageBox.Show("프로세스 또는 코어를 제대로 입력해주세요.");
                return;
            }
            //프로세스 데이터들 xml에 저장
            string filePath = "processes.xml";
            xml = new XMLControl();
            xml.SaveProcessXml(dgInputData, dt, filePath, algoFind(), tboxTimequntum.Text, coreType);

            //cpp 파일 실행
            runCppProgram(filePath);

            string outFilePath = "C://Users/user/source/repos/test/winformProcessSceheduling/bin/Debug/output.xml";
            xml.readCoreXml(dgOutputData, dtOut, outFilePath);
            
        }

        private string algoFind()
        {
            string algo = "FCFS";

            if(rdoFCFS.Checked)
            {
                algo = "FCFS";
            } 
            else if(rdoRR.Checked)
            {
                algo = "RR";
            }

            return algo;
        }
        private void runCppProgram(string xmlFilePath)
        {
            //Arguments로 xml파일 넘겨주며 cpp파일 프로세스 실행
            Process process = new Process();
            process.StartInfo.FileName = "../../../Debug/test.exe";
            process.StartInfo.Arguments = xmlFilePath; // XML 파일 경로 전달
            process.StartInfo.UseShellExecute = false;
            process.StartInfo.RedirectStandardOutput = true;
            process.StartInfo.CreateNoWindow = true;

            process.Start();

            // C++ 프로그램 출력 읽기
            string output = process.StandardOutput.ReadToEnd();
            process.WaitForExit();
            //MessageBox.Show(output);
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if(xml != null)
                xml.abortThread();
        }
    }
}
