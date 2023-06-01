#pragma once

#include "Vector.hpp"
#include <vector>

#define TEX_PATH "ProjectActivity\\resources\\textures\\"
#define FONT_PATH "ProjectActivity\\resources\\fonts\\"


namespace Core
{
	enum  Eqiupment {
		BIG_HEAL,
		SMALL_HEAL,
		ARMOR1,
		SNIPER,
		SOFF_SHOTGUN,
		SHOTGUN,
		MINIGUN,
		UZI,
		RIFLE,
	};
	enum BulletType {
		pistol,
		rifle,
		shotgun
	};
	class GameObject;

	class Settings final
	{
	private:
		using Uint32 = unsigned int;

		static std::vector<GameObject*> objects_;
		static vec2f scale_;

	public:
		static char entered;
		static int mouseWheelMoved;

		static void addGameObject(GameObject*& object);

		static vec2f getGlobalScale();
		static void setGlobalScale(const float& scale);

		static void setGlobalScale(const float& xs, const float& ys);
		static void setGlobalScale(const vec2f& nvec);
	};

}
