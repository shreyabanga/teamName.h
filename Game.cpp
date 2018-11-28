//
// Created by mckda on 11/23/2018.
//

#include "Game.h"
#include "Card.h"
#include "Player.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>


Game::Game() {
    //Constructor: creates and sets order of players and creates a playedDeck vector full of
    //filler cards

    //Creates players
    Player Player0;
    Player Player1;
    Player Player2;
    Player Player3;


    //Creates a playedDeck vector of filler cards
    Card filler('0','0');
    for (int i=0; i<4; i++)
        playedDeck.push_back(filler);

}

void Game::setNames(std::string &name, std::string &name1, std::string &name2, std::string &name3) {
    //Sets the players' names
    Player0.setName(name);
    Player1.setName(name1);
    Player2.setName(name2);
    Player3.setName(name3);
}

bool Game::setFinalScore(int finalScore) {
    //Sets the desired score cap
    if (finalScore <= 0)
	return false;
    this -> finalScore = finalScore;
    return true;
}

void Game::shuffleDeal() {
    //Creates, shuffles, and deals the main deck and finds and sets the starter to the currentPlayer

    //Creates full main deck of cards
    char suit[] = {'C','D','H','S'};
    char value[] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
    for (int i=0; i<4; i++) {
        for (int j=0; j<13; j++) {
            Card *newCard = new Card(suit[i],value[j]);
            mainDeck.push_back(*newCard);
        }
    }

    //Shuffles the main deck

    srand(time(NULL));
    std::random_shuffle(mainDeck.begin(), mainDeck.end());
    

    //Deals the cards from deck to the players
    while (mainDeck.size() > 0) {
        Card temp(mainDeck[0].getSuit(), mainDeck[0].getValue());
        Player0.addCard(temp);
        mainDeck.erase(mainDeck.begin());
        Card temp1(mainDeck[0].getSuit(), mainDeck[0].getValue());
        Player1.addCard(temp1);
        mainDeck.erase(mainDeck.begin());
        Card temp2(mainDeck[0].getSuit(), mainDeck[0].getValue());
        Player2.addCard(temp2);
        mainDeck.erase(mainDeck.begin());
        Card temp3(mainDeck[0].getSuit(), mainDeck[0].getValue());
        Player3.addCard(temp3);
        mainDeck.erase(mainDeck.begin());
    }

    //Sorts cards by suit and value
    Player0.sortCards();
    Player1.sortCards();
    Player2.sortCards();
    Player3.sortCards();

    //Finds and sets the starter
    if (Player0.isStart())
        starter = 0;
    else if(Player1.isStart())
        starter = 1;
    else if(Player2.isStart())
        starter = 2;
    else
        starter = 3;

    currentPlayer = starter;

    //Because new round, hearts are set as not broken
    heartsBroken = false;
}

