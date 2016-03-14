using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace FEALAC_PC
{
    public class ListModel
    {
        private int _id;
        public int id
        {
            get { return _id; }
            set { _id = value; }
        }

        private DateTime _fecha = DateTime.Now;
        public DateTime Fecha
        {
            get { return _fecha; }
            set { _fecha = value; }
        }

        private double _concentracion;

        public double Concentracion
        {
            get { return _concentracion; }
            set { _concentracion = value; }
        }
        
    }
}
