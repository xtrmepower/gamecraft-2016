#include <string>
#include <SFML/Graphics.hpp>

class Enemy {
public:
    Enemy(int id);
    std::string getName();
    sf::Texture getTexture();
    std::vector<int> getEnemyType();
private:
    int id;
    std::string name;
    sf::Texture texture;
    std::vector<int> enemy_type;
};
