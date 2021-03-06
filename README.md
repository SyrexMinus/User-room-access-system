# University access system
Project implements access system between users and rooms on C++ programming language.

Homework Solution 2 on the Introduction to programming 2 course at Innopolis University.

![](https://habrastorage.org/webt/jk/sm/9x/jksm9x__s0on-xbxmlaf-ovwzmo.png)

Example of program work.

## Usage

### Instruction
1. Clone repo.
2. Install Visual Studio 2019 (VS).
3. Open *PSSHW2/PSSHW2.sln* using VS.
4. In VS press *Local Windows Debugger* button (or *f5* hotkey). The program starts running. The console will open.
5. The program will ask you to enter a username. Enter one of the existing names in the system.
   1. If you tried to log in through the admin, you will need to enter the password for his account.
6. Enter any of the suggested commands.

### How to change rooms and users database
In *PSSHW2/source.cpp* change the contents of sets rooms and users: add / remove / modify instances of rooms and users.

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
| NO_LEVEL | Class room | Student |
| GREEN | Lecture room | Lab employee |
| YELLOW | Conference room | Professor, Director |
| RED | Cabinet, Lab cabinet | Admin |

## Classes of Rooms

### In the system implemented following classes of rooms:
- `Room` — superclass for all types of rooms. It has parameters: `roomNumber`, `accessLevel`, `whiteList`, `blackList`.
   - Constructor: `Room(int roomNumber, AccessLevel accessLevel, +(User user));`
   - Methods:
      - `void grantAccess(User user);` — add user to white list and delete him from black list.
      - `void clearAccess(User user);` — delete user from both white and black lists.
      - `void banAccess(User user);` — add user to black list and delete him from white list.
      - `virtual bool access(User user);` — return if user has access to the room.
- `ClassRoom` — room of `NO_LEVEL` access level. By default, it can be accessed by any user.
   - Constructor: `ClassRoom(int roomNumber);`
- `LectureRoom` — room of `GREEN` access level. By default, it can be accessed by lab employees, professors, directors and admins.
   - Constructor: `LectureRoom(int roomNumber);`
- `ConferenceRoom` — room of `YELLOW` access level. By default, it can be accessed by professors, directors and admins.
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
- `Student` — user of `NO_LEVEL` access level. Represents student. Its `extra` parameter is *scholarship*.
   - Constructor: `Student(std::string name, std::string scholarship);`
- `Lab` — user of `GREEN` access level. Represents lab employee. Its `extra` parameter is *lab name*.
   - Constructor: `Lab(std::string name, std::string labName);`
- `Prof` — user of `YELLOW` access level. Represents professor. Its `extra` parameter is *favorite joke*.
   - Constructor: `Prof(std::string name, std::string favoriteJoke);`
- `Dir` — user of `YELLOW` access level. Represents director. Its `extra` parameter is *hobby*.
   - Constructor: `Dir(std::string name, std::string hobby);`
- `Admin` — user of `RED` access level. Represents system admin. Its `extra` parameter is *favorite energy drink*.
   - Constructor: `Admin(std::string name, std::string favoriteEnergyDrink, std::string password);`

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
