#include "User.h"
#include <iostream>

User::User(std::string _name, unsigned int _age, float _height)
: name(_name)
, age(_age)
, height(_height)
, hobbies()
, friends()
{
    if(_name.empty())
    {
        std::cout << "Error: name is empty!" << std::endl;
        _name = "Default name";
    }

    if(0 == age || 150 < age)
    {
        std::cout << "Error: Incorret age!" << std::endl;
        age = 0;
    }
    if(0 >= _height || 3 <_height)
    {
        std::cout << "Error: Incorret height!" << std::endl;
        _height = 0;
    }
};

User::User(const User& user)
: name(std::move(user.name))
, age(user.age)
, height(user.height)
, hobbies(user.hobbies)
, friends(user.friends)
, id(user.id)
{
}

User::User(User&& user)
: name(std::move(user.name))
, age(user.age)
, height(user.height)
, hobbies(user.hobbies)
, friends(user.friends)
, id(user.id)
{
}

void User::setFriendsOfUser(const User& user)
{
    friends.emplace_back(user.id);
}
std::list<unsigned int> User::getFriendsOfUser() const
{
    return friends;
}

void User::setUserId(const unsigned int _id)
{
    id = _id;
}

void User::setHobbies(const std::list<std::string>& list)
{
    hobbies = list;
}