bool Game::cardPlayed(Card & inCard) {
    //Error checks to make sure valid card is played. Returns false if invalid card 
    //played. If played card is valid, removes the played card from the current player's hand, adds the 
    //played card to the playedDeck, changes the currentPlayer data field to the next player, and returns true.
    

    //Checks if Player has card
    bool cardInHand;
    switch (currentPlayer) {
	case 0:
		cardInHand = Player0.hasCard(inCard);
		break;
	case 1:
		cardInHand = Player1.hasCard(inCard);
		break;
	case 2: 
		cardInHand = Player2.hasCard(inCard);
		break;
	default:
		cardInHand = Player3.hasCard(inCard);
		break;
    }
    if (!cardInHand) {
	return false;
	}

    //If card is first of the round, checks if it's the 2 of Clubs
   if (currentPlayer == starter) {
	std::vector<Card> hand;
	switch (currentPlayer) {
		case 0:
			hand = Player0.getHand();
			break;
		case 1:
			hand = Player1.getHand();
			break;
		case 2: 
			hand = Player2.getHand();
			break;
		default:
			hand = Player3.getHand();
			break;
	}
	if (hand.size() == 13 && (inCard.getSuit() != 'C' || inCard.getValue() != '2')) {
		return false;
	}
    }

    //Checks if heart or Queen of Spades is played during first trick
    if (inCard.getSuit() == 'H'||(inCard.getSuit() == 'S' && inCard.getValue() == 'Q')) {
	std::vector<Card> hand;
	switch (currentPlayer) {
		case 0:
			hand = Player0.getHand();
			break;
		case 1:
			hand = Player1.getHand();
			break;
		case 2: 
			hand = Player2.getHand();
			break;
		default:
			hand = Player3.getHand();
			break;
	}
	if (hand.size() == 13) {
		return false;
	}
    }
    
    //Checks if card is matching starter's suit, if possible
    if (currentPlayer!=starter && playedDeck[starter].getSuit() != inCard.getSuit()) {
   	bool correctSuit;
	switch (currentPlayer) {
		case 0:
			correctSuit = Player0.hasSuit(playedDeck[starter].getSuit());
			break;
		case 1:
			correctSuit = Player1.hasSuit(playedDeck[starter].getSuit());
			break;
		case 2: 
			correctSuit = Player2.hasSuit(playedDeck[starter].getSuit());
			break;
		default:
			correctSuit = Player3.hasSuit(playedDeck[starter].getSuit());
			break;
	}
	if (correctSuit) {
		return false;
	}
    }

    //Checks if hearts/Queen of Spades start trick before hearts have been broken
    if (!heartsBroken && currentPlayer==starter && (inCard.getSuit() == 'H' || (inCard.getSuit() == 'S' && inCard.getValue() == 'Q'))) {
		return false;
    }


    //If card is valid and is first Hearts or Queen of Spades, breaks hearts
    if (!heartsBroken && (currentPlayer != starter) && (inCard.getSuit() == 'H' || (inCard.getSuit() == 'S' && inCard.getValue() == 'Q'))) {
	heartsBroken = true;
    }
	
    //If card is valid, removes card from players hand and adds it to the played deck in the appropriate
    //position, moves the currentPlayer to the next player, and returns true.
    
    switch (currentPlayer) {
	case 0:
		Player0.removeCard(inCard);
		playedDeck[0]=inCard;
		currentPlayer++;
		break;
	case 1:
		Player1.removeCard(inCard);
		playedDeck[1]=inCard;
		currentPlayer++;
		break;
	case 2:
		Player2.removeCard(inCard);
		playedDeck[2]=inCard;
		currentPlayer++;
		break;
	default:
		Player3.removeCard(inCard);
		playedDeck[3]=inCard;
		currentPlayer = 0;
		break;
	}

	return true;   
    
}

bool Game::isEndOfTrick() const {
    //Returns true if the trick is over, i.e. if there are 4 played cards
    if (playedDeck.size()==4)
        return true;
    return false;
}

void Game::endOfTrick() {
    //Finds the highest card in the same suit as the initial card and adds the playedDeck to the
    //pointsCards deck of the player that played it. This player becomes the new starter.
    // Also clears the played deck.

    //Reads in the suit and value of the initial card of the trick
    char origSuit;
    char highestValue;
    switch(starter) {
        case 0:
            origSuit=playedDeck[0].getSuit();
            highestValue=playedDeck[0].getValue();
            break;
        case 1:
            origSuit=playedDeck[1].getSuit();
            highestValue=playedDeck[1].getValue();
            break;
        case 2:
            origSuit=playedDeck[2].getSuit();
            highestValue=playedDeck[2].getValue();
            break;
        default:
            origSuit=playedDeck[3].getSuit();
            highestValue=playedDeck[3].getValue();
            break;
    }

    //Finds the highest card played in the initial suit and sets the starter to the player that
    //played it
    if (highestValue != 'A') {
        for (int i=0; i<4; i++) {
            if (playedDeck[i].getSuit()==origSuit) {
                if (playedDeck[i].getValue()=='A') {
                    starter = i;
                    break;
                }
                else if ((playedDeck[i].getValue()>57 && highestValue<=57) || (playedDeck[i].getValue()<=57 && highestValue<=57 && playedDeck[i].getValue()>highestValue)){
                    starter = i;
                    highestValue = playedDeck[i].getValue();
                }
                else if ((playedDeck[i].getValue()=='J' && highestValue == 'T')|| (playedDeck[i].getValue()=='Q' && highestValue != 'K') || playedDeck[i].getValue()=='K'){
                    starter = i;
                    highestValue = playedDeck[i].getValue();
                }
            }
        }
    }

    //Moves the cards in playedDeck that have a points value to a temporary vector
    std::vector<Card> temp;
    for (int i=0; i<playedDeck.size();i++) {
        if (playedDeck[i].getSuit()=='H' || (playedDeck[i].getSuit()=='S' && playedDeck[i].getValue()=='Q')) {
            temp.push_back(playedDeck[i]);
        }
    }

    //Gives the cards worth points to the person who played the highest card in the
    // initial suit in the trick
    switch(starter) {
        case 0:
            Player0.addPointsCards(temp);
            break;
        case 1:
            Player1.addPointsCards(temp);
            break;
        case 2:
            Player2.addPointsCards(temp);
            break;
        default:
            Player3.addPointsCards(temp);
            break;
    }


    //Clears the playedDeck
    Card filler('0','0');
    for (int i=0; i<4; i++) {
	playedDeck.erase(playedDeck.begin());
        playedDeck.push_back(filler);
    }

    //Sets the current player to the starter
    currentPlayer=starter;
}

