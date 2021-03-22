#include "ConferenceRoom.h"

/**************************************/
/* class ConferenceRoom : public Room */
/**************************************/

// constructor of room with level of access YELLOW
ConferenceRoom::ConferenceRoom(int roomNumber) : Room(roomNumber, YELLOW)
{
	if (roomNumber >= 100 && roomNumber <= 199)
		this->accessLevel = BLUE;
}

/***************************************/
/* /class ConferenceRoom : public Room */
/***************************************/