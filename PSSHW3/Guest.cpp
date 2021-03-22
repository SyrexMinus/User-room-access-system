#include "Guest.h"
#include "string"

/*******************************/
/* class Guest : public User */
/*******************************/

// constructor for student user
Guest::Guest() :
	User(BLUE, "Guest", "This account was used by many people...")
{

}

// returns string with user type
std::string Guest::getUserType()
{
	return "Guest";
}
/********************************/
/* /class Guest : public User */
/********************************/