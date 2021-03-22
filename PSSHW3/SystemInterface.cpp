#include <iostream>
#include "SystemInterface.h"

/*************************/
/* class SystemInterface */
/*************************/

// return pair if in the set there is user with such name and pointer to it
std::pair<bool, User*> SystemInterface::findUser(std::string name, std::set<User*>& users)
{
	User* nullUser;
	std::pair<bool, User*> ans(false, nullUser);
	for (auto& user : users)
		if (user->name == name)
		{
			ans.first = true;
			ans.second = user;
			return ans;
		}
	return ans;
}

// return pair if in the set there is user with such name and pointer to it
std::pair<bool, Room*> SystemInterface::findRoom(int roomNumber, std::set<Room*>& rooms)
{
	Room* nullRoom;
	std::pair<bool, Room*> ans(false, nullRoom);
	for (auto& room : rooms)
		if (room->roomNumber == roomNumber)
		{
			ans.first = true;
			ans.second = room;
			return ans;
		}
	return ans;
}

// convert level of access to string
std::string SystemInterface::levelToString(AccessLevel level)
{
	if (level == BLUE)
		return "Blue";
	if (level == NO_LEVEL)
		return "No level";
	if (level == GREEN)
		return "Green";
	if (level == YELLOW)
		return "Yellow";
	if (level == RED)
		return "Red";
	else
		return "Undefined";
}

// show user info
void SystemInterface::showInfo(User* activeUser, std::set<Room*>& rooms)
{
	std::cout << std::endl;
	std::cout << "Name: " << activeUser->name << std::endl;
	std::cout << "User type: " << activeUser->getUserType() << std::endl;
	std::cout << "Level: " << levelToString(activeUser->accessLevel) << std::endl;
	std::cout << "Rooms avaliable: ";
	for (auto room : rooms)
	{
		if (room->access(*activeUser))
			std::cout << room->roomNumber << " ";
	}
	std::cout << std::endl;
	std::cout << activeUser->extra << std::endl;
}

User* SystemInterface::logIn(std::set<User*>& users)
{
	while (true)
	{
		// initialize input buffer
		std::string input = "";

		// authorize using name
		User* activeUser = &User(NO_LEVEL, "null user", "null extra");
		bool userNameOK = false;
		while (!userNameOK)
		{
			std::cout << std::endl;
			std::cout << "Please enter your name (\"Guest\" if you are guest):" << std::endl << "> ";
			std::getline(std::cin, input);

			// try to find such user
			std::pair<bool, User*> findUserReturn = findUser(input, users);
			userNameOK = findUserReturn.first;
			activeUser = findUserReturn.second;

			// if no such user - error message
			if (!userNameOK)
				std::cout << "Error: User with such name not found. Try again." << std::endl;
		}

		// enter password if user has it
		if (!activeUser->checkPassword(""))
		{
			input = "";
			std::cout << "Please enter your password: ";
			std::getline(std::cin, input);
			if (activeUser->checkPassword(input))
				return activeUser;
			else
			{
				std::cout << "Error: Wrong password. Try again." << std::endl;
				continue;
			}
		}
		return activeUser;
	}
}

