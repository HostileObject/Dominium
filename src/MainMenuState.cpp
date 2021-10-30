#include "MainMenuState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include <iostream>
#include "GameState.hpp"

namespace DAi
{
    MainMenuState::MainMenuState(GameDataRef data) : _data(data)
    {
    }

    void MainMenuState::init()
    {
        this->_data->assets.loadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
        this->_data->assets.loadTexture("Title", MAIN_MENU_TITLE_FILEPATH);
        this->_data->assets.loadTexture("PuntoDiDomanda", PUNTO_DI_DOMANDA_FILEPATH);
        this->_data->assets.loadTexture("Hamburguer", HAMBURGUER_FILEPATH);
        this->_data->assets.loadTexture("OfflineButton", OFFLINE_BUTTON_FILEPATH);
        this->_data->assets.loadTexture("OfflineButtonOver", OFFLINE_BUTTON_OVER_FILEPATH);
        this->_data->assets.loadTexture("OnlineButton", ONLINE_BUTTON_FILEPATH);
        this->_data->assets.loadTexture("OnlineButtonOver", ONLINE_BUTTON_OVER_FILEPATH);
        this->_data->assets.loadTexture("PrivateButton", PRIVATE_BUTTON_FILEPATH);
        this->_data->assets.loadTexture("PrivateButtonOver", PRIVATE_BUTTON_OVER_FILEPATH);

        this->_background.setTexture(this->_data->assets.getTexture("Background"));
        this->_title.setTexture(this->_data->assets.getTexture("Title"));
        this->_puntoDiDomanda.setTexture(this->_data->assets.getTexture("PuntoDiDomanda"));
        this->_hamburguer.setTexture(this->_data->assets.getTexture("Hamburguer"));
        this->_offlineButton.setTexture(this->_data->assets.getTexture("OfflineButton"));
        this->_offlineButtonOver.setTexture(this->_data->assets.getTexture("OfflineButtonOver"));
        this->_onlineButton.setTexture(this->_data->assets.getTexture("OnlineButton"));
        this->_onlineButtonOver.setTexture(this->_data->assets.getTexture("OnlineButtonOver"));
        this->_privateButton.setTexture(this->_data->assets.getTexture("PrivateButton"));
        this->_privateButtonOver.setTexture(this->_data->assets.getTexture("PrivateButtonOver"));

        this->_title.setPosition((SCREEN_WIDTH / 2) - (this->_title.getGlobalBounds().width / 2), 0);

        this->_offlineButton.setPosition((SCREEN_WIDTH) - (this->_offlineButton.getGlobalBounds().width * 1.28), 700);
        this->_offlineButtonOver.setPosition((SCREEN_WIDTH) - (this->_offlineButtonOver.getGlobalBounds().width * 1.28), 700);

        this->_onlineButton.setPosition((SCREEN_WIDTH / 2) - (this->_onlineButton.getGlobalBounds().width / 2), 700);
        this->_onlineButtonOver.setPosition((SCREEN_WIDTH / 2) - (this->_onlineButtonOver.getGlobalBounds().width / 2), 700);

        this->_privateButton.setPosition((SCREEN_WIDTH / 10) - (this->_privateButton.getGlobalBounds().width / 10), 700);
        this->_privateButtonOver.setPosition((SCREEN_WIDTH / 10) - (this->_privateButtonOver.getGlobalBounds().width / 10), 700);

        this->_puntoDiDomanda.setPosition(((SCREEN_WIDTH) - this->_puntoDiDomanda.getGlobalBounds().width) - this->_hamburguer.getGlobalBounds().width - 5, 10);
        this->_hamburguer.setPosition((SCREEN_WIDTH) - (this->_hamburguer.getGlobalBounds().width + 5), 12);
    }

    void MainMenuState::handleInput()
    {
        sf::Event event;

        while (this->_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }
            if (this->_data->input.isSpriteClicked(this->_offlineButtonOver, sf::Mouse::Left, this->_data->window))
            {
                this->_data->machine.addState(stateRef(new GameState(_data)), true);
            }
        }
    }

    void MainMenuState::update(float dt)
    {
        if (dt == 1)
        {
            std::cout << dt << std::endl;
        }

        if (this->_data->input.isMouseOver(this->_offlineButton, this->_data->window))
        {
            this->isOverOffline = true;
        }
        else
        {
            this->isOverOffline = false;
        }
        if (this->_data->input.isMouseOver(this->_onlineButton, this->_data->window))
        {
            this->isOverOnline = true;
        }
        else
        {
            this->isOverOnline = false;
        }
        if (this->_data->input.isMouseOver(this->_privateButton, this->_data->window))
        {
            this->isOverPrivate = true;
        }
        else
        {
            this->isOverPrivate = false;
        }
    }

    void MainMenuState::draw(float dt)
    {
        if (dt == 1)
        {
            std::cout << dt << std::endl;
        }
        this->_data->window.clear();

        this->_data->window.draw(this->_background);
        this->_data->window.draw(this->_title);
        if (isOverOffline)
        {
            this->_data->window.draw(this->_offlineButtonOver);
        }
        else
        {
            this->_data->window.draw(this->_offlineButton);
        }
        if (isOverOnline)
        {
            this->_data->window.draw(this->_onlineButtonOver);
        }
        else
        {
            this->_data->window.draw(this->_onlineButton);
        }
        if (isOverPrivate)
        {
            this->_data->window.draw(this->_privateButtonOver);
        }
        else
        {
            this->_data->window.draw(this->_privateButton);
        }
        this->_data->window.draw(this->_puntoDiDomanda);
        this->_data->window.draw(this->_hamburguer);

        this->_data->window.display();
    }
}
