using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace FEALAC_PC
{
    public partial class Form1 : Form
    {
        public List<ListModel> list = new List<ListModel>();
        Random r = new Random(DateTime.Now.Millisecond);
        public Form1()
        {
            InitializeComponent();
            list.Add(new ListModel { Fecha = DateTime.Now, Concentracion = 0.001, id = 1 });
            dataGridView1.DataSource = list;
        }

        private void button1_Click(object sender, EventArgs e)
        {

            list.Add(new ListModel { Fecha = DateTime.Now, Concentracion = (r.Next(1000) / 1000.0), id = list.Count + 1 });
            dataGridView1.DataSource = null;
            dataGridView1.DataSource = list;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < 5; i++)
                list.Add(new ListModel { Fecha = DateTime.Now, Concentracion = (r.Next(1000) / 1000.0), id = list.Count + 1 });
            dataGridView1.DataSource = null;
            dataGridView1.DataSource = list;
        }
    }
}
