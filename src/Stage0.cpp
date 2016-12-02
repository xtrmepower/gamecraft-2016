#include "Stage0.hpp"

Stage0::Stage0(std::shared_ptr<sf::RenderWindow> window_)
{
	window = window_;

	float size_x = window->getSize().x;
	float size_y = window->getSize().y;
	my_view.setCenter(size_x*0.5f, size_y*0.5f);
	my_view.setSize(size_x, size_y);

	old_view_center.x = window_->getView().getCenter().x;
	old_view_center.y = window_->getView().getCenter().y;

	window->setView(my_view);
}

void Stage0::draw()
{
	my_view.setCenter(p.getPos());
	window->setView(my_view);
	p.draw(window);
}

void Stage0::update()
{
	p.update();
}

void Stage0::reset()
{
	my_view.setCenter(old_view_center);
	window->setView(my_view);
	p.reset();
}