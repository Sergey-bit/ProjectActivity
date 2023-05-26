#pragma once

#include <map>
#include <StatisticMenu.h>

class Profile
{
private: 
	std::string name;
	std::string rank;
	std::string winsPercentage;
	std::string kills;
	std::string favWeapon;
	std::string KDA;
	std::string matchesPlayed;
	std::string averMatchTime;
public: 
	Profile();
	virtual std::string& getname();
	virtual std::string& getrank();
	virtual std::string& getwinsPercentage();
	virtual std::string& getkills();
	virtual std::string& getfavWeapon();
	virtual std::string& getKDA();
	virtual std::string& getmatchesPlayed();
	virtual std::string& getaverMatchTime();

	virtual void setname(std::string name_);
	virtual void setrank(std::string rank_);
	virtual void setwinsPercentage(std::string winsPercentage_);
	virtual void setkills(std::string kills_);
	virtual void setfavWeapon(std::string favWeapon_);
	virtual void setKDA(std::string KDA_);
	virtual void setmatchesPlayed(std::string matchesPlayed_);
	virtual void setaverMatchTime(std::string averMatchTime_);

};