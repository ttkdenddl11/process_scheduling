using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
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

        private void btnRun_Click(object sender, EventArgs e)
        {
            //프로세스 데이터들 xml에 저장
            string filePath = "processes.xml";
            XMLControl xml = new XMLControl();
            xml.SaveProcessXml(dgInputData, filePath, algoFind(), tboxTimequntum.Text);
            
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
    }
}
