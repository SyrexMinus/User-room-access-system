#pragma once

#include "Room.h"

class ConferenceRoom : public Room
{
public:
	// constructor of room with level of access YELLOW
	ConferenceRoom(int roomNumber);
};