void SystemInterface::processCommands(User* activeUser, std::set<Room*>& rooms, std::set<User*>& users)
{
	// initialize input buffer
	std::string input = "";

	while (true)
	{
		std::cout << std::endl;
		std::cout << "Enter command" << std::endl;
		std::cout << "Command list:" << std::endl;
		if (activeUser->getUserType() == "Admin")
		{
			std::cout << "	access [room number]             - try to access room" << std::endl;
			std::cout << "	bana [user name] [room number]   - ban access to room for user" << std::endl;
			std::cout << "	cleara [user name] [room number] - clear special access to room for user" << std::endl;
			std::cout << "	granta [user name] [room number] - grant access to room for user" << std::endl;
			std::cout << "  emergencyon                      - turn on emergency mode" << std::endl;
			std::cout << "  emergencyoff                     - turn off emergency mode" << std::endl;
			std::cout << "	info                             - show info about you" << std::endl;
			std::cout << "	logout                           - exit from your account" << std::endl;
		}
		else
		{
			std::cout << "	access [room number] - try to access room" << std::endl;
			std::cout << "	emergencyon          - turn on emergency mode" << std::endl;
			std::cout << "	emergencyoff         - turn off emergency mode" << std::endl;
			std::cout << "	info                 - show info about you" << std::endl;
			std::cout << "	logout               - exit from your account" << std::endl;
		}
		std::cout << "> ";

		std::getline(std::cin, input);
		std::string command;
		std::istringstream inputLine(input);
		inputLine >> command;

		if (activeUser->getUserType() == "Admin")
		{
			if (command == "access")
			{
				// input room number and try to find it
				int roomNumber;
				inputLine >> roomNumber;
				std::pair<bool, Room*> findRoomReturn = findRoom(roomNumber, rooms);
				bool foundRoom = findRoomReturn.first;
				Room* foundedRoom = findRoomReturn.second;

				// if there is such room, try to access it
				if (foundRoom)
				{
					if (foundedRoom->access(*activeUser))
						std::cout << "Success" << std::endl;
					else
						std::cout << "Error: You have no access to room " << roomNumber << std::endl;
				}
				// if there is no such room - error message
				else
					std::cout << "Error: No room " << roomNumber << ". Try again." << std::endl;
			}
			else if (command == "bana" || command == "cleara" || command == "granta")
			{
				std::string name;
				inputLine >> name;
				// try to find such user
				std::pair<bool, User*> findUserReturn = findUser(name, users);
				bool userNameOK = findUserReturn.first;
				User* foundedUser = findUserReturn.second;
				// if no such user - error message
				if (!userNameOK)
				{
					std::cout << "Error: User with such name not found. Try again." << std::endl;
					continue;
				}

				// input room number and try to find it
				int roomNumber;
				inputLine >> roomNumber;
				std::pair<bool, Room*> findRoomReturn = findRoom(roomNumber, rooms);
				bool foundRoom = findRoomReturn.first;
				Room* foundedRoom = findRoomReturn.second;
				// if there is no such room - error message
				if (!foundRoom)
				{
					std::cout << "Error: No room " << roomNumber << ". Try again." << std::endl;
					continue;
				}

				// success: found user and room
				if (command == "bana")
				{
					foundedRoom->banAccess(*foundedUser);
					std::cout << name << " banned in " << roomNumber << " room." << std::endl;
				}
				else if (command == "cleara")
				{
					foundedRoom->clearAccess(*foundedUser);
					std::cout << name << "'s access was cleared in " << roomNumber << " room." << std::endl;
				}
				else if (command == "granta")
				{
					foundedRoom->grantAccess(*foundedUser);
					std::cout << name << " got access for " << roomNumber << " room." << std::endl;
				}
			}
			else if (command == "emergencyon")
			{
				emergencyMode = true;
				std::cout << "Emergency mode turned on." << std::endl;
			}
			else if (command == "emergencyoff")
			{
				emergencyMode = false;
				std::cout << "Emergency mode turned off." << std::endl;
			}
			else if (command == "info")
			{
				// show user info
				showInfo(activeUser, rooms);
			}
			else if (command == "logout")
			{
				break;
			}
			else
			{
				std::cout << "Error: no such command '" << command << "'. Try again." << std::endl;
			}
		}
		else
		{
			if (command == "access")
			{
				// input room number and try to find it
				int roomNumber;
				inputLine >> roomNumber;
				std::pair<bool, Room*> findRoomReturn = findRoom(roomNumber, rooms);
				bool foundRoom = findRoomReturn.first;
				Room* foundedRoom = findRoomReturn.second;

				// if there is such room, try to access it
				if (foundRoom)
				{
					if (foundedRoom->access(*activeUser))
						std::cout << "Success" << std::endl;
					else
						std::cout << "Error: You have no access to room " << roomNumber << std::endl;
				}
				// if there is no such room - error message
				else
					std::cout << "Error: No room " << roomNumber << ". Try again." << std::endl;
			}
			else if (command == "emergencyon")
			{
				emergencyMode = true;
				std::cout << "Emergency mode turned on." << std::endl;
			}
			else if (command == "emergencyoff")
			{
				emergencyMode = false;
				std::cout << "Emergency mode turned off." << std::endl;
			}
			else if (command == "info")
			{
				// show user info
				showInfo(activeUser, rooms);
			}
			else if (command == "logout")
			{
				break;
			}
			else
			{
				std::cout << "Error: no such command '" << command << "'. Try again." << std::endl;
			}
		}
	}
}

// system interface it should be initialized with sets of rooms and users 
int SystemInterface::startSystemInterface(std::set<Room*>& rooms, std::set<User*>& users)
{
	while (true)
	{

		// authorize user
		User* activeUser = logIn(users);

		// show user info
		showInfo(activeUser, rooms);

		// process user's commands
		processCommands(activeUser, rooms, users);
	}
}

/**************************/
/* /class SystemInterface */
/**************************/