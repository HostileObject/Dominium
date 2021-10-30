#pragma once
#include <SFML/Graphics.hpp>

namespace DAi
{
    class Card
    {
    private:
        std::string cardImage;
        int cardName;
        int cardSuit;

    public:
        Card(){};
        Card(int newCardName, int newCardSuit, std::string filePath);
        ~Card(){};

        int getCardName();
        int getCardSuit();
        std::string getFilePath();
    };

}
