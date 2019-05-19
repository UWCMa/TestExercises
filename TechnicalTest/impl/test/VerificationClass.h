#ifndef VerificationClass_hpp
#define VerificationClass_hpp

#include "SocialNetwork.h"
#include "Storyboard.h"
#include <iostream>

class VerificationClass
{
public:    
    VerificationClass(SocialNetwork*);
    VerificationClass(Storyboard*);
    ~VerificationClass();
    //SocialNetwork: test cases
    void test_searchByName(const std::string&, const std::list<User>&   expacted_result);
    void test_searchByAge(const unsigned int, const std::list<User>&    expacted_result);
    void test_searchByHobbie(const std::string&, const std::list<User>& expacted_result);
    void test_deleteUser(const User&);
    //StoryBoard: test cases
    void test_searchByTitle(const std::string&, const std::list<Note>& expacted_result);
    void test_searchByText(const std::string&, const std::list<Note>&  expacted_result);
    void test_searchByTag(const std::string&, const std::list<Note>&   expacted_result);
    void test_deleteNote(Note&);
    
private:
    template<typename T>
    void compare(std::list<T>, std::list<T>);
    
private:
    SocialNetwork* network;
    Storyboard*    storyboard;
};

template<typename T>
void VerificationClass::compare(std::list<T> list_right, std::list<T> list_left)
{
    if(list_right.size() != list_left.size())
    {
        std::cout << " is FAILED" << std::endl;
        return;
    }
    else
    {
        list_right.sort();
        list_left.sort();
        list_right == list_left ? std::cout << " is PASSED" << std::endl
        : std::cout << " is FAILED" << std::endl;
    }
}
#endif
