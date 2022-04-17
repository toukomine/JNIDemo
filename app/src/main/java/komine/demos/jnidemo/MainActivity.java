package komine.demos.jnidemo;

import android.graphics.Point;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity{

    private String mName = "MainActivity";
    private Person mPerson;

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Point point = createPoint(39,39);
        Log.d(mName,"x = " + point.x + ",y = " + point.y);

        alert();
        Toast.makeText(getApplicationContext(),"name:" + getName(),Toast.LENGTH_SHORT).show();
    }

    public void alertMessage(String msg) {
        Toast.makeText(getApplicationContext(),msg,Toast.LENGTH_SHORT).show();
    }

    public native String getName();
    public native void alert();
    public native Point createPoint(int x,int y);

    public void showName(View view) {
        Toast.makeText(getApplicationContext(),mPerson.getName(),Toast.LENGTH_SHORT).show();
    }

    public void showAge(View view) {
        Toast.makeText(getApplicationContext(),mPerson.getAge() + "",Toast.LENGTH_SHORT).show();
    }
}
