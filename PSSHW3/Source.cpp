/*
Author: Shevchenko Makar Ilyich
Date: 22.03.2021 23:01
*/

#include <iostream>
#include <string>
#include <set>
#include "AccessLevel.h"
#include "Room.h"
#include "User.h"
#include "ClassRoom.h"
#include "LectureRoom.h"
#include "ConferenceRoom.h"
#include "Cabinet.h"
#include "LabRoom.h"
#include "Student.h"
#include "Lab.h"
#include "Prof.h"
#include "Dir.h"
#include "Admin.h"
#include "SystemInterface.h"
#include "SetSupport.h"
#include "Guest.h"

int main()
{
	// upload database to system interface
	Dir dir1("Kirill_Semenihin", "golf");
	Admin admin1("Alex_Flex", "Monster", "admin");
	Admin admin2("Boris_Bzik", "Red Bull", "nimda");
	Prof prof1("Nikolai_Shilov", "Shel medved po lesu, vidit: mashina gorit. Sel v neyo i sgorel.");
	Prof prof2("Evgeniy_Zuev", "Kolobok povesilsya.");
	Prof prof3("Adil_Khan", "Prihodyat beskonechnoe kolichestvo matematikov v bar. 1-iy prosit 1 pivo, 2-oy - 1/2 piva, 3-iy - 1/4 piva i tak dalee... Barmen nalivaet pivo i govorit: 'Vot vashi 2 piva'.");
	Prof prof4("Djancarlo_Succi", "Popadayut nemec, francuz i russkiy na neobitaemiy ostrov. Nemec govorit: 'Davayte postroim lodku i poplivem domoy.'. Francuz otvechaet, vozmushayas': 'Mi dazhe ne znaem gde kontinent, davayte luchshe dadim signal i budem zhdat' evakuaciyu'. Russkiy smotrit na nih v nedoumenii i vosklicaet: 'Vi otkuda, bl**t russkiy znaete?!'.");
	Lab lab1("Oleg_Bulichev", "robotics");
	Lab lab2("Romzan_Kadirov", "robotics");
	Lab lab3("Vladimir_Putin", "data science");
	Lab lab4("Alla_Pugacheva", "data science");
	Lab lab5("Ratmir_Shishkov", "computer security");
	Lab lab6("Barak_Obama", "computer security");
	Lab lab7("Aleksey_Navalny", "software development");
	Lab lab8("Alexandr_Pushkin", "software development");
	Student student1("Makar_Shevchenko", "36000");
	Student student2("Nikita_Surnachev", "3000");
	Student student3("Slava_Siniy", "18000");
	Student student4("Danil_Davidyan", "12000");
	Student student5("Alexandr_Agafonov", "18000");
	Student student6("Sofia_Maria_Lo_Chichero_Vaina", "12000");
	Student student7("Artem_Batalov", "36000");
	Student student8("Vladimir_Makharenko", "18000");
	Student student9("Artem_Murashko", "15000");
	Student student10("Artem_Chernitsa", "16000");
	Student student11("Iskander_Nafikov", "15000");
	Student student12("Eduard_Zaripov", "15000");
	Student student13("Sergei_Golubev", "18000");
	Student student14("Vsevolod_Kiaver", "16000");
	Student student15("Khabib_Khays", "24000");
	Student student16("Asem_Abdelhady", "24000");
	Guest guest1;

	Cabinet cabinet1(550, dir1);
	Cabinet cabinet2(404, admin1);
	Cabinet cabinet3(405, admin2);
	Cabinet cabinet4(501, prof1);
	Cabinet cabinet5(502, prof2);
	Cabinet cabinet6(503, prof3);
	Cabinet cabinet7(418, prof4);
	LabRoom labRoom1(406, "robotics");
	LabRoom labRoom2(407, "data science");
	LabRoom labRoom3(408, "computer security");
	LabRoom labRoom4(409, "software development");
	ClassRoom classRoom1(318);
	ClassRoom classRoom2(312);
	LectureRoom lectureRoom1(108);
	LectureRoom lectureRoom2(106);
	ConferenceRoom conferenceRoom1(430);
	ConferenceRoom conferenceRoom2(431);
	ConferenceRoom conferenceRoom3(110);

	SystemInterface mainSI;
	std::set<Room*> rooms{ &cabinet1, &cabinet2, &cabinet3, &cabinet4, &cabinet5, 
						   &cabinet6, &cabinet7,
						   &labRoom1, &labRoom2, &labRoom3, &labRoom4,
						   &classRoom1, &classRoom2, 
						   &lectureRoom1, &lectureRoom2,
						   &conferenceRoom1, &conferenceRoom2, &conferenceRoom3 };
	std::set<User*> users{ &dir1, &admin1, &admin2, &prof1, &prof2, &prof3, &prof4,
						   &lab1, &lab2, &lab3, &lab4, &lab5, &lab6, &lab7, &lab8, 
						   &student1, &student2, &student3, &student4, &student5, 
						   &student6, &student7, &student8, &student9, &student10, 
						   &student11, &student12, &student13, &student14, &student15, 
						   &student16, &guest1 };

	// run system interface
	mainSI.startSystemInterface(rooms, users);

	return 0;
}