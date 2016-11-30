#ifndef VIEW_HPP
#define VIEW_HPP
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "util.hpp"

constexpr float FPS = 1.0f/60.0f;

// All possible game states
enum ViewMode {
	MAIN_MENU = 0,

	// Enums used by Main Menu
	IN_GAME = 1,
	LOAD_SAVE = 2,
	OPTION_MENU = 3,
	EXIT = 4,

	// Enums used while in playing state
	INGAME_MENU = 10,
	INGAME_BATTLE = 11
};

// View is the asbtract class that covers all viewable scenes of the game.
// This includes menus, the game scene itself, and any other things.
// It includes a RenderWindow to draw any view on.
// Ideally any views of the game only needs to implement:
// 1. Human input event handling (via the process**() functions)
// 2. What to draw 
class View {
public:
	View(std::shared_ptr<sf::RenderWindow> window_) 
		: window(window_), res(window_->getSize()) {
		set_scale_factor();
	}
	~View() {}

	// Draws the game onto the screen. May call several helper functions.
	virtual void draw() = 0;

	// The view loop is the event handling and update loop for each of the views.
	// When the program leaves a ViewMode it will return the next ViewMode
	// it should go to. For example, if the player exits the game from the MainMenu,
	// then it should return the EXIT ViewMode.
	virtual const ViewMode view_loop() = 0;

	// This applies changes accumulated with processEvent to the game state once every FPS.
	virtual void update() {}

protected:
	// All state loops have the same structure, but may have different return protocols.
	void standardStateLoop();

	// All menus must have these basic event processing formulas.
	// At least one event must set exit_state to false; otherwise the state will never be
	// broken out of.
	void processEvent(const sf::Event &event_);

	// Fine-tuned event processing is delegated to the concrete classes.
	// Otherwise they will do nothing by default.
	virtual void processKeypress(const sf::Keyboard::Key &key) {}
	virtual void processKeyrelease(const sf::Keyboard::Key &key) {}
	virtual void processMouseClick(const int x, const int y) {}
	virtual void processMouseMove(const int x, const int y) {}

	// Misc convenience functions
	void draw_rectangle(const sf::Vector2f &pos, const sf::Vector2f &size, const sf::Color &color);
	void set_scale_factor();

	std::shared_ptr<sf::RenderWindow> window;
	sf::Vector2f scale_factor;
	sf::Vector2u res; // Resolution
	bool exit_state;
};

inline void View::standardStateLoop() {
	exit_state = false;
	sf::Clock clock;
	float dt = 0.0f;
	sf::Event event_;

	while (!exit_state) {
		dt += clock.getElapsedTime().asSeconds();
		clock.restart();
		while (window->pollEvent(event_)) {
			processEvent(event_);
		}
		while (dt > FPS) {
			dt -= FPS;
			update();
		}
		draw();
	}
}

inline void View::processEvent(const sf::Event &event_) {
	switch (event_.type) {
	case sf::Event::KeyPressed:
	{
		processKeypress(event_.key.code);
		break;
	}
	case sf::Event::KeyReleased:
	{
		processKeyrelease(event_.key.code);
		break;
	}
	case sf::Event::MouseButtonPressed:
	{
		auto e = event_.mouseButton;
		if (e.button != sf::Mouse::Button::Left)
			return; // Don't care about any button except left
		processMouseClick(e.x, e.y);
		break;
	}
	case sf::Event::MouseMoved:
	{
		auto e = event_.mouseMove;
		processMouseMove(e.x, e.y);
		break;
	}
	// Put other input events here as need arises.
	default: return;
	}
}

inline void View::draw_rectangle(const sf::Vector2f &pos, const sf::Vector2f &size, const sf::Color &color) {
	sf::RectangleShape shape;
	shape.setFillColor(color);
	shape.setPosition(pos);
	shape.setSize(size - pos);
	window->draw(shape);
}

// Scale factors should be a multiple of the
// HD 720 resolution.
inline void View::set_scale_factor() {
	auto size = window->getSize();
	switch (size.y) {
	case 1440:
		scale_factor = sf::Vector2f(2.0f, 2.0f); break;
	case 1080:
		scale_factor = sf::Vector2f(1.5f, 1.5f); break;
	case 768:
		scale_factor = sf::Vector2f(1.067f, 1.067f); break;
	case 720:
	default:
		scale_factor = sf::Vector2f(1.0f, 1.0f); break;
	}
}

#endif // VIEW_HPP