#pragma once

#include "Widget.hpp"

namespace Core
{
	class GameObject
	{
	protected:
		bool visibility_ = true;
		
		GameObject();

	private:
		vec2f scale;
	public:
		virtual void draw() = 0;
		virtual void setScale(const vec2f&);

		virtual bool isVisible() const;
		virtual void setVisibility(bool) ;
	};
}
