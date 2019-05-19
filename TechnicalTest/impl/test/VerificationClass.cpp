#include "VerificationClass.h"
#include <iostream>

VerificationClass::VerificationClass(SocialNetwork* ptr)
: network(ptr)
{
    std::cout << "-----Test SocialNetwork-----" << std::endl;
    storyboard = nullptr;
}

VerificationClass::VerificationClass(Storyboard* ptr)
: storyboard(ptr)
{
    std::cout << "-----Test Storyboard-----" << std::endl;
    network = nullptr;
}

VerificationClass::~VerificationClass()
{
    network =    nullptr;
    storyboard = nullptr;
}

//-------------------------------------SocialNetwork: test cases-------------------------------------

void VerificationClass::test_searchByName(const std::string& name, const std::list<User>& expacted_result)
{
    if(nullptr == network)
        return;
    const auto result = network->searchUserByName(name);
    std::cout << "test_searchByName: " << name;
    compare(result, expacted_result);
}

void VerificationClass::test_searchByAge(const unsigned int age, const std::list<User>& expacted_result)
{
    if(nullptr == network)
        return;
    const auto result = network->searchUserByAge(age);
    std::cout << "test_searchByAge: " << age;
    compare(result, expacted_result);
}

void VerificationClass::test_searchByHobbie(const std::string& hobbie, const std::list<User>& expacted_result)
{
    if(nullptr == network)
        return;
    const auto result = network->searchUserByHobbies(hobbie);
    std::cout << "test_searchByHobbie: " << hobbie;
    compare(result, expacted_result);
}

void VerificationClass::test_deleteUser(const User& user)
{
    if(nullptr == network)
        return;
    network->deleteUser(user);
    false == network->getUserById(user.id).second ? std::cout << "test_deleteUser is PASSED" << std::endl
    : std::cout << "test_deleteUser is FAILED" << std::endl;
}

//-------------------------------------StoryBoard: test cases-------------------------------------

void VerificationClass::test_searchByTitle(const std::string& title, const std::list<Note>& expacted_result)
{
    if(nullptr == storyboard)
        return;
    const auto result = storyboard->searchByTitle(title);
    std::cout << "test_searchByTitle: " << title;
    compare(result, expacted_result);
}

void VerificationClass::test_searchByText(const std::string& text, const std::list<Note>& expacted_result)
{
    if(nullptr == storyboard)
        return;
    const auto result = storyboard->searchByText(text);
    std::cout << "test_searchByText: " << text;
    compare(result, expacted_result);
}

void VerificationClass::test_searchByTag(const std::string& tag, const std::list<Note>& expacted_result)
{
    if(nullptr == storyboard)
        return;
    const auto result = storyboard->searchByTag(tag);
    std::cout << "test_searchByTag: " << tag;
    compare(result, expacted_result);
}

void VerificationClass::test_deleteNote(Note& note)
{
    if(nullptr == storyboard)
        return;
    storyboard->deleteNote(note);
    false == storyboard->isNote(note) ? std::cout << "test_deleteUser is PASSED" << std::endl
    : std::cout << "test_deleteUser is FAILED" << std::endl;
}