bool Game::isEndOfRound() const {
    //Returns true if the players have no cards left in their hands, meaning the round is over
    std::vector<Card> temp;
    temp = Player0.getHand();
    if (temp.size() == 0)
        return true;
    return false;
}

void Game::endOfRound() {
    //Adds scores for every player and if a player shoots the moon,
    //26 points are added to their opponents

    //Adds players scores
    int moon0, moon1, moon2, moon3;
    moon0 = Player0.addScore();
    moon1 = Player1.addScore();
    moon2 = Player2.addScore();
    moon3 = Player3.addScore();

    //Checks if any player has shot the moon and adds 26 to opponents if someone has
    if (moon0 == -1) {
        Player1.add26();
        Player2.add26();
        Player3.add26();
    }
    else if(moon1 == -1) {
        Player0.add26();
        Player2.add26();
        Player3.add26();
    }
    else if (moon2 == -1) {
        Player0.add26();
        Player1.add26();
        Player3.add26();
    }
    else if (moon3 == -1) {
        Player0.add26();
        Player1.add26();
        Player2.add26();
    }
}

bool Game::isGameOver() const {
    //Returns true if a player has a score greater than the desired cap score
    if (Player0.getScore() > finalScore || Player1.getScore() > finalScore || Player2.getScore() > finalScore || Player3.getScore() > finalScore) {
        return true;
    }
    return false;
}

int Game::getStarter() const {
    //Returns the starter player
    return starter;
}

int Game::getCurrentPlayer() const {
    //Returns the player whose turn it is
    return currentPlayer;
}

int * Game::getScores() const {
    //Returns an array of the scores, with the indices matching the players' orders
    int *scores = new int[4];
    scores[0] = Player0.getScore();
    scores[1] = Player1.getScore();
    scores[2] = Player2.getScore();
    scores[3] = Player3.getScore();
    return scores;
}

int Game::getWinner() const {
    //Returns the winner

    //Creates an array of the players scores
    int *scores = new int[4];
    scores[0] = Player0.getScore();
    scores[1] = Player1.getScore();
    scores[2] = Player2.getScore();
    scores[3] = Player3.getScore();

    //Loops through the players' scores to find the lowest
    int lowestScore = finalScore;
    int winner;
    for (int i=0; i<4; i++) {
        if (scores[i] < lowestScore) {
            winner = i;
            lowestScore = scores[i];
        }
    }
    delete scores;
    return winner;
}

std::vector<Card> Game::getPlayerHand(int player) const {
    //Returns current hand of desired player
    std::vector<Card> hand;
    switch(player) {
        case 0:
            hand = Player0.getHand();
        case 1:
            hand = Player1.getHand();
        case 2:
            hand = Player2.getHand();
        default:
            hand = Player3.getHand();
    }
    return hand;
}


std::vector<Card> Game::getPlayedDeck() const {

	return playedDeck;
}
