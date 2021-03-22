#pragma once

#include "User.h"

class Student : public User
{
public:

	// constructor for student user, extra - scholarship
	Student(std::string name, std::string scholarship);

	// returns string with user type
	std::string getUserType();
};