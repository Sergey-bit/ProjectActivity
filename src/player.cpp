#include <player.hpp>

Player::Player(sf::RenderWindow& win, Profile& profile) : win_(win), profile_(profile)
{

}
void Player::lookAt(const float& angle)
{
	angle_ = angle;
}

void Player::lookingAround()
{
	vec2i ray = sf::Mouse::getPosition() - pos_;
	angle_ = std::acos(ray.x / length(ray)) * 180.0 / PI;

	if (ray.y < 0)
	{
		angle_ += 180.0f;
	}
}
const float& Player::getAngle() const
{
	return angle_;
}