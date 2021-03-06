#pragma once

#include "User.h"

class Dir : public User
{
public:
	// constructor for professor user, extra - director's hobby
	Dir(std::string name, std::string hobby);

	// returns string with user type
	std::string getUserType();
};