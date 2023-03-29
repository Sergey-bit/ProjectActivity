#pragma once

#include "Object.hpp"
#include "Sprite.hpp"

namespace Core
{
	class AbstractButton : virtual public GameObject
	{
	protected:
		virtual void hover() = 0;
		virtual void pressed() = 0;

	};
}


