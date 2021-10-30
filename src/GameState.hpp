#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "CardDeck.hpp"
#include "Card.hpp"
#include <vector>

namespace DAi
{
    class GameState : public State
    {
    private:
        GameDataRef _data;
        sf::Sprite _background;
        sf::Sprite _puntoDiDomanda;
        sf::Sprite _hamburguer;
        sf::Sprite _cardBack;
        CardDeck _deck;
        Card _topCard;

        std::vector<Card> _firstPlayerHand;
        std::vector<Card> _secondPlayerHand;

        sf::Sprite dummy;
        std::vector<sf::Sprite> _FPHsprites{4, dummy};
        std::vector<sf::Sprite> _SPHsprites{4, dummy};

        std::stack<Card> _dominiumPile;

        std::vector<Card> _field;
        std::vector<sf::Sprite> _fieldSprites{2, dummy};

        sf::Sprite _playedCard;
        sf::Sprite _playedDominium;

        bool firstPlayerTurn = true;

    public:
        GameState(GameDataRef data);
        ~GameState();

        void init();

        void initialCardDraw();

        void turnCardDraw();

        void findADominium();

        void updateDominiumSprite();

        void calculateOutcome();

        void playCard(int index, std::vector<Card> playerHand);

        void slideCards(bool isFPTurn, int index);

        int whatDominium();

        void handleInput();
        void update(float dt);
        void draw(float dt);
    };
}