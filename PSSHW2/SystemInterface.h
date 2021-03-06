#pragma once

#include "User.h"
#include "Room.h"
#include <sstream>

// class for working with end user
class SystemInterface
{
public:
	// return pair if in the set there is user with such name and pointer to it
	std::pair<bool, User*> findUser(std::string name, std::set<User*>& users);

	// return pair if in the set there is user with such name and pointer to it
	std::pair<bool, Room*> findRoom(int roomNumber, std::set<Room*>& rooms);

	// convert level of access to string
	std::string levelToString(AccessLevel level);

	// show user info
	void showInfo(User* activeUser, std::set<Room*>& rooms);

	// log in some account in database
	User* logIn(std::set<User*>& users);

	// start processing commands on behalf of the authorized user
	void processCommands(User* activeUser, std::set<Room*>& rooms, std::set<User*>& users);

	// system interface it should be initialized with sets of rooms and users 
	int startSystemInterface(std::set<Room*>& rooms, std::set<User*>& users);
};