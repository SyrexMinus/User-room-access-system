#pragma once

#include "User.h"

class Prof : public User
{
public:
	// constructor for professor user, extra - favorite professor's joke
	Prof(std::string name, std::string favoriteJoke);

	// returns string with user type
	std::string getUserType();
};
