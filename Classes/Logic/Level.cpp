#include "Level.h"
Level::Level()
{

}

void Level::setID(LevelID id)
{
    _id = id;
}
void Level::setImage(std::string image)
{
    _level_image = image;
}
const LevelID Level::getID()  const
{
    return _id;
}
const std::string Level::getImage() const
{
    return _level_image;
}
void Level::setWord(Word word)
{
    _word = word;
}

void Level::setTranslation(std::string translation)
{
    _translation = translation ;
}
const Word Level::getWord() const
{
    return _word;
}
const std::string Level::getTranslation() const
{
    return _translation;
}

const std::string Level::getLevelImage() const
{
    return _level_image;
}
