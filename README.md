# teamName.h

# Running the App
Heartz is an on-the-go app version of the card game Hearts. To run this app, you must extract the folder entitled HeartzWithCards from teamname.h_Source.zip. Then, in Android Studio, open an existing project and select the HeartzWithCards folder. All necessary files will be made available. To run the app in the emulator, click the run button. When asked to select depolyment target, you must select a device with API 28. A lower API level will not allow the app to work properly. For an optimal GUI experience, select the Nexus S API 28, though any device with the necessary API level will work.

# Using the App
The title page will be the first to appear. You can select the "RULES" button to be taken to a page where you can read the rules of hearts. From this page, press the back button to return to the title page. Pressing start will take you to a screen where you can input the names of the players. You may type in anything here. You can also continue without entering names, but this will make playing the game difficult as the players' names serve as a label to identify when it's a player's turn. Once you have entered names, press done. This takes you to a screen asking for the final score. This is the final score to which the game will played. Once a player passes this score, the game will end. You must enter a number here. If you enter a negative number or zero, you will be told to enter a positive number. Press done to begin the game. 

A screen will appear telling you the name of the player that will start the game. This is to allow players a chance to pass the phone to the appropriate player. Tap anywhere on this screen to continue. Next, you will see the first player's cards. Tapping a card will play it. If it is an invalid play, meaning the play is not allowed by the rules of hearts, a snackbar will appear at the bottom of the screen telling you as much. Once a valid card is played, the screen will move back to the passing screen, this time with the name of the next player. Tapping the screen anywhere, once again, takes you to the player's screen. The card just played by the first player will now be displayed at the top of the screen. Play will continue in this pattern. When a trick is over, the player who played the card with the highest value in the same suit as the first card played in the trick obtains the cards and starts the next trick. When players run out of cards, points are tallied. If the final score is reached, the game will end and you will see the game over screen, which displays the winner and the scores. If the score hasn't been reached, players receive new cards and the game continues.

From any players' screen, you may press the "SCORES" button in the top right corner to see the current scores. Be aware, points are not tallied until the end of the round, so there will be no points displayed until players play all their cards and a new hand is received.

After a game is over, if you choose to play again, you may press the "PLAY AGAIN" button. This will take you back to the inital title  screen.

# Additional Test Cases
According to the rules of hearts, there are many plays that constitute an invalid play. The following are all error-checked in the app. If you try to play a card that's invalid, a snackbar will appear at the bottom screen informing you that you may not play the card.

Invalid Plays:
1. Playing any card except the 2 of Spades when starting the first trick of a round/hand
2. Playing a Hearts card in the first trick
3. Starting a trick with a Hearts card before Hearts have been broken (i.e. before a hearts card or the Queen of Spades has been played)
4. Playing a card of a different suit from the lead card of a trick when you are able to play the same suit

