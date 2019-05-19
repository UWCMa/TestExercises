#ifndef User_hpp
#define User_hpp

#include <string>
#include <list>

struct User
{
    User(std::string, unsigned int = 0, float = 0.0);
    User(){};
    ~User(){};
    User(const User&);
    User(User&&);
    
    void setFriendsOfUser(const User&);
    std::list<unsigned int> getFriendsOfUser() const;
    void setUserId(const unsigned int);
    void setHobbies(const std::list<std::string>&);

	std::string             name;
	unsigned int            age;
	float                   height;
	std::list<std::string>  hobbies;
	std::list<unsigned int> friends;
    unsigned int            id;
    
	friend bool operator<(const User& lft, const User& rht)
	{
		return lft.id < rht.id;
	};
    bool operator == (const User& user) const
    {
        return (id == user.id && name == user.name && age == user.age
        && height == user.height && hobbies == user.hobbies && friends == user.friends);
    }
};
#endif
