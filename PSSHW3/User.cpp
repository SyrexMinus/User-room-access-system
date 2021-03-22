#include "AccessLevel.h"
#include "User.h"
#include <string>

/**************/
/* class User */
/**************/

// user constructor
User::User(AccessLevel accessLevel, std::string name, std::string extra)
{
	this->accessLevel = accessLevel;
	this->name = name;
	this->extra = extra;
}

// user constructor with password
User::User(AccessLevel accessLevel, 
		   std::string name, 
		   std::string extra, 
		   std::string password) : User(accessLevel, name, extra)
{
	this->password = password;
}

// check if input password equal to user's password
bool User::checkPassword(std::string password)
{
	if (this->password == password)
		return true;
	return false;
}

// returns string with user type
std::string User::getUserType()
{
	return "User";
}

// if name and access level are equal
bool User::operator==(const User& user)
{
	return this->name == user.name && this->accessLevel == user.accessLevel;
}

// if name and access level are not equal
bool User::operator!=(const User& user)
{
	return this->name != user.name || this->accessLevel != user.accessLevel;
}

/***************/
/* /class User */
/***************/