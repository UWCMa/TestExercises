#include "SocialNetwork.h"

SocialNetwork::SocialNetwork()
: users()
, id(0)
{
}

SocialNetwork::~SocialNetwork()
{
}

void SocialNetwork::addUser(User& user)
{
    user.id = ++id;
    users.addUser(user);
}
void SocialNetwork::deleteUser(const User& user)
{
    users.deleteUser(user);
}
std::list<User> SocialNetwork::searchUserByName(const std::string& name)
{
    return users.searchUserByName(name);
}
std::list<User> SocialNetwork::searchUserByAge(const unsigned int age)
{
    return users.searchUserByAge(age);
}
std::list<User> SocialNetwork::searchUserByHobbies(const std::string& hobbie)
{
    return users.searchUserByHobbies(hobbie);
}

void SocialNetwork::addUserHobbies(const unsigned int id, const std::list<std::string>& list)
{
    users.addUserHobbies(id, list);
}

std::list<User> SocialNetwork::getFriendsOfUser(const User& user)
{
    const auto friends_ids = user.getFriendsOfUser();
    if(friends_ids.empty())
        return std::list<User>();
    std::list<User> users_list;
    users.getUsersbyIdList(friends_ids, users_list);
    return users_list;
}
const std::pair<User, bool> SocialNetwork::getUserById(const unsigned int id)
{
    return users.getUserById(id);
}
