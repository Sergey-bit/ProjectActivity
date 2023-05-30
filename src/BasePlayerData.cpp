#include <BaseDataPlayer.hpp>

std::string BasePlayerData::toStrData() const
{
	std::string gun = "";
	for (const auto& e : equips)
	{
		if (e >= 3)
		{
			gun = std::to_string(e);
			break;
		}
	}
	return "name:" + name + ";health:" + std::to_string(health) + ";" + rotableObjectPosition::toStrData() +
		";armor:" + std::to_string(isHaveEquipment(Core::Eqiupment::ARMOR1)) +
		((gun.size()) ? (";gun:" + gun) : "");
}
std::string BasePlayerData::getName() const
{
	return name;
}

void BasePlayerData::setName(const std::string& nename)
{
	name = nename;
}
void BasePlayerData::healthMoves(float dx)
{
	health += dx;
}

float BasePlayerData::getHealth() const
{
	return health;
}
bool BasePlayerData::isHaveEquipment(const Core::Eqiupment& ind) const
{
	for (const auto& e: equips)
	{
		if (e == ind)
		{
			return true;
		}
	}
	return false;
}
bool BasePlayerData::isHaveEquipmentAtAll() const
{
	return equips.size() > 0;
}