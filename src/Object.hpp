#pragma once

namespace Core
{
	class GameObject
	{
	protected:
		bool visibility_ = true;

	public:
		virtual void draw() = 0;

		virtual bool isVisible() const = 0;
		virtual void setVisibility(bool) = 0;
	};
}
