#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "AssetManager.hpp"
#include "InputManager.hpp"
#include "StateMachine.hpp"

namespace DAi
{
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	private:
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;

		GameDataRef _data = std::make_shared<GameData>();

		void run();

	public:
		Game(int width, int height);
	};
}