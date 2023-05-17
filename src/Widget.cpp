#include <Object.hpp>

vec2f Core::Settings::getGlobalScale()
{
	return scale_;
}
void Core::Settings::setGlobalScale(const float& scale)
{
	setGlobalScale({ scale, scale });
}

void Core::Settings::setGlobalScale(const float& xs, const float& ys)
{
	setGlobalScale({ xs, ys });
}
void Core::Settings::setGlobalScale(const vec2f& scale)
{
	scale_ = scale;
	for (GameObject* object : objects_)
	{
		object->setScale(scale_);
	}
}

void Core::Settings::addGameObject(GameObject*& object)
{
	objects_.push_back(object);
}

Core::GameObject::GameObject()
{
}

std::vector<Core::GameObject*> Core::Settings::objects_;
vec2f Core::Settings::scale_(1.f, 1.f);
char Core::Settings::entered;
int Core::Settings::mouseWheelMoved = 0;