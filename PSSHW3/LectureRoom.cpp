#include "LectureRoom.h"

/***********************************/
/* class LectureRoom : public Room */
/***********************************/

// constructor of room with level of access GREEN
LectureRoom::LectureRoom(int roomNumber) : Room(roomNumber, GREEN)
{
	if (roomNumber >= 100 && roomNumber <= 199)
		this->accessLevel = BLUE;
}

/************************************/
/* /class LectureRoom : public Room */
/************************************/