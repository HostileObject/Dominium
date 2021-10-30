#include "CardDeck.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

namespace DAi
{
    void CardDeck::addCard(int cardName, int cardSuit, std::string filePath)
    {
        Card newCard(cardName, cardSuit, filePath);
        this->_cards.push_back(newCard);
    }

    void CardDeck::createDeck()
    {
        this->addCard(ACE_OF_SPADES, SPADES, ACE_OF_SPADES_SPRITE);
        this->addCard(TWO_OF_SPADES, SPADES, TWO_OF_SPADES_SPRITE);
        this->addCard(THREE_OF_SPADES, SPADES, THREE_OF_SPADES_SPRITE);
        this->addCard(FOUR_OF_SPADES, SPADES, FOUR_OF_SPADES_SPRITE);
        this->addCard(FIVE_OF_SPADES, SPADES, FIVE_OF_SPADES_SPRITE);
        this->addCard(SIX_OF_SPADES, SPADES, SIX_OF_SPADES_SPRITE);
        this->addCard(SEVEN_OF_SPADES, SPADES, SEVEN_OF_SPADES_SPRITE);
        this->addCard(EIGHT_OF_SPADES, SPADES, EIGHT_OF_SPADES_SPRITE);
        this->addCard(NINE_OF_SPADES, SPADES, NINE_OF_SPADES_SPRITE);
        this->addCard(TEN_OF_SPADES, SPADES, TEN_OF_SPADES_SPRITE);
        this->addCard(JACK_OF_SPADES, SPADES, JACK_OF_SPADES_SPRITE);
        this->addCard(QUEEN_OF_SPADES, SPADES, QUEEN_OF_SPADES_SPRITE);
        this->addCard(KING_OF_SPADES, SPADES, KING_OF_SPADES_SPRITE);

        this->addCard(ACE_OF_HEARTS, HEARTS, ACE_OF_HEARTS_SPRITE);
        this->addCard(TWO_OF_HEARTS, HEARTS, TWO_OF_HEARTS_SPRITE);
        this->addCard(THREE_OF_HEARTS, HEARTS, THREE_OF_HEARTS_SPRITE);
        this->addCard(FOUR_OF_HEARTS, HEARTS, FOUR_OF_HEARTS_SPRITE);
        this->addCard(FIVE_OF_HEARTS, HEARTS, FIVE_OF_HEARTS_SPRITE);
        this->addCard(SIX_OF_HEARTS, HEARTS, SIX_OF_HEARTS_SPRITE);
        this->addCard(SEVEN_OF_HEARTS, HEARTS, SEVEN_OF_HEARTS_SPRITE);
        this->addCard(EIGHT_OF_HEARTS, HEARTS, EIGHT_OF_HEARTS_SPRITE);
        this->addCard(NINE_OF_HEARTS, HEARTS, NINE_OF_HEARTS_SPRITE);
        this->addCard(TEN_OF_HEARTS, HEARTS, TEN_OF_HEARTS_SPRITE);
        this->addCard(JACK_OF_HEARTS, HEARTS, JACK_OF_HEARTS_SPRITE);
        this->addCard(QUEEN_OF_HEARTS, HEARTS, QUEEN_OF_HEARTS_SPRITE);
        this->addCard(KING_OF_HEARTS, HEARTS, KING_OF_HEARTS_SPRITE);

        this->addCard(ACE_OF_DIAMONDS, DIAMONDS, ACE_OF_DIAMONDS_SPRITE);
        this->addCard(TWO_OF_DIAMONDS, DIAMONDS, TWO_OF_DIAMONDS_SPRITE);
        this->addCard(THREE_OF_DIAMONDS, DIAMONDS, THREE_OF_DIAMONDS_SPRITE);
        this->addCard(FOUR_OF_DIAMONDS, DIAMONDS, FOUR_OF_DIAMONDS_SPRITE);
        this->addCard(FIVE_OF_DIAMONDS, DIAMONDS, FIVE_OF_DIAMONDS_SPRITE);
        this->addCard(SIX_OF_DIAMONDS, DIAMONDS, SIX_OF_DIAMONDS_SPRITE);
        this->addCard(SEVEN_OF_DIAMONDS, DIAMONDS, SEVEN_OF_DIAMONDS_SPRITE);
        this->addCard(EIGHT_OF_DIAMONDS, DIAMONDS, EIGHT_OF_DIAMONDS_SPRITE);
        this->addCard(NINE_OF_DIAMONDS, DIAMONDS, NINE_OF_DIAMONDS_SPRITE);
        this->addCard(TEN_OF_DIAMONDS, DIAMONDS, TEN_OF_DIAMONDS_SPRITE);
        this->addCard(JACK_OF_DIAMONDS, DIAMONDS, JACK_OF_DIAMONDS_SPRITE);
        this->addCard(QUEEN_OF_DIAMONDS, DIAMONDS, QUEEN_OF_DIAMONDS_SPRITE);
        this->addCard(KING_OF_DIAMONDS, DIAMONDS, KING_OF_DIAMONDS_SPRITE);

        this->addCard(ACE_OF_CLUBS, CLUBS, ACE_OF_CLUBS_SPRITE);
        this->addCard(TWO_OF_CLUBS, CLUBS, TWO_OF_CLUBS_SPRITE);
        this->addCard(THREE_OF_CLUBS, CLUBS, THREE_OF_CLUBS_SPRITE);
        this->addCard(FOUR_OF_CLUBS, CLUBS, FOUR_OF_CLUBS_SPRITE);
        this->addCard(FIVE_OF_CLUBS, CLUBS, FIVE_OF_CLUBS_SPRITE);
        this->addCard(SIX_OF_CLUBS, CLUBS, SIX_OF_CLUBS_SPRITE);
        this->addCard(SEVEN_OF_CLUBS, CLUBS, SEVEN_OF_CLUBS_SPRITE);
        this->addCard(EIGHT_OF_CLUBS, CLUBS, EIGHT_OF_CLUBS_SPRITE);
        this->addCard(NINE_OF_CLUBS, CLUBS, NINE_OF_CLUBS_SPRITE);
        this->addCard(TEN_OF_CLUBS, CLUBS, TEN_OF_CLUBS_SPRITE);
        this->addCard(JACK_OF_CLUBS, CLUBS, JACK_OF_CLUBS_SPRITE);
        this->addCard(QUEEN_OF_CLUBS, CLUBS, QUEEN_OF_CLUBS_SPRITE);
        this->addCard(KING_OF_CLUBS, CLUBS, KING_OF_CLUBS_SPRITE);
    }

