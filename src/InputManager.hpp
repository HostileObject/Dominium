#pragma once

#include <SFML/Graphics.hpp>
namespace DAi
{
	class InputManager
	{
	private:
	public:
		InputManager(){};
		~InputManager(){};

		bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

		sf::Vector2i getMousePosition(sf::RenderWindow &window);

		bool isMouseOver(sf::Sprite object, sf::RenderWindow &window);

		bool isKeyPressed(sf::Keyboard::Key key, sf::Event event, sf::RenderWindow &window);
	};
}
