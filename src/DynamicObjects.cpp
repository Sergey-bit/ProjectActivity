#include <DynamicObjects.hpp>


std::string DynamicObjects::toStrData() const
{
	std::string res;

	for (int i = 0; i < chests.size() - 1; i++)
	{
		res += chests[i].toStrData() + ";";
	}

	return res;
}