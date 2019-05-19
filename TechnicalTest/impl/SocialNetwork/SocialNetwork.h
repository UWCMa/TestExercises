#ifndef SocialNetwork_hpp
#define SocialNetwork_hpp

#include "UserCollection.h"

class SocialNetwork
{
public:
    SocialNetwork();
    ~SocialNetwork();
    void addUser(User&);
    void deleteUser(const User&);
    
    std::list<User> searchUserByName(const std::string&);
    std::list<User> searchUserByAge(const unsigned int);
    std::list<User> searchUserByHobbies(const std::string&);
    
    void addUserHobbies(const unsigned int id, const std::list<std::string>&);
    std::list<User> getFriendsOfUser(const User&);
    const std::pair<User, bool> getUserById(const unsigned int);
    
private:
    UserCollection users;
    unsigned int id;
};
#endif
