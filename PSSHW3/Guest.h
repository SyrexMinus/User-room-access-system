#pragma once

#include "User.h"

class Guest : public User
{
public:
	// constructor for student user, extra - scholarship
	Guest();

	// returns string with user type
	std::string getUserType();
};