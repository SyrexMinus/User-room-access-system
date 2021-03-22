# University access system
Project implements access system between users and rooms on C++ programming language.

Homework Solution 3 on the Introduction to programming 2 course at Innopolis University.

![](https://habrastorage.org/webt/vr/eu/xf/vreuxfpnqxpnoib8k0g6rvtbluy.png)
Example of program work.

## Usage

### Instruction
1. Clone repo.
2. Install Visual Studio 2019 (VS).
3. Open *PSSHW3/PSSHW2.sln* using VS.
4. In VS press *Local Windows Debugger* button (or *f5* hotkey). The program starts running. The console will open.
5. The program will ask you to enter a username. Enter one of the existing names in the system.
   1. If you tried to log in through the admin, you will need to enter the password for his account.
6. Enter any of the suggested commands.

### For testing guest account, blue level, emergency
1. Run the program
2. Login as Guest — enter comand `Guest`
3. Check your access level — *Blue*
4. Check in *Rooms avaliable* list that lecture and conference rooms of 1st floor avaliable (for example, 108), 
they have blue access level. But same types of rooms of other floors are unavalible (for example, 430).
5. Turn on emergency — enter command `emergencyon`.
6. Check that now all rooms become avaliable — enter command `info`.
7. Turn off emergency — enter command `emergencyoff`.
8. Check that now you have access for only *blue* access level rooms — enter command `info`.

### How to change rooms and users database
In *PSSHW3/source.cpp* change the contents of sets rooms and users: add / remove / modify instances of rooms and users.

## Implemented functionality
- Access levels for both rooms and users
- Different classes for each type of room and user using OOP
- System of white and black lists for rooms
- User interface class to process with accounts and commands

## Commands

After authorization the user can enter commands for interacting with the system.

### Commands list:

For all users:
- `access [room number]` — try to access room.
- `emergencyon` — turn on emergency mode.
- `emergencyoff` — turn off emergency mode.
- `info` — show info about you.
- `logout` — exit from your account.

Additional commands for admins:
- `bana [user name] [room number]` — ban access to room for user.
- `cleara [user name] [room number]` — clear special access to room for user.
- `granta [user name] [room number]` - grant access to room for user.

## Hierarchy of access levels
In the system there is several access levels which have both rooms and users.

If user has *level of access* greater or equal to *access level* of room, then he can enter this room (of course, if he is not banned there).
If the user is in room's *whiteList*, then he can access it unconditionally. Note that user cannot be in both *black and white lists*.

### Table of access levels in increasing order.

| Level | Rooms | Users |
| - | - | - |
| BLUE | Lecture room and Conference room of 1st floor | Guest |
| NO_LEVEL | Class room | Student |
| GREEN | Lecture room | Lab employee |
| YELLOW | Conference room | Professor, Director |
| RED | Cabinet, Lab cabinet | Admin |

## Classes of Rooms

### In the system implemented following classes of rooms:
- `Room` — superclass for all types of rooms. It has parameters: `roomNumber`, `accessLevel`, `whiteList`, `blackList`. Also it adds global variable `bool emergencyMode` which, when true, allows any user access any room.
   - Constructor: `Room(int roomNumber, AccessLevel accessLevel, +(User user));`
   - Methods:
      - `void grantAccess(User user);` — add user to white list and delete him from black list.
      - `void clearAccess(User user);` — delete user from both white and black lists.
      - `void banAccess(User user);` — add user to black list and delete him from white list.
      - `virtual bool access(User user);` — return if user has access to the room.
- `ClassRoom` — room of `NO_LEVEL` access level. By default, it can be accessed by any user.
   - Constructor: `ClassRoom(int roomNumber);`
- `LectureRoom` — room of `GREEN` access level (`BLUE` if room on the 1st floor, i.e. room number is between 100 and 199). By default, it can be accessed by lab employees, professors, directors and admins.
   - Constructor: `LectureRoom(int roomNumber);`
- `ConferenceRoom` — room of `YELLOW` access level (`BLUE` if room on the 1st floor, i.e. room number is between 100 and 199). By default, it can be accessed by professors, directors and admins.
   - Constructor: `ConferenceRoom(int roomNumber);`
- `Cabinet` — room of `RED` access level. By default, it can be accessed by only one user, for example, professor or director, and admins.
   - Constructor: `Cabinet(int roomNumber, User user);`
- `Lab cabinet` — room of `RED` access level. By default, it can be accessed by only lab employees of it's lab and admins. 
   - Constructor: `LabRoom(int roomNumber, std::string labName);`

## Classes of Users

### In the system implemented following classes of users:
- `User` — superclass for all types of users. It has parameters: `accessLevel`, `name`, `password`, `extra`.
   - Constructor: `User(AccessLevel accessLevel, std::string name, std::string extra, +(std::string password));`
   - Methods:
      - `virtual std::string getUserType();` — returns string with user type.
      - `bool checkPassword(std::string password);` — check if input password equal to user's password.
   - Constructor: `Admin(std::string name, std::string favoriteEnergyDrink, std::string password);`
- `Guest` — user of `BLUE` access level. Represents guest. Its `extra` parameter is misterious message: *This account was used by many people...*.
   - Constructor: `Guest();`
- `Student` — user of `NO_LEVEL` access level. Represents student. Its `extra` parameter is *scholarship*.
   - Constructor: `Student(std::string name, std::string scholarship);`
- `Lab` — user of `GREEN` access level. Represents lab employee. Its `extra` parameter is *lab name*.
   - Constructor: `Lab(std::string name, std::string labName);`
- `Prof` — user of `YELLOW` access level. Represents professor. Its `extra` parameter is *favorite joke*.
   - Constructor: `Prof(std::string name, std::string favoriteJoke);`
- `Dir` — user of `YELLOW` access level. Represents director. Its `extra` parameter is *hobby*.
   - Constructor: `Dir(std::string name, std::string hobby);`
- `Admin` — user of `RED` access level. Represents system admin. Its `extra` parameter is *favorite energy drink*.

## class SystemInterface

This class was implemented for interacting with the system via console. It interacts with inserted database: `rooms`, `users`.

### Methods:
- `std::pair<bool, User*> findUser(std::string name, std::set<User*>& users);` — return pair if in the set there is user with such name and pointer to it.
- `std::pair<bool, Room*> findRoom(int roomNumber, std::set<Room*>& rooms);` — return pair if in the set there is user with such name and pointer to it.
- `std::string levelToString(AccessLevel level);` — convert level of access to string.
- `void showInfo(User* activeUser, std::set<Room*>& rooms);` — show user info.
- `User* logIn(std::set<User*>& users);` — log in some account in database.
- `void processCommands(User* activeUser, std::set<Room*>& rooms, std::set<User*>& users);` — start processing commands on behalf of the authorized user.
- `int startSystemInterface(std::set<Room*>& rooms, std::set<User*>& users);` — system interface it should be initialized with sets of rooms and users.