#pragma once

#include <SFML/Graphics.hpp>
#include <type_traits>

template<typename T>
using vec2 = sf::Vector2<T>;

template<typename T>
using vec3 = sf::Vector3<T>;

using vec3i = vec3<int>;
using vec3f = vec3<float>;

using vec2i = vec2<int>;
using vec2f = vec2<float>;

using vec2u = vec2<unsigned int>;
using vec3u = vec3<unsigned int>;

template<typename T>
struct _Trans
{
	using type = T;
};

template<>
struct _Trans<unsigned int>
{
	using type = int;
};

template<>
struct _Trans<float>
{
	using type = int;
};

template<>
struct _Trans<int>
{
	using type = float;
};

template<typename T>
inline vec2<typename _Trans<std::_Remove_cvref_t<T>>::type>&& exchangeIF(const vec2<T>& vec)
{
	return vec2<typename _Trans<std::_Remove_cvref_t<T>>::type>(
		(typename _Trans<std::_Remove_cvref_t<T>>::type)vec.x,
		(typename _Trans<std::_Remove_cvref_t<T>>::type)vec.y
		);
}

template<typename T>
inline vec3<typename _Trans<std::_Remove_cvref_t<T>>::type>&& exchangeIF(const vec3<T>& vec)
{
	return vec3<typename _Trans<std::_Remove_cvref_t<T>>::type>(
		(typename _Trans<std::_Remove_cvref_t<T>>::type)vec.x,
		(typename _Trans<std::_Remove_cvref_t<T>>::type)vec.y,
		(typename _Trans<std::_Remove_cvref_t<T>>::type)vec.z
		);
}

template<typename T>
vec2<T> operator*(const vec2<T>& vec1, const vec2<T>& vec2)
{
	return vec2f(vec1.x * vec2.x, vec1.y * vec2.y);
}

template<typename T>
vec2f operator/(const vec2<T>& vec1, const vec2<T>& vec2)
{
	return vec2f(vec1.x / vec2.x, vec1.y / vec2.y);
}