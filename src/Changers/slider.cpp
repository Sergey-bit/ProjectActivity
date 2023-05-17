#include "slider.hpp"


HorizontalSlider::HorizontalSlider(sf::RenderWindow& win, const vec2i& pos, const vec2i& size, const int& value)
	: win_(win), value_(value), sprite_()
{
	pos_ = pos;
	size_ = size;
	shader_ = nullptr;
	sprite_.setColor(sf::Color::White);
}
HorizontalSlider::~HorizontalSlider()
{
	if (shader_ != nullptr)
	{
		delete shader_;
	}
}

void HorizontalSlider::setFrShader(const std::string& filename)
{
	shader_ = new sf::Shader();

	if (!shader_->loadFromFile(filename, sf::Shader::Fragment))
	{
		throw "Failed to load shader";
	}
}
void HorizontalSlider::draw()
{
	win_.draw(sprite_, shader_);
}

float HorizontalSlider::getValue() const
{
	return static_cast<unsigned>(value_);
}