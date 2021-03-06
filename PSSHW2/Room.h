#pragma once

#include "AccessLevel.h"
#include "User.h"
#include <set>
#include <string>

class Room
{
public:
	int roomNumber;				// number of room
	AccessLevel accessLevel;	// minimal level of access to open
	std::set<std::string> whiteList;		// users who have unconditional access
	std::set<std::string> blackList;		// banned users for this room

	// room constructor
	Room(int roomNumber, AccessLevel accessLevel);

	// room constructor with adding 1 user to whiteList
	Room(int roomNumber, AccessLevel accessLevel, User user);

	// add user to white list and delete him from black list
	void grantAccess(User user);

	// delete user from both white and black lists
	void clearAccess(User user);

	// add user to black list and delete him from white list
	void banAccess(User user);

	// return if user has access to the room
	virtual bool access(User user);

	// if room numbers is equal
	bool operator==(const Room& room);

	// if room numbers is not equal
	bool operator!=(const Room& room);
};