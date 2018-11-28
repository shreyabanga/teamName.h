//
// Created by mckda on 11/19/2018.
//

#ifndef HEARTS_PLAYER_H
#define HEARTS_PLAYER_H

#include <string>
#include <vector>
#include "Card.h"

class Player {
    private:
        std::string name; //Name of player
        int score;  //Player's score 
	std::vector<Card> pointsCards; //Cards worth points a player obtains during a round
	std::vector<Card> hand; //Cards in a player's hand for a round
    public:
	Player();
        void setName(std::string & name); //Sets player's name
        std::string getName() const; //Returns player's name
        void addCard(Card & inCard); //Adds card to player's hand
        void removeCard(Card & inCard); //Removes card from player's hand
        bool isStart() const; //Returns true if player has the 2 of Clubs, meaning they start the trick
        int addScore(); //Counts points in pointsCards and puts in score and clears pointsCard vector;
                        // if player has all possible points cards, returns -1, returns 1 otherwise
                        //Also clears the pointsCards vector
        int getScore() const; //Returns score
        void addPointsCards (std::vector<Card> inCards); //Adds the vector of inCards to pointsCards vector
        void add26(); //Adds 26 to score, used when a player shoots the moon
        std::vector<Card> getHand() const; //Returns hand
	bool hasCard(Card & inCard) const; //Returns true if player has the card in their hand, false if they don't
	bool hasSuit(char inSuit) const;  //Returns true if player has at least one card in the inputted suit
	void sortCards(); //Sorts cards in hand by suit and increasing value
};



#endif //HEARTS_PLAYER_H
