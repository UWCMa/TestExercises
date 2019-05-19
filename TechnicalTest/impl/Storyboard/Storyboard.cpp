#include "Storyboard.h"

Storyboard::Storyboard()
{
}

Storyboard::~Storyboard()
{
}

void Storyboard::addNote(Note& note)
{
    notes.emplace_back(note);
}

void Storyboard::deleteNote(Note& note)
{
    notes.remove(note);
}

Storyboard::list Storyboard::searchByTitle(const std::string& title)
{
    list result;
    std::for_each(notes.begin(), notes.end(),[&](auto it)
                  { if(title == it.getTitle())result.emplace_back(it);});
    return result;
}

Storyboard::list Storyboard::searchByText(const std::string& text)
{
    list result;
    std::for_each(notes.begin(), notes.end(),[&](auto it)
                  { if(text == it.getText()) result.emplace_back(it); });
    return result;
}

Storyboard::list Storyboard::searchByTag(const std::string& tag)
{
    list result;
    std::for_each(notes.begin(), notes.end(),[&](auto it)
                  {
                      const auto& found = it.getTags().find(tag);
                      if(found != it.getTags().end())
                          if(tag == *found)
                              result.emplace_back(it);
                  });
    return result;
}

bool Storyboard::isNote(const Note& note)
{
    bool result = false;
    auto it = std::find(notes.begin(), notes.end(), note);
    if(it != notes.end())
        result = true;
    return result;
}
