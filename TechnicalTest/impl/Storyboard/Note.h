#ifndef Note_hpp
#define Note_hpp

#include <string>
#include <set>

class Note
{
public:
    using set = std::set<std::string>;
    Note(const std::string&, const std::string&, const set&);
    Note(const Note&);
    Note(const Note&&);
    Note();
    ~Note();
    
    void changeTitle( std::string&);
    void changeText( const std::string&);
    void addTag(std::string&);
    void deleteTag( std::string&);
    
    inline const std::string& getTitle();
    inline const std::string& getText();
    inline const set& getTags();
    
    bool operator<(const Note &other) const
    {
        if (title < other.title)
            return true;
        if (title == other.title && text < other.text)
            return true;
        return (title == other.title && text == other.text && tags < other.tags);
    }
    bool operator == (const Note& note) const
    {
        return (title == note.title && text == note.text && tags == note.tags);
    }
private:
    std::string title;
    std::string text;
    set tags;
};

const std::string& Note::getTitle()
{
    return title;
}
const std::string& Note::getText()
{
    return text;
}
const Note::set& Note::getTags()
{
    return tags;
}
#endif
