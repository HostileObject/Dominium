#include "Card.hpp"

namespace DAi
{
    Card::Card(int newCardName, int newCardSuit, std::string filePath)
    {
        this->cardImage = filePath;
        this->cardName = newCardName;
        this->cardSuit = newCardSuit;
    }

    int Card::getCardName()
    {
        return this->cardName;
    }

    int Card::getCardSuit()
    {
        return this->cardSuit;
    }

    std::string Card::getFilePath()
    {
        return this->cardImage;
    }
}