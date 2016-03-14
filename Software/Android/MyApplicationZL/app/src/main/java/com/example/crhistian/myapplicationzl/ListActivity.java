package com.example.crhistian.myapplicationzl;

import android.app.ProgressDialog;
import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.ListView;
import android.widget.Toast;

import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;

/**
 * Created by crhistian on 31/01/2016.
 */
public class ListActivity extends AppCompatActivity {

    ArrayList<ListModel> arrayOfListModels = new ArrayList<ListModel>();
    protected  void  onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_list);
        Log.d("MyApp", "Entre a las listas");

        // Construct the data source

        // Create the adapter to convert the array to views
        CustomAdapter adapter = new CustomAdapter(this, arrayOfListModels);
        // Attach the adapter to a ListView
        ListView listView = (ListView) findViewById(R.id.listView);
        listView.setAdapter(adapter);


        //agregando elementos
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss 'GTM' Z");
        String currentDateandTime = sdf.format(new Date());
        arrayOfListModels.add(new ListModel(currentDateandTime, 1235 ));
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.listmenu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case R.id.action_selectAll:
                Toast.makeText(getApplicationContext(), "Seleccionar todo", Toast.LENGTH_SHORT).show();
                return true;

            case R.id.action_deselectAll:
                Toast.makeText(getApplicationContext(), "Deseleccionar todo", Toast.LENGTH_SHORT).show();
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }

    public void onClickSync(View w)
    {
        Toast.makeText(getApplicationContext(), "Sincronizar", Toast.LENGTH_SHORT).show();

        Log.d("MyApp", "Entre");
        try {
            JSONObject jsonUser = new JSONObject();
            jsonUser.put("dateMeasure", ((ListModel)arrayOfListModels.get(0)).getFecha());
            jsonUser.put("measure", String.valueOf(((ListModel) arrayOfListModels.get(0)).getConcentracion()));
            String message = jsonUser.toString();
            Log.d("MyApp", "Enviar");
            Log.d("MyApp", message);
            uploadToServer(message);

        } catch (Throwable t) {
            Toast.makeText(getApplicationContext(), "Request failed: " + t.toString(), Toast.LENGTH_LONG).show();
            Log.d("MyApp", "error");
            Log.d("MyApp", t.toString());
        }
    }

    public void onClickDelete(View w)
    {
        Toast.makeText(getApplicationContext(), "Borrar", Toast.LENGTH_SHORT).show();
    }

    private JSONObject uploadToServer(String jsonSend) throws IOException, JSONException {
        class SendJSON extends AsyncTask<String, Void, String> {
            ProgressDialog loading;

            @Override
            protected void onPreExecute() {
                super.onPreExecute();
                loading = ProgressDialog.show(ListActivity.this, "Cargando...",null,true,true);
            }

            @Override
            protected String doInBackground(String... params) {
                String json = params[0];
                BufferedReader bufferedReader = null;

                try {
                    String query = "http://192.168.1.5/ws_hg/service_write.php";

                    Log.d("MyApp", "url");
                    Log.d("MyApp", query);

                    URL url = new URL(query);
                    Log.d("MyApp", "abrir Conexion");
                    HttpURLConnection conn = (HttpURLConnection) url.openConnection();
                    conn.setConnectTimeout(15000);
                    conn.setRequestProperty("Content-Type", "application/json; charset=UTF-8");
                    conn.setDoOutput(true);
                    conn.setDoInput(true);
                    conn.setRequestMethod("POST");

                    Log.d("MyApp", "enviando datos");
                    OutputStream os = conn.getOutputStream();
                    os.write(json.getBytes("UTF-8"));
                    os.close();
                    Log.d("MyApp", "termine de enviar datos");

                    // read the response
                    Log.d("MyApp", "recibi respuesta");
                    bufferedReader = new BufferedReader(new InputStreamReader(conn.getInputStream()));
                    StringBuilder sb = new StringBuilder();

                    String result;
                    while((result = bufferedReader.readLine())!= null){
                        sb.append(result+"\n");
                    }

                    //InputStream in = new BufferedInputStream(conn.getInputStream());
                    // String result = in.toString();
                    Log.d("MyApp", "recibi esto RAWR");
                    Log.d("MyApp", result);
                    JSONObject jsonObject = new JSONObject(result);
                    Log.d("MyApp", "recibi esto");
                    Log.d("MyApp", jsonObject.toString());

                    bufferedReader.close();
                    conn.disconnect();
                }
                catch (Exception ex)
                {
                    Log.d("MyApp", "error send");
                    Log.d("MyApp", ex.toString());
                }
                return "asd";
            }

            @Override
            protected void onPostExecute(String s) {
                super.onPostExecute(s);
                loading.dismiss();
            }
        }
        Log.d("sendJson","Enviando");
        SendJSON sj = new SendJSON();
        sj.execute(jsonSend);
        Log.d("sendJson", "Enviado");
        return null;
    }

}
