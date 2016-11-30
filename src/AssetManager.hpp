#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP

#include <string>
#include <SFML/Graphics.hpp>

class AssetManager {
public:

	// Load all the assets we have here!
	AssetManager() {
		if (!main_menu_font.loadFromFile("../../data/CrimsonText-Roman.ttf"))
			throw std::runtime_error("Font not found!");
	}

	~AssetManager() {}

	sf::Font main_menu_font;
	sf::Font test_font;
};

#endif // ASSET_MANAGER_HPP