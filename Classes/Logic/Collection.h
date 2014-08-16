#ifndef COLLECTION_H
#define COLLECTION_H
#include "cocos2d.h"
#include "Level.h"
#include "CollectionPart.h"
#include <vector>
#include <string>
typedef unsigned int CollectionID;
class Collection
{
public:
    Collection();
    void setID(CollectionID id);
    void setColor(cocos2d::ccColor3B color);
    void setName(std::string name);
    void setImage(std::string image);
    void setLevelNum(int level_num);
    void setLevels(std::vector<Level> levels);
    void setCollectionPartEasy(CollectionPart part);
    void setCollectionPartMiddle(CollectionPart part);
    void setCollectionPartDifficult(CollectionPart part);

private:
    CollectionID _id;
    cocos2d::ccColor3B _color;
    std::string _name;
    std::string _image;
    int _level_num;
    std::vector<Level> _levels;
    CollectionPart _easy;
    CollectionPart _middle;
    CollectionPart _difficult;

};

#endif // COLLECTION_H
