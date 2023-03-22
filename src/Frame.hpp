#pragma once

#include <Vector.hpp>
#include <vector>

class Frame
{
private:
	vec2i size_;
	vec2i pos_;

public:
	Frame(const vec2i& size, const vec2i& position = { 0, 0 });
	virtual void work() = 0;

	virtual const vec2i& getSize() const;
	virtual void setSize(const vec2i& nsize);

	virtual const vec2i& getPosition() const;
	virtual void setPosition(const vec2i& npos);
};
