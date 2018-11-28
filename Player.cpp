//
// Created by mckda on 11/19/2018.
//

#include "Player.h"
#include <string>
#include <vector>
#include <algorithm>

Player::Player() {
    //Constructor
	score = 0;
	name = "";
}

void Player::setName(std::string &name) {
    //Sets player's name
    this -> name = name;
}

std::string Player::getName() const {
    //Returns player's name
    return name;
}

void Player::addCard(Card &inCard) {
    //Adds card to player's hand
    hand.push_back(inCard);
}

void Player::removeCard(Card &inCard) {
    //Removes card from player's hand
    for (int i=0; i<hand.size(); i++) {
        if (inCard.getSuit() == hand[i].getSuit() && inCard.getValue() == hand[i].getValue())
            hand.erase(hand.begin()+i);
    }
}


bool Player::isStart() const {
    //Returns true if player has the 2 of Clubs, meaning they start the trick
    for (int i=0; i<hand.size(); i++) {
        if ((hand[i].getSuit() == 'C') && (hand[i].getValue() == '2'))
            return true;
    }
    return false;
}

int Player::addScore() {
    //Counts points in pointsCards and puts in score and clears pointsCard vector;
    // if player has all possible points cards, returns -1, returns 1 otherwise.
    //Also clears the pointsCards vector
    int heartCounter = 0;
    int totalScore = 0;
    bool queenSpades = false;

    //If a person has all 14 points cards, they shot the moon. The points cards vector is cleared
    //and -1 is returned
    if (pointsCards.size() == 14) {
        unsigned long pointsCardsSize = pointsCards.size();
        for (int i=0; i<pointsCardsSize;i++)
            pointsCards.erase(pointsCards.begin());
        return -1;
    }

    //A person that hasn't shot the moon, has their points added based on number of hearts
    //and if they have the Queen of Spades
    for (int i = 0; i < pointsCards.size(); i++) {
        if (pointsCards[i].getSuit() == 'H') 
            heartCounter++;
        if (pointsCards[i].getSuit() == 'S')
            queenSpades = true;
    }

    if (queenSpades)
        totalScore += 13;
    totalScore += heartCounter;
   
    score += totalScore;

    //Points cards vector cleared
    unsigned long pointsCardsSize = pointsCards.size();
    for (int i=0; i<pointsCardsSize;i++)
        pointsCards.erase(pointsCards.begin());

    return 1;
}

int Player::getScore() const {
    //Returns score
    return score;
}

void Player::addPointsCards(std::vector<Card> inCards) {
    //Adds the vector of inCards to pointsCards vector
    for (int i=0; i<inCards.size(); i++) {
        pointsCards.push_back(inCards[i]);
    }
}

void Player::add26() {
    //Adds 26 to score, used when a player shoots the moon
    score += 26;
}

std::vector<Card> Player::getHand() const {
    //Returns hand
    return hand;
}

bool Player::hasCard(Card & inCard) const {
     //Returns true if player has the card in their hand, false if they don't

    for (int i=0; i<hand.size(); i++) {
	if (inCard.getSuit() == hand[i].getSuit() && inCard.getValue() == hand[i].getValue())
		return true;
    }
    return false;
}

bool Player::hasSuit(char inSuit) const {
    //Returns true if player has at least one card in the inputted suit

    for (int i=0; i<hand.size(); i++) {
	if (hand[i].getSuit() == inSuit)
		return true;
    }
    return false;
}

