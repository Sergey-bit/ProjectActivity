#pragma once

#include <Vector.hpp>
#include <string>

struct rotableObjectPosition
{
protected:
	vec2f pos;
	double angle;

public:

	virtual float x() const;
	virtual float y() const;

	virtual void setX(float x);
	virtual void setY(float y);

	virtual double getAngle() const;
	virtual void setAngle(float angle);
	virtual void rotate(float deltaAngle);

	virtual std::string toStrData() const;
};
