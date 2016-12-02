#include <string>
#include <SFML/Graphics.hpp>

class Weapon {
public:
    Weapon(int id);
    std::string getName();
    sf::Texture getTexture();
    float getRange();
    float getDamage();
    float calculateBossDamage(float distance);
    float calculateWinningChance(std::vector<int> enemy_type);
private:
    int id;
    std::string name;
    sf::Texture texture;
    float range;
    float damage;
};
