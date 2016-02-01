package com.example.hamid.androidapp1;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RelativeLayout;

public class MainActivity extends AppCompatActivity {

    public enum OPERATOR_t {
        PLUS,
        MINUS,
        MULTIPLY,
        DIVIDE;

//        private final char value;
//
//        private OPERATOR_t(char c) {
//            value = c;
//        }
    }

    RelativeLayout mainLayout;
    EditText editTextMain;
    double currentArg1 = 0;
    double currentArg2 = 0;
    OPERATOR_t currentOperator;




    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();
            }
        });

        mainLayout = (RelativeLayout) findViewById(R.id.mainLayout);
        editTextMain = (EditText) findViewById(R.id.editTextMain);

    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    public void buttonClicked(View view)
    {
        String btnText = (String) ((Button) view).getText();

        switch(btnText)
        {
            case ".":
            case "0":
            case "1":
            case "2":
            case "3":
            case "4":
            case "5":
            case "6":
            case "7":
            case "8":
            case "9":
                editTextMain.append(btnText);
                break;

            case "+":
                currentOperator = OPERATOR_t.PLUS;
                break;
            case "-":
                currentOperator = OPERATOR_t.MINUS;
                break;
            case "*":
                currentOperator = OPERATOR_t.MULTIPLY;
                break;
            case "/":
                currentOperator = OPERATOR_t.DIVIDE;
                break;

            case "=":
                String textMain = editTextMain.getText().toString();
                currentArg2 =  Double.parseDouble(textMain);

                double result = currentArg1;
                switch(currentOperator)
                {
                    case PLUS:
                        result += currentArg2;
                        break;
                    case MINUS:
                        result -= currentArg2;
                        break;
                    case MULTIPLY:
                        result *= currentArg2;
                        break;
                    case DIVIDE:
                        result /= currentArg2;
                        break;
                }

                editTextMain.setText(String.valueOf(result));
                break;

        }


        switch(btnText)
        {
            case "+":
            case "-":
            case "*":
            case "/":
                String textMain = editTextMain.getText().toString();
                currentArg1 =  Double.parseDouble(textMain);
                editTextMain.setText("");
                break;
        }




        System.out.println("\ncurrentArg1 == " + currentArg1 + "\ncurrentArg2 == " + currentArg2 + "\ncurrentOperator == " + currentOperator);


    }
}
