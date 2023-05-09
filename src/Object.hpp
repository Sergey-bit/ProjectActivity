#pragma once

#include "Widget.hpp"

namespace Core
{
	class GameObject
	{
	protected:
		bool visibility_ = true;
		
		GameObject();
	public:
		virtual void draw() = 0;
		virtual void setScale(const vec2f&) = 0;

		virtual bool isVisible() const = 0;
		virtual void setVisibility(bool) = 0;
	};
}
