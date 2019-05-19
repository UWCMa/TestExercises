#ifndef Storyboard_hpp
#define Storyboard_hpp

#include "Note.h"
#include <list>

class Storyboard
{
public:
    Storyboard();
    ~Storyboard();
    
    using list = std::list<Note>;
    void addNote(Note&);
    void deleteNote(Note&);
    list searchByTitle(const std::string&);
    list searchByText(const std::string&);
    list searchByTag(const std::string&);
    bool isNote(const Note&);
    
private:
    list notes;
};
#endif
