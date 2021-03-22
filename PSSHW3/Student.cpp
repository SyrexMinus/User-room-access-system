#include "Student.h"

/*******************************/
/* class Student : public User */
/*******************************/

// constructor for student user
Student::Student(std::string name, std::string scholarship) : 
	User(NO_LEVEL, name, "Sholarship: " + scholarship)
{

}

// returns string with user type
std::string Student::getUserType()
{
	return "Student";
}

/********************************/
/* /class Student : public User */
/********************************/