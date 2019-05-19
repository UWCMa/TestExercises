#include"UserCollection.h"
#include <algorithm>

UserCollection::UserCollection()
{
}

UserCollection::~UserCollection()
{
}

void UserCollection::addUser(const User& user)
{
    auto result = users.emplace(std::make_pair(user.id, user));
    if(false == result.second)
        return;
    names.  emplace(std::make_pair(user.name, user.id));
	ages.   emplace(std::make_pair(user.age, user.id));
	std::for_each(user.hobbies.begin(), user.hobbies.end(), 
		[=](std::string hobbie) { hobbies.emplace(std::make_pair(hobbie, user.id)); });
}

void UserCollection::deleteUser(const User& user)
{
    auto range_names = names.equal_range(user.name);
    deleteFromSearchingList(user, range_names, names);
    auto range_ages = ages.equal_range(user.age);
    deleteFromSearchingList(user, range_ages, ages);
    for(const auto& hobbie: user.hobbies)
    {
        auto range_hobbies = hobbies.equal_range(hobbie);
        deleteFromSearchingList(user, range_hobbies, hobbies);
    }
     users.erase(user.id);
}

std::list<User> UserCollection::searchUserByName(const std::string& name)
{
    auto range = names.equal_range(name);
    std::list<User> users_list;
    fillUsersList(users_list, range);
    return users_list;
}

std::list<User> UserCollection::searchUserByAge(const unsigned int age)
{
    auto range = ages.equal_range(age);
    std::list<User> users_list;
    fillUsersList(users_list, range);
    return users_list;
}
std::list<User> UserCollection::searchUserByHobbies(const std::string& hobbie)
{
    auto range = hobbies.equal_range(hobbie);
    std::list<User> users_list;
    fillUsersList(users_list, range);
    return users_list;
}

void UserCollection::getUsersbyIdList(const std::list<unsigned int> & ids, std::list<User> & list)
{
    for(auto id: ids)
        if(users.count(id))
            list.emplace_back(users[id]);
}

const std::pair<User, bool> UserCollection::getUserById(const unsigned int id)
{
    User foundUser;
    if(users.count(id))
        return std::pair<User, bool>(users[id], true);
    else
        return std::pair<User, bool>(User(), false);
}

void UserCollection::addUserHobbies(const unsigned int id, const std::list<std::string>& list)
{
    if(!users.count(id))
        return;
    users[id].setHobbies(list);
}
