using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;
using System.Threading;

namespace winformProcessSceheduling
{
    class XMLControl
    {
        XElement resultXml = null;
        Thread thread = null;

        public void SaveProcessXml(DataGridView dgInputData, DataTable dt, string filePath, string algo, string time_quntum, List<int> coreType)
        {
            //XElement processXml = new XElement("processes",
            //    new XElement("algorithm", algo),
            //    new XElement("timeQuntum", time_quntum),
            //    from DataGridViewRow row in dgInputData.Rows
            //    where !row.IsNewRow
            //    select new XElement("process",
            //    new XElement("Name", row.Cells["Name"].Value),
            //    new XElement("ArriveTime", row.Cells["Arrive Time"].Value.ToString()),
            //    new XElement("BurstTime", row.Cells["Burst Time"].Value.ToString())
            //    )
            //);
            XElement processXml = new XElement("processes",
                new XElement("algorithm", algo),
                new XElement("timeQuntum", time_quntum),
                new XElement("coreTypes", 
                from int core_type in coreType
                select new XElement("coreType", core_type.ToString())
                ),
                from DataRow row in dt.Rows
                select new XElement("process",
                new XElement("Name", row["Name"].ToString()),
                new XElement("ArriveTime", row["Arrive Time"].ToString()),
                new XElement("BurstTime", row["Burst Time"].ToString())
                )
            );
            

            processXml.Save(filePath);
        }

        public void readCoreXml(DataGridView dgOutputData, DataTable dtOut, string outFilePath)
        {
            resultXml = XElement.Load(outFilePath);

            thread = new Thread(() =>
            {
                foreach (XElement time in resultXml.Elements("Time"))
                {
                    //time.Attribute("Value");
                    //DataGridViewRow row = new DataGridViewRow();
                    //row.CreateCells(dgOutputData);
                    DataRow row = dtOut.NewRow();

                    int i = 0;
                    foreach (XElement core in time.Elements("Core"))
                    {
                        if (i < dtOut.Columns.Count)
                        {
                            XElement name = core.Element("Name");
                            row[i] = name.Value;
                            i++;
                        }
                    }
                    

                    //화면갱신 스레드
                    if (dgOutputData.InvokeRequired)
                    {
                        dgOutputData.Invoke(new Action(() =>
                        {
                            //dtOut이 바인딩 되어있기 때문에 이것도 UI취급 invoke로 넣어야함!
                            
                            dtOut.Rows.Add(row);
                            dgOutputData.DataSource = dtOut;
                            // 각 행 헤더에 추가 인덱스번호 (초) 추가
                            foreach (DataGridViewRow oRow in dgOutputData.Rows)
                            {
                                oRow.HeaderCell.Value = (oRow.Index).ToString();
                            }
                            dgOutputData.AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode.AutoSizeToAllHeaders);

                            //dgOutputData.Refresh();
                            dgOutputData.Rows[dgOutputData.Rows.Count - 1].Selected = true;
                            if (dgOutputData.Rows.Count > 0)
                                dgOutputData.FirstDisplayedScrollingRowIndex = dgOutputData.Rows.Count - 1;
                        }));
                    }
                    Thread.Sleep(300);
                }
            });
            thread.IsBackground = true; // 스레드를 백그라운드로 설정
            thread.Start(); // 스레드 시작


        }

        public void abortThread()
        {
            if(thread != null && thread.IsAlive)
            {
                thread.Abort();
            }
        }
    }
}
