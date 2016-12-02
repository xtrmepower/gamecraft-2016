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

		if (!weapon_texture_0.loadFromFile("../../data/W_Bow01.png"))
			throw std::runtime_error("Texture W_Bow01.png not found!");

		if (!weapon_texture_1.loadFromFile("../../data/W_Gun001.png"))
			throw std::runtime_error("Texture W_Gun001.png not found!");

		if (!weapon_texture_2.loadFromFile("../../data/W_Sword001.png"))
			throw std::runtime_error("Texture W_Sword001.png not found!");
	}

	~AssetManager() {}

	sf::Font main_menu_font;
	sf::Font test_font;
    
    sf::Texture weapon_texture_0;
    sf::Texture weapon_texture_1;
    sf::Texture weapon_texture_2;
    
    sf::Texture enemy_texture_0;
    sf::Texture enemy_texture_1;
    sf::Texture enemy_texture_2;

    sf::Texture boss_texture_0;
    sf::Texture boss_texture_1;
    sf::Texture boss_texture_2;
};

#endif // ASSET_MANAGER_HPP