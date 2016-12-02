#include "Stage0.hpp"

Stage0::Stage0(std::shared_ptr<sf::RenderWindow> window_) : 
	View(window_) 
{
}

void Stage0::draw()
{
	p.draw(window);
}

void Stage0::update()
{
	p.update();
}

const ViewMode Stage0::view_loop()
{
	View::standardStateLoop();
	return ViewMode::SCORE;
}

void Stage0::reset()
{
	p.reset();
}