#pragma once

#include "Vector.hpp"
#include <vector>

namespace Core
{
	class GameObject;

	class Settings final
	{
	private:
		using Uint32 = unsigned int;

		static std::vector<GameObject*> objects_;
		static vec2f scale_;

	public:
		static void addGameObject(GameObject*& object);

		static vec2f getGlobalScale();
		static void setGlobalScale(const float& scale);

		static void setGlobalScale(const float& xs, const float& ys);
		static void setGlobalScale(const vec2f& nvec);
	};
}
