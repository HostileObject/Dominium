#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "Card.hpp"

namespace DAi
{
    class CardDeck
    {
    private:
        void addCard(int cardName, int cardSuit, std::string filePath);
        std::vector<Card> _cards;

        void createDeck();

    public:
        CardDeck();
        ~CardDeck(){};

        void reInit();

        bool isEmpty();

        void shuffleDeck();

        Card getFirstDominium();

        Card getTopCard();
    };

}