#include <Position.hpp>

float rotableObjectPosition::x() const
{
	return pos.x;
}
float rotableObjectPosition::y() const
{
	return pos.y;
}

void rotableObjectPosition::setX(float x)
{
	pos.x = x;
}
void rotableObjectPosition::setY(float y)
{
	pos.y = y;
}

double rotableObjectPosition::getAngle() const
{
	return angle;
}
void rotableObjectPosition::setAngle(float angle)
{
	this->angle = angle;
}

void rotableObjectPosition::rotate(float deltaAngle)
{
	angle += deltaAngle;
}
std::string rotableObjectPosition::toStrData() const
{
	return "x:" + std::to_string(pos.x) + ";y:" +
		std::to_string(pos.y) + ";angle:" + std::to_string(angle);
}