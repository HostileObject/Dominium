#include <sstream>
#include "SplashState.hpp"
#include <iostream>
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"

namespace DAi
{
    SplashState::SplashState(GameDataRef data) : _data(data)
    {
    }

    void SplashState::init()
    {
        this->_data->assets.loadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

        _background.setTexture(this->_data->assets.getTexture("Splash State Background"));
    }

    void SplashState::handleInput()
    {
        sf::Event event;

        while (this->_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }
        }
    }

    void SplashState::update(float dt)
    {
        if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
        {
            //Switch to the main menu
            if (dt == 1)
            {
                std::cout << dt << std::endl;
            }
            this->_data->machine.addState(stateRef(new MainMenuState(_data)), true);
        }
    }

    void SplashState::draw(float dt)
    {
        if (dt == 1)
        {
            std::cout << dt << std::endl;
        }

        this->_data->window.clear(sf::Color::Red);

        this->_data->window.draw(this->_background);

        this->_data->window.display();
    }
}
