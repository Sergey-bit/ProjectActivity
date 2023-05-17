#include <Profile.hpp>

Profile::Profile() {

}

std::string Profile::getname() {
	return name;
}

std::string Profile::getrank() {
	return rank;
}

std::string Profile::getwinsPercentage() {
	return winsPercentage;
}

std::string Profile::getkills() {
	return kills;
}

std::string Profile::getfavWeapon() {
	return favWeapon;
}

std::string Profile::getKDA() {
	return KDA;
}

std::string Profile::getmatchesPlayed() {
	return matchesPlayed;
}


std::string Profile::getaverMatchTime() {
	return averMatchTime;
}
