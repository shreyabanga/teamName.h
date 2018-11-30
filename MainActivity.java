package com.example.sarah.heartz;

import android.os.Bundle;
import android.widget.TextView;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;

import java.util.ArrayList;
import java.util.Collections;


public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    ImageView iv_deck, iv_card1, iv_card2, iv_card3, iv_card4, iv_card5, iv_card6;

    ArrayList<Integer> cards;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        iv_deck = (ImageView) findViewById(R.id.iv_deck);
        iv_card1 = (ImageView) findViewById(R.id.iv_card1);
        iv_card2 = (ImageView) findViewById(R.id.iv_card2);
        iv_card3 = (ImageView) findViewById(R.id.iv_card3);
        iv_card4 = (ImageView) findViewById(R.id.iv_card4);
        iv_card5 = (ImageView) findViewById(R.id.iv_card5);
        iv_card6 = (ImageView) findViewById(R.id.iv_card6);

        iv_card1.setVisibility(View.INVISIBLE);
        iv_card2.setVisibility(View.INVISIBLE);
        iv_card3.setVisibility(View.INVISIBLE);
        iv_card4.setVisibility(View.INVISIBLE);
        iv_card5.setVisibility(View.INVISIBLE);
        iv_card6.setVisibility(View.INVISIBLE);

        cards = new ArrayList<>();
        cards.add(102);  //2 of clubs
        cards.add(103); //3 of clubs
        cards.add(104); //4 of clubs
        cards.add(105); //5 of clubs
        cards.add(106); //6 of clubs
        cards.add(107); //7 of clubs
        cards.add(108); //8 of clubs
        cards.add(109); //9 of clubs
        cards.add(110); //10 of clubs
        cards.add(111); //J of clubs
        cards.add(112); //Q of clubs
        cards.add(113); //K of clubs
        cards.add(114); //A of clubs

        cards.add(202); //2 of diamonds
        cards.add(203); //3 of diamonds
        cards.add(204); //4 of diamonds
        cards.add(205);//5 of diamonds
        cards.add(206); //6 of diamonds
        cards.add(207); //7 of diamonds
        cards.add(208); //8 of diamonds
        cards.add(209); //9 of diamonds
        cards.add(210); //10 of diamonds
        cards.add(211); //J of diamonds
        cards.add(212); //Q of diamonds
        cards.add(213); //K of diamonds
        cards.add(214); //A of diamonds

        cards.add(302); //2 of hearts
        cards.add(303); //3 of hearts
        cards.add(304); //4 of hearts
        cards.add(305); //5 of hearts
        cards.add(306); //6 of hearts
        cards.add(307); //7 of hearts
        cards.add(308); //8 of hearts
        cards.add(309); //9 of hearts
        cards.add(310); //10 of hearts
        cards.add(311); //J of hearts
        cards.add(312); //Q of hearts
        cards.add(313); //K of hearts
        cards.add(314); //A of hearts

        cards.add(402); //2 of spades
        cards.add(403); //3 of spades
        cards.add(404); //4 of spades
        cards.add(405); //5 of spades
        cards.add(406); //6 of spades
        cards.add(407); //7 of spades
        cards.add(408); //8 of spades
        cards.add(409); //9 of spades
        cards.add(410); //10 of spades
        cards.add(411); //J of spades
        cards.add(412); //Q of spades
        cards.add(413); //K of spades
        cards.add(414); //A of spades

        iv_deck.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(view view)
            {
                //shuffle the cards
                Collections.shuffle(cards);;

                //deal the first 6 cards
                assignImages(cards.get(0), iv_card1);
                assignImages(cards.get(0), iv_card2);
                assignImages(cards.get(0), iv_card3);
                assignImages(cards.get(0), iv_card4);
                assignImages(cards.get(0), iv_card5);
                assignImages(cards.get(0), iv_card6);

                iv_card1.setVisibility(view.VISIBLE);
                iv_card2.setVisibility(view.VISIBLE);
                iv_card3.setVisibility(view.VISIBLE);
                iv_card4.setVisibility(view.VISIBLE);
                iv_card5.setVisibility(view.VISIBLE);
                iv_card6.setVisibility(view.VISIBLE);

            }
        });
    }

    public void assignImages(int card, ImageView image)
    {
        switch (card)
        {
            case 102:
                image.setImageResource(R.drawable.clubs_2);
                break;
            case 103:
                image.setImageResource(R.drawable.clubs_3);
                break;
            case 104:
                image.setImageResource(R.drawable.clubs_4);
                break;
            case 105:
                image.setImageResource(R.drawable.clubs_5);
                break;
            case 106:
                image.setImageResource(R.drawable.clubs_6);
                break;
            case 107:
                image.setImageResource(R.drawable.clubs_7);
                break;
            case 108:
                image.setImageResource(R.drawable.clubs_8);
                break;
            case 109:
                image.setImageResource(R.drawable.clubs_9);
                break;
            case 110:
                image.setImageResource(R.drawable.clubs_10);
                break;
            case 111:
                image.setImageResource(R.drawable.jack_of_clubs);
                break;
            case 112:
                image.setImageResource(R.drawable.queen_of_clubs);
                break;
            case 113:
                image.setImageResource(R.drawable.king_of_clubs);
                break;
            case 114:
                image.setImageResource(R.drawable.ace_of_clubs);
                break;

            case 202:
                image.setImageResource(R.drawable.diamonds_2);
                break;
            case 203:
                image.setImageResource(R.drawable.diamonds_3);
                break;
            case 204:
                image.setImageResource(R.drawable.diamonds_4);
                break;
            case 205:
                image.setImageResource(R.drawable.diamonds_5);
                break;
            case 206:
                image.setImageResource(R.drawable.diamonds_6);
                break;
            case 207:
                image.setImageResource(R.drawable.diamonds_7);
                break;
            case 208:
                image.setImageResource(R.drawable.diamonds_8);
                break;
            case 209:
                image.setImageResource(R.drawable.diamonds_9);
                break;
            case 210:
                image.setImageResource(R.drawable.diamonds_10);
                break;
            case 211:
                image.setImageResource(R.drawable.jack_of_diamonds);
                break;
            case 212:
                image.setImageResource(R.drawable.queen_of_diamonds);
                break;
            case 213:
                image.setImageResource(R.drawable.king_of_diamonds);
                break;
            case 214:
                image.setImageResource(R.drawable.ace_of_diamonds);
                break;

            case 302:
                image.setImageResource(R.drawable.hearts_2);
                break;
            case 303:
                image.setImageResource(R.drawable.hearts_3);
                break;
            case 304:
                image.setImageResource(R.drawable.hearts_4);
                break;
            case 305:
                image.setImageResource(R.drawable.hearts_5);
                break;
            case 306:
                image.setImageResource(R.drawable.hearts_6);
                break;
            case 307:
                image.setImageResource(R.drawable.hearts_7);
                break;
            case 308:
                image.setImageResource(R.drawable.hearts_8);
                break;
            case 309:
                image.setImageResource(R.drawable.hearts_9);
                break;
            case 310:
                image.setImageResource(R.drawable.hearts_10);
                break;
            case 311:
                image.setImageResource(R.drawable.jack_of_hearts);
                break;
            case 312:
                image.setImageResource(R.drawable.queen_of_hearts);
                break;
            case 313:
                image.setImageResource(R.drawable.king_of_hearts);
                break;
            case 314:
                image.setImageResource(R.drawable.ace_of_hearts);
                break;

            case 402:
                image.setImageResource(R.drawable.spades_2);
                break;
            case 403:
                image.setImageResource(R.drawable.spades_3);
                break;
            case 404:
                image.setImageResource(R.drawable.spades_4);
                break;
            case 405:
                image.setImageResource(R.drawable.spades_5);
                break;
            case 406:
                image.setImageResource(R.drawable.spades_6);
                break;
            case 407:
                image.setImageResource(R.drawable.spades_7);
                break;
            case 408:
                image.setImageResource(R.drawable.spades_8);
                break;
            case 409:
                image.setImageResource(R.drawable.spades_9);
                break;
            case 410:
                image.setImageResource(R.drawable.spades_10);
                break;
            case 411:
                image.setImageResource(R.drawable.jack_of_spades);
                break;
            case 412:
                image.setImageResource(R.drawable.queen_of_spades);
                break;
            case 413:
                image.setImageResource(R.drawable.king_of_spades);
                break;
            case 414:
                image.setImageResource(R.drawable.ace_of_spades);
                break;
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        Intent resultActivity = new Intent(MainActivity.this, Result.class);

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();
            }
        });

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
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

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}
