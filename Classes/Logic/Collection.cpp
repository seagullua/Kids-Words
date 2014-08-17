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

const CollectionID Collection::getID() const
{
    return _id;
}
const std::string Collection::getImage() const
{
    return _image;
}
const cocos2d::ccColor3B Collection::getColor() const
{
      return _color;
}
const std::string Collection::getName() const
{
    return _name;
}

const CollectionPart Collection::getCollectionPartEasy() const
{
return _easy;

}
const CollectionPart Collection::getCollectionPartMiddle() const
{
    return _middle;

}

const CollectionPart Collection::getCollectionPartDifficult() const
{
    return _difficult;

}
