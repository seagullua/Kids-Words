#include "Level.h"
void Level::setID(LevelID id)
{
    _id = id;
}
void Level::setImage(std::string image)
{
    _level_image = image;
}
const Level::LevelID Level::getID() const
{
    return _id;
}
const std::string Level::getImage() const
{
    return _level_image;
}
