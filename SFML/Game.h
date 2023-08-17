#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/*
	Class that act as the game engine
	Wrapper class
*/

class Game
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Mouse position
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Resources
	sf::Font font;

	//Text
	sf::Text uiText;
	
	//Game logic 
	unsigned points;
	int health;
	float enemySpawnTimer;
	float enemySpaenTimerMax;
	int maxEnemies;
	bool mouseHeld;
	bool endGame;

	//Game objects
	sf::RectangleShape enemy;
	std::vector<sf::RectangleShape> enemies;

	//Private functions
	void initVariables();
	void initWindow();
	void initFonts();
	void initText();
	void initEnemys();

public:
	//Constructor & Destructor
	Game();
	virtual ~Game();
	//Accessors 
	const bool running() const;
	const bool getEndGame() const;
	// Functions
	void spawnEnemy();

	void pollEvents();
	void updateMousePosition();
	void updateText();
	void updateEnemies();
	void update();

	void renderText(sf::RenderTarget& target);
	void renderEnemies(sf::RenderTarget& target);
	void render();
};

