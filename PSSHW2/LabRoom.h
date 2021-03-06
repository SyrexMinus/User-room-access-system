#pragma once

#include "Room.h"
#include "Lab.h"

class LabRoom : public Room
{
public:
	std::string labName;

	// lab room constructor
	LabRoom(int roomNumber, std::string labName);
	// specific access method for lab users
	bool access(User user);
};