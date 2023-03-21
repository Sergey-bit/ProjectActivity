#pragma once

#include "Vector.hpp"

namespace Core
{
	class Settings
	{
	private:
		vec2f scale_;
		Settings();

	public:
		virtual vec2f getGlobalScale() const;
		virtual void setGlobalScale(const float& scale);

		virtual void setGlobalScale(const float& xs, const float& ys);
		virtual void setGlobalScale(const vec2f& nvec);

		static Settings& getInstance();
	};
}
