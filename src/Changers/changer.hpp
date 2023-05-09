#include <Object.hpp>
#include <Vector.hpp>

class Changer : virtual public Core::GameObject
{
protected:
	vec2i pos_ = { 0, 0 };
	vec2f scale_ = {1.0f, 1.0f};
public:
	virtual void draw() = 0;
	virtual unsigned int getValue() = 0;

	virtual void setScale(const vec2f& scale);
	virtual void setScale(const float& scale);
	virtual void setScale(const float& xs, const float& ys);

	virtual bool isVisible() const;
	virtual void setVisibility(bool);
};