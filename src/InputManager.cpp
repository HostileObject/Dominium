#include "InputManager.hpp"
#include <iostream>
#include <sstream>

namespace DAi
{
	bool InputManager::isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
	{
		if (sf::Mouse::isButtonPressed(button))
		{
			sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
			if (tempRect.contains(sf::Mouse::getPosition(window)))
			{
				return true;
			}
		}
		return false;
	}

	sf::Vector2i InputManager::getMousePosition(sf::RenderWindow &window)
	{
		return sf::Mouse::getPosition(window);
	}

	bool InputManager::isMouseOver(sf::Sprite object, sf::RenderWindow &window)
	{
		sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
		if (tempRect.contains(sf::Mouse::getPosition(window)))
		{
			return true;
		}
		return false;
	}

	bool InputManager::isKeyPressed(sf::Keyboard::Key key, sf::Event event, sf::RenderWindow &window)
	{
		window.setKeyRepeatEnabled(false);
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == key)
			{
				return true;
			}
		}
		return false;
	}
}
