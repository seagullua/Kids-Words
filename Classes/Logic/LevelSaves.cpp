#include "LevelSaves.h"
#include "Collection.h"
#include "Level.h"
#include "InfoStyles.h"
LevelSaves::LevelSaves()
{
}
const std::vector<Collection>& LevelSaves::getCollections()
{
    return _collections;
}
const std::vector<Level>& LevelSaves::getLevels(CollectionID coll_id)
{
    return _levels;
}
LevelSaves& LevelSaves::getInstance()
{
    static LevelSaves obj;
    return obj;
}

void LevelSaves::readLevels()

{
//    Level level1;
//    level1.setID(1);
//    level1.setImage("collections/c1.png");
//    _levels.push_back(level1);
//    Level level2;
//    level2.setID(2);
//    level2.setImage("collections/c2.png");
//    _levels.push_back(level2);
//    Level level3;
//    level3.setID(3);
//    level3.setImage("collections/c3.png");
//    _levels.push_back(level3);

    Collection collect;
    collect.setID(1);
    collect.setColor(InfoStyles::COLOR_ORANGE);
    collect.setImage("collections/c1.png");
    collect.setName("Animals");
    //collect.setCollectionPartEasy(CollectionPart part)
    _collections.push_back(collect);
    Collection collect1;
    collect1.setID(2);
    collect1.setColor(InfoStyles::COLOR_BLUE);
    collect1.setImage("collections/c2.png");
    collect1.setName("Food");
    _collections.push_back(collect1);
    Collection collect2;
    collect2.setID(3);
    collect2.setColor(InfoStyles::COLOR_MAGENTA);
    collect2.setImage("collections/c3.png");
    collect2.setName("Family");
    _collections.push_back(collect2);


}
