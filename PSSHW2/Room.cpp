#include "AccessLevel.h"
#include "Room.h"
#include "User.h"
#include "Lab.h"
#include <set>
#include <string>

/**************/
/* class Room */
/**************/

// room constructor
Room::Room(int roomNumber, AccessLevel accessLevel)
{
	this->roomNumber = roomNumber;
	this->accessLevel = accessLevel;
}

// room constructor with adding 1 user to whiteList
Room::Room(int roomNumber, AccessLevel accessLevel, User user) : Room(roomNumber, accessLevel)
{
	this->grantAccess(user);
}

// add user to white list and delete him from black list
void Room::grantAccess(User user)
{
	this->whiteList.insert(user.name);
	this->blackList.erase(user.name);
}

// delete user from both white and black lists
void Room::clearAccess(User user)
{
	this->whiteList.erase(user.name);
	this->blackList.erase(user.name);
}

// add user to black list and delete him from white list
void Room::banAccess(User user)
{
	this->whiteList.erase(user.name);
	this->blackList.insert(user.name);
}

// return if user has access to the room
bool Room::access(User user)
{
	// check is accessLevel of user satisfies
	if (this->blackList.find(user.name) == this->blackList.end() && (user.accessLevel >= this->accessLevel || this->whiteList.find(user.name) != this->whiteList.end()))
	{
		return true;
	}
	return false;
}

// if room numbers is equal
bool Room::operator==(const Room& room)
{
	return this->roomNumber == room.roomNumber;
}

// if room numbers is not equal
bool Room::operator!=(const Room& room)
{
	return this->roomNumber != room.roomNumber;
}
	
/***************/
/* /class Room */
/***************/