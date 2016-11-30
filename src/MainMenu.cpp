#include "MainMenu.hpp"

extern std::unique_ptr<AssetManager> ASSETMGR;

MainMenu::MainMenu(std::shared_ptr<sf::RenderWindow> window_) : View(window_) {

	// Make buttons
	auto apply_button = [] (const char* txt, const sf::Vector2f &pos) -> sf::Text {
		auto btn = sf::Text(txt, ASSETMGR->main_menu_font, 40U);
		auto tr = btn.getLocalBounds();
		btn.setOrigin(tr.left + tr.width / 2.0f, tr.top + tr.height / 2.0f);
		btn.setPosition(pos);
		return btn;
	};

	sf::Vector2f buttonHalfDims = sf::Vector2f(200.0f, 25.0f) * scale_factor;
	const float buttonGap = (20.0f + 2.0f * buttonHalfDims.y) * scale_factor.y;
	const float baseY = (res.y / 2.0f) + (2.0f * buttonHalfDims.y);
	sf::Vector2f curr(res.x / 2.0f, baseY);
	newgame_btn = apply_button("New Game", curr);
	curr.y += buttonGap;
	continue_btn = apply_button("Continue", curr);
	curr.y += buttonGap;
	options_btn = apply_button("Options", curr);
	curr.y += buttonGap;
	exit_btn = apply_button("Exit", curr);
}

const ViewMode MainMenu::view_loop() {
	View::standardStateLoop();
	return (ViewMode)current_option;
}

void MainMenu::draw() {
	window->clear(sf::Color(64, 64, 127));

	// Buttons. Draw order is top to bottom.
	sf::Vector2f highlgHalfDims = sf::Vector2f(210.0f, 25.0f) * scale_factor;
	sf::Vector2f buttonHalfDims = sf::Vector2f(200.0f, 25.0f) * scale_factor;
	const float buttonGap = (20.0f + 2.0f * buttonHalfDims.y) * scale_factor.y;

	const float baseY = (res.y / 2.0f) + (2.0f * buttonHalfDims.y);

	// Highlighted option
	sf::Vector2f curr(res.x / 2.0f, baseY + (current_option - 1) * buttonGap);
	auto highlg = create_rect(curr - highlgHalfDims, curr + highlgHalfDims, sf::Color::Yellow);
	window->draw(highlg);

	window->draw(newgame_btn);
	window->draw(continue_btn);
	window->draw(options_btn);
	window->draw(exit_btn);

	window->display();
}

void MainMenu::processKeypress(const sf::Keyboard::Key &key) {
	switch (key) {
	case sf::Keyboard::Return:
	case sf::Keyboard::Space:
	{
		exit_state = true;
		break;
	}

	case sf::Keyboard::Up:
	case sf::Keyboard::W:
	{
		--current_option;
		if (current_option < 1)
			current_option = 4;
		break;
	}

	case sf::Keyboard::Down:
	case sf::Keyboard::S:
	{
		++current_option;
		if (current_option > 4)
			current_option = 1;
		break;
	}
	default:
	{
		break;
	}
	}
}