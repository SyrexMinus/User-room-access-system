#include "Prof.h"

/****************************/
/* class Prof : public User */
/****************************/

// constructor for professor user
Prof::Prof(std::string name, std::string favoriteJoke) : 
	User(YELLOW, name, "Favorite joke: " + favoriteJoke)
{

}

// returns string with user type
std::string Prof::getUserType()
{
	return "Professor";
}

/*****************************/
/* /class Prof : public User */
/*****************************/