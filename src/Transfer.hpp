#pragma once

#include "Frame.hpp"
#include <functional>

// switch from Frame a to Frame b when condition is true
struct Transfer
{
	using index = unsigned int;

	index a;
	const bool& condition;
	index b;
};

