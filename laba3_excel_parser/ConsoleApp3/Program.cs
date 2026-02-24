using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Office.Interop.Excel;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            Application excel = new Application();

            if (excel == null)
            {
                Console.WriteLine("failed to create excel object");
                return;
            }

            Workbook excelbook = excel.Workbooks.Open(@"C:\Users\24_ИП-191к\Desktop\d2.xlsx");
            _Worksheet excelsheet = excelbook.Sheets[1];
            Range excelrange = excelsheet.UsedRange;

            int rowcount = excelrange.Rows.Count;

            for (int i = 1; i < rowcount; i++) 
            {
                if (excelrange.Cells[i][1] != null && excelrange.Cells[i, 1].Value2 != null &&
                    excelrange.Cells[i][2] != null && excelrange.Cells[i, 2].Value2 != null)
                {
                    string line1 = excelrange.Cells[i, 1].Value2;
                    string line2 = excelrange.Cells[i, 2].Value2;

                    Console.WriteLine("{0} \t\t {1}", line1, line2); 
                }
            }
        }
    }
}
