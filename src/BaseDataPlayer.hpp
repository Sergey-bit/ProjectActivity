#pragma 

#include <Vector.hpp>
#include <Widget.hpp>
#include <string>
#include <vector>
#include <Position.hpp>

struct BasePlayerData : virtual public rotableObjectPosition
{
protected:
	std::vector<Core::Eqiupment> equips;
	std::string name;
	float health;

public:
	std::string toStrData() const;
	std::string getName() const;

	void setName(const std::string& nename);
	void healthMoves(float dx);

	float getHealth() const;
	bool isHaveEquipment(const Core::Eqiupment& ind) const;
	bool isHaveEquipmentAtAll() const;
};