#pragma once

#include <string>
#include "AccessLevel.h"

// class User represents account for person in Innopolis university
// superclass for all users in the system
class User
{
public:
	AccessLevel accessLevel;		// Level of access to rooms
	std::string name;				// Name of user
	std::string password = "";		// password to account
	std::string extra = "";			// extra info for specific class

	// user constructor
	User(AccessLevel accessLevel, std::string name, std::string extra);

	// user constructor with password
	User(AccessLevel accessLevel, std::string name, std::string extra, std::string password);

	// returns string with user type
	virtual std::string getUserType();

	// check if input password equal to user's password
	bool checkPassword(std::string password);

	// if name and access level are equal
	bool operator==(const User& user);

	// if name and access level are not equal
	bool operator!=(const User& user);
};