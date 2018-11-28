//
// Created by mckda on 11/19/2018.
//

#ifndef HEARTS_CARD_H
#define HEARTS_CARD_H


class Card {
    public:
        Card(char suit, char value);
        char getValue() const;
        char getSuit() const;
        void setValue(char value);
        void setSuit(char suit);
    private:
        char value;
        char suit;
};


#endif //HEARTS_DECK_H
