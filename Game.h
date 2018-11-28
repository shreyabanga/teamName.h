//
// Created by mckda on 11/23/2018.
//

#ifndef HEARTS_GAME_H
#define HEARTS_GAME_H

#include "Player.h"
#include "Card.h"
#include <string>
#include <vector>

class Game {
    private:
  	Player Player0;
        Player Player1;
	Player Player2;
	Player Player3;
        std::vector<Card> mainDeck;
	std::vector<Card> playedDeck;
	bool heartsBroken;
        int finalScore;
        int starter;
        int currentPlayer;
    public:
        Game(); //Constructor: creates players and creates a playedDeck vector full of filler cards
        void setNames(std::string &name1, std::string &name2, std::string &name3, std::string &name4);
                //Sets the players' names
        bool setFinalScore(int finalScore); //Sets the desired score cap (called finalScore). Returns false if 
					   //negative/zero (invalid) number. Returns true otherwise.
        void shuffleDeal(); //Creates, shuffles, and deals the main deck. Finds who has the 2 of
                            // clubs and sets them as the starter and current player
        bool cardPlayed(Card & inCard);  //Error checks to make sure valid card is played. Returns false 
					//if invalid card played. If played card is valid, removes the played
					//card from the current player's hand, adds the played card to the playedDeck,
					//changes the currentPlayer data field to the next player, and returns true
        bool isEndOfTrick() const; //Returns true if the trick is over, i.e. if there are 4 played cards
        void endOfTrick(); //Finds the highest card in the same suit as the initial card and
                            //adds the playedDeck to the pointsCards deck of the player that played
                            //it. This player becomes the new starter. Also clears the played deck.
        bool isEndOfRound() const; //Returns true if the players have no cards left in their hands,
                                //meaning the round is over
        void endOfRound(); //Adds scores for every player and if a player shoots the moon,
                            //26 points are added to their opponents
        bool isGameOver() const; //Returns true if a player has a score greater than the desired cap score
        int getStarter() const; //Returns the starter player
        int getCurrentPlayer() const; //Returns the player whose turn it is
        int * getScores() const; //Returns an array of the scores, with the indices matching the players' orders
        int getWinner() const; //Returns the winner
        std::vector<Card> getPlayerHand(int player) const; //Returns current hand of desired player
	std::vector<Card> getPlayedDeck() const; //Returns played cards in current trick
	
};


#endif //HEARTS_GAME_H
