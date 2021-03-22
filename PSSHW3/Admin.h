#pragma once

#include "User.h"

class Admin : public User
{
public:
	// constructor for admin user, extra - name of favorite admin's drink
	Admin(std::string name, std::string favoriteEnergyDrink, std::string password);

	// returns string with user type
	std::string getUserType();
};
