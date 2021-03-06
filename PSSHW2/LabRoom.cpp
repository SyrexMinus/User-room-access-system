#include "LabRoom.h"

/*******************************/
/* class LabRoom : public Room */
/*******************************/

// lab room constructor
LabRoom::LabRoom(int roomNumber, std::string labName) : Room(roomNumber, RED)
{
	this->labName = labName;
}

// specific access method for lab users
bool LabRoom::access(User user)
{
	if (this->blackList.find(user.name) == this->blackList.end() &&
		(user.extra == "Lab name: " + this->labName ||
			user.accessLevel >= this->accessLevel ||
			this->whiteList.find(user.name) != this->whiteList.end()))
		return true;
	return false;
}

/********************************/
/* /class LabRoom : public Room */
/********************************/