#include "Admin.h"

/*****************************/
/* class Admin : public User */
/*****************************/

// constructor for admin user
Admin::Admin(std::string name, std::string favoriteEnergyDrink, std::string password) : 
	User(RED, name, "Favorite energy drink: " + favoriteEnergyDrink, password)
{

}

// returns string with user type
std::string Admin::getUserType()
{
	return "Admin";
}

/******************************/
/* /class Admin : public User */
/******************************/