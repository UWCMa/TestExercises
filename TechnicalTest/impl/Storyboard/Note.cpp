#include "Note.h"

Note::Note(const std::string& _title, const std::string& _text, const set& _tags)
: title(_title)
, text(_text)
, tags(_tags)
{
}

Note::Note(const Note& note)
: title(std::move(note.title))
, text(std::move(note.text))
, tags(std::move(note.tags))
{
}

Note::Note(const Note&& note)
: title(std::move(note.title))
, text(std::move(note.text))
, tags(std::move(note.tags))
{
}

Note::Note()
{
}

Note::~Note()
{
}

void Note::changeTitle( std::string& _title)
{
    title = _title;
}

void Note::changeText( const std::string& _text)
{
    text = _text;
}

void Note::addTag(std::string& _tag)
{
    if(!_tag.empty())
        tags.emplace(_tag);
}

void Note::deleteTag( std::string& _tag)
{
    tags.erase(_tag);
}
