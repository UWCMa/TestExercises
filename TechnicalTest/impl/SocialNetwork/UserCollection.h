#ifndef HashCollection_hpp
#define HashCollection_hpp

#include "User.h"
#include <unordered_map>

class UserCollection
{
public:

    UserCollection();
    ~UserCollection();

	void addUser(const User&);
    void addUserHobbies(const unsigned int id, const std::list<std::string>&);
	void deleteUser(const User&);
    
    std::list<User> searchUserByName(const std::string&);
	std::list<User> searchUserByAge(const unsigned int);
	std::list<User> searchUserByHobbies(const std::string&);
    
    void getUsersbyIdList(const std::list<unsigned int> &, std::list<User>&);
    const std::pair<User, bool> getUserById(const unsigned int);
    
private:

	std::unordered_map     <unsigned int, User>         users;
	std::unordered_multimap<std::string,  unsigned int> names;
	std::unordered_multimap<unsigned int, unsigned int> ages;
	std::unordered_multimap<std::string,  unsigned int> hobbies;
    
    template<typename T>
    void fillUsersList(std::list<User>&, T&);
    template<typename T, typename C>
    void deleteFromSearchingList(const User&, T&, C&);
};

template<typename T>
void UserCollection::fillUsersList(std::list<User>& list, T& range)
{
    std::for_each(range.first, range.second, [&](auto it)
                  { list.emplace_front(users[it.second]); });
}

template<typename T, typename C>
void UserCollection::deleteFromSearchingList(const User& user, T& range, C& container)
{
    if(range.second == container.end())
        return;
    auto result_it = std::find_if(range.first, range.second, [&](auto it)
                                  { return it.second == user.id;});
    if(result_it != range.second)
        container.erase(result_it);
    else
        if(result_it->second == user.id)
            container.erase(result_it);
}
#endif