void Player::sortCards() {
    //Sorts cards by suit and increasing value
    
    //Sorts by suit
    for (int i=0; i<hand.size()-1; i++) {
	for (int j=i+1; j<hand.size(); j++) {
		if (hand[i].getSuit() < hand[j].getSuit()) {
			Card temp(hand[i].getSuit(),hand[i].getValue());
			hand[i].setSuit(hand[j].getSuit());
			hand[i].setValue(hand[j].getValue());
			hand[j].setSuit(temp.getSuit());
			hand[j].setValue(temp.getValue());
		}
	}
    }

   //Sorts by value
   int counterS=0;
   int counterH=0;
   int counterD=0;
   int counterC=0;

   for (int i=0; i<hand.size();i++){
	if (hand[i].getSuit() == 'S')
		counterS++;
   }

   for (int i=0; i<hand.size();i++){
	if (hand[i].getSuit() == 'H')
		counterH++;
   }

   for (int i=0; i<hand.size();i++){
	if (hand[i].getSuit() == 'D')
		counterD++;
   }

   for (int i=0; i<hand.size();i++){
	if (hand[i].getSuit() == 'C')
		counterC++;
   }

   for (int i=0; i<counterS-1; i++) {
	for (int j=i+1; j<counterS; j++) {
		if (hand[i].getValue() == 'A' || (hand[i].getValue()>57 && hand[j].getValue()<=57) || (hand[i].getValue()<=57 && hand[j].getValue() <=57 && hand[i].getValue() > hand[j].getValue()) || (hand[j].getValue()!='A' && ((hand[i].getValue() =='J' && hand[j].getValue() == 'T')|| (hand[i].getValue() =='Q' && hand[j].getValue() != 'K') || hand[i].getValue()=='K'))) {
			Card temp(hand[i].getSuit(),hand[i].getValue());
			hand[i].setSuit(hand[j].getSuit());
			hand[i].setValue(hand[j].getValue());
			hand[j].setSuit(temp.getSuit());
			hand[j].setValue(temp.getValue());
		}
	}
   }

   for (int i=counterS; i<(counterS+counterH-1); i++) {
	for (int j=i+1; j<(counterS+counterH); j++) {
		if (hand[i].getValue() == 'A' || (hand[i].getValue()>57 && hand[j].getValue()<=57) || (hand[i].getValue()<=57 && hand[j].getValue() <=57 && hand[i].getValue() > hand[j].getValue()) || (hand[j].getValue()!='A' && ((hand[i].getValue() =='J' && hand[j].getValue() == 'T')|| (hand[i].getValue() =='Q' && hand[j].getValue() != 'K') || hand[i].getValue()=='K'))) {
			Card temp(hand[i].getSuit(),hand[i].getValue());
			hand[i].setSuit(hand[j].getSuit());
			hand[i].setValue(hand[j].getValue());
			hand[j].setSuit(temp.getSuit());
			hand[j].setValue(temp.getValue());
		}
	}
   }

   for (int i=counterS+counterH; i<(counterS+counterH+counterD-1); i++) {
	for (int j=i+1; j<(counterS+counterH+counterD); j++) {
		if (hand[i].getValue() == 'A' || (hand[i].getValue()>57 && hand[j].getValue()<=57) || (hand[i].getValue()<=57 && hand[j].getValue() <=57 && hand[i].getValue() > hand[j].getValue()) || (hand[j].getValue()!='A' && ((hand[i].getValue() =='J' && hand[j].getValue() == 'T')|| (hand[i].getValue() =='Q' && hand[j].getValue() != 'K') || hand[i].getValue()=='K'))) {
			Card temp(hand[i].getSuit(),hand[i].getValue());
			hand[i].setSuit(hand[j].getSuit());
			hand[i].setValue(hand[j].getValue());
			hand[j].setSuit(temp.getSuit());
			hand[j].setValue(temp.getValue());
		}
	}
   }

   for (int i=counterS+counterH+counterD; i<(counterS+counterH+counterD+counterC-1); i++) {
	for (int j=i+1; j<(counterS+counterH+counterD+counterC); j++) {
		if (hand[i].getValue() == 'A' || (hand[i].getValue()>57 && hand[j].getValue()<=57) || (hand[i].getValue()<=57 && hand[j].getValue() <=57 && hand[i].getValue() > hand[j].getValue()) || (hand[j].getValue()!='A' && ((hand[i].getValue() =='J' && hand[j].getValue() == 'T')|| (hand[i].getValue() =='Q' && hand[j].getValue() != 'K') || hand[i].getValue()=='K'))) {
			Card temp(hand[i].getSuit(),hand[i].getValue());
			hand[i].setSuit(hand[j].getSuit());
			hand[i].setValue(hand[j].getValue());
			hand[j].setSuit(temp.getSuit());
			hand[j].setValue(temp.getValue());
		}
	}
   }

				
}

	