    Card CardDeck::getFirstDominium()
    {
        Card firstDominium;
        for (int i = this->_cards.size() - 1; i > 0; i--)
        {
            if ((this->_cards.at(i).getCardName() >= 20 && this->_cards.at(i).getCardName() <= 22) || (this->_cards.at(i).getCardName() >= 33 && this->_cards.at(i).getCardName() <= 35) || (this->_cards.at(i).getCardName() >= 46 && this->_cards.at(i).getCardName() <= 48) || (this->_cards.at(i).getCardName() >= 59 && this->_cards.at(i).getCardName() <= 61) || (this->_cards.at(i).getCardName() == 10 || this->_cards.at(i).getCardName() == 23 || this->_cards.at(i).getCardName() == 36 || this->_cards.at(i).getCardName() == 49))
            {
                firstDominium = this->_cards.at(i);
                this->_cards.erase(this->_cards.begin() + i);
                break;
            }
        }
        return firstDominium;
    }

    CardDeck::CardDeck()
    {
        this->createDeck();
    }

    void CardDeck::reInit()
    {
        this->createDeck();
    }

    bool CardDeck::isEmpty()
    {
        return this->_cards.empty();
    }

    void CardDeck::shuffleDeck()
    {
        std::random_device rd;
        std::default_random_engine rng(rd());

        shuffle(_cards.begin(), _cards.end(), rng);
    }

    Card CardDeck::getTopCard()
    {
        Card topCard = this->_cards.back();
        this->_cards.pop_back();
        return topCard;
    }
}