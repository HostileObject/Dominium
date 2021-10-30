#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace DAi
{
    class MainMenuState : public State
    {
    private:
        GameDataRef _data;
        sf::Sprite _background;
        sf::Sprite _title;
        sf::Sprite _puntoDiDomanda;
        sf::Sprite _hamburguer;
        sf::Sprite _offlineButton;
        sf::Sprite _offlineButtonOver;
        sf::Sprite _onlineButton;
        sf::Sprite _onlineButtonOver;
        sf::Sprite _privateButton;
        sf::Sprite _privateButtonOver;

        bool isOverOffline = false;
        bool isOverOnline = false;
        bool isOverPrivate = false;

    public:
        MainMenuState(GameDataRef data);
        ~MainMenuState();

        void init();

        void handleInput();
        void update(float dt);
        void draw(float dt);
    };
}
