using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;

namespace winformProcessSceheduling
{
    class XMLControl
    {
        public void SaveProcessXml(DataGridView dgInputData, DataTable dt, string filePath, string algo, string time_quntum)
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
                from DataRow row in dt.Rows
                select new XElement("process",
                new XElement("Name", row["Name"].ToString()),
                new XElement("ArriveTime", row["Arrive Time"].ToString()),
                new XElement("BurstTime", row["Burst Time"].ToString())
                )
            );
            

            processXml.Save(filePath);
        }
    }
}
