#include "Dir.h"

/***************************/
/* class Dir : public User */
/***************************/

// constructor for director user
Dir::Dir(std::string name, std::string hobby) : 
	User(YELLOW, name, "Hobby: " + hobby)
{

}

// returns string with user type
std::string Dir::getUserType()
{
	return "Director";
}

/****************************/
/* /class Dir : public User */
/****************************/