package com.example.crhistian.myapplicationzl;

/**
 * Created by crhistian on 31/01/2016.
 */
public class ListModel {
    private  String Fecha="20-ene-15";
    private  double Concentracion=0.001;

    public ListModel(String date, double conc) {
        this.Fecha = date;
        this.Concentracion = conc;
    }
    //set metodos
    public void setFecha(String fecha) {
        this.Fecha=fecha;
    }
    public void setConcentracion(double concentracion) {
        this.Concentracion = concentracion;
    }

    //get metodos
    public String getFecha() {
        return Fecha;
    }
    public double getConcentracion() {
        return Concentracion;
    }
}
