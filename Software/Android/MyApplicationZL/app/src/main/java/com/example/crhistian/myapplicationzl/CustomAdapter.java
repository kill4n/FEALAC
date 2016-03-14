package com.example.crhistian.myapplicationzl;

import android.content.Context;
import android.content.DialogInterface;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.BaseAdapter;
import android.widget.TextView;

import java.util.ArrayList;

/**
 * Created by crhistian on 31/01/2016.
 */
public class CustomAdapter extends ArrayAdapter<ListModel> {

    public CustomAdapter(Context context, ArrayList<ListModel> modelo) {
            super(context, 0, modelo);
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        // Get the data item for this position
        ListModel modelo = getItem(position);
        // Check if an existing view is being reused, otherwise inflate the view
        if (convertView == null) {
            convertView = LayoutInflater.from(getContext()).inflate(R.layout.list_object, parent, false);
        }
        // Lookup view for data population
        TextView tvFecha = (TextView) convertView.findViewById(R.id.textView1);
        TextView tvConce = (TextView) convertView.findViewById(R.id.textView2);
        // Populate the data into the template view using the data object
        tvFecha.setText("Date: " + modelo.getFecha());
        tvConce.setText("Concentration: " + String.valueOf(modelo.getConcentracion()) + "ppb");
        // Return the completed view to render on screen
        return convertView;
    }
}