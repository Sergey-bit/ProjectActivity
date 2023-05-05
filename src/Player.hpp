#pragma once

#include <Object.hpp>
#include <iostream>

class Player : virtual public Core::GameObject
{
private:
	std::string name_;

public:
	Player(const std::string& name);
	virtual void setName(const std::string& name);
	virtual std::string getName() const;
	virtual void draw() ;
};

