#pragma once

#include "Room.h"
#include "User.h"

bool operator<(const Room& room1, const Room& room2)
{
	return room1.roomNumber < room2.roomNumber;
}

bool operator<(const User& user1, const User& user2)
{
	return user1.name < user2.name;
}