#pragma once

#include "User.h"

class Lab : public User
{
public:
	// constructor for lab user, extra - name of user's lab
	Lab(std::string name, std::string labName);

	// returns string with user type
	std::string getUserType();
};