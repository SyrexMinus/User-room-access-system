#include "Lab.h"

/***************************/
/* class Lab : public User */
/***************************/

// constructor for lab user
Lab::Lab(std::string name, std::string labName) : 
	User(GREEN, name, "Lab name: " + labName)
{

}

// returns string with user type
std::string Lab::getUserType()
{
	return "Lab employee";
}

/****************************/
/* /class Lab : public User */
/****************************/