#pragma once

#include "Room.h"

class Cabinet : public Room
{
public:
	// cabinet constructor with adding 1 user to whiteList
	Cabinet(int roomNumber, User user);
};