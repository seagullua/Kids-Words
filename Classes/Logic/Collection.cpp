#include "Collection.h"

Collection::Collection()
{
}
void Collection::setID(CollectionID id)
{
  _id = id;
}
void Collection::setColor(cocos2d::ccColor3B color)
{
   _color = color;
}
void Collection::setName(std::string name)
{
   _name = name;
}
void Collection::setImage(std::string image)
{
   _image = image;
}
void Collection::setLevelNum(int level_num)
{
   _level_num = level_num;
}
void Collection::setLevels(std::vector<Level> levels)
{
    _levels = levels;
}
void Collection::setCollectionPartEasy(CollectionPart part)
{
  _easy = part;
}
void Collection::setCollectionPartMiddle(CollectionPart part)
{
   _middle  = part;
}
void Collection::setCollectionPartDifficult(CollectionPart part)
{
   _difficult = part;
}
