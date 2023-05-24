#include <Profile.hpp>

Profile::Profile() {

}

std::string& Profile::getname() {
	return name;
}

std::string& Profile::getrank() {
	return rank;
}

std::string& Profile::getwinsPercentage() {
	return winsPercentage;
}

std::string& Profile::getkills() {
	return kills;
}

std::string& Profile::getfavWeapon() {
	return favWeapon;
}

std::string& Profile::getKDA() {
	return KDA;
}

std::string& Profile::getmatchesPlayed() {
	return matchesPlayed;
}


std::string& Profile::getaverMatchTime() {
	return averMatchTime;
}

void Profile::setname(std::string name_) {
	name = name_;
}

void Profile::setrank(std::string rank_) {
	rank = rank_;
}

void Profile::setwinsPercentage(std::string winsPercentage_) {
	winsPercentage = winsPercentage_;
}

void Profile::setkills(std::string kills_) {
	kills = kills_;
}

void Profile::setfavWeapon(std::string favWeapon_) {
	favWeapon = favWeapon_;
}

void Profile::setKDA(std::string KDA_) {
	KDA = KDA_;
}

void Profile::setmatchesPlayed(std::string matchesPlayed_) {
	matchesPlayed = matchesPlayed_;
}

void Profile::setaverMatchTime(std::string averMatchTime_) {
	averMatchTime = averMatchTime_;
}