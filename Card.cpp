//
// Created by mckda on 11/19/2018.
//

#include "Card.h"

Card::Card(char suit, char value) {
    this -> suit = suit;
    this -> value = value;
}

char Card::getSuit() const {
    return suit;
}

char Card::getValue() const {
    return value;
}

void Card::setSuit(char suit) {
    this -> suit = suit;
}

void Card::setValue(char value) {
    this -> value = value;
}
