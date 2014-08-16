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
const std::vector<Level> LevelSaves::getLevels(CollectionID coll_id)
{
    return _levels;
}
void LevelSaves::readLevels()

{
    Collection collect;
       collect.setID(1);
       collect.setColor(InfoStyles::COLOR_ORANGE);
       collect.
       collect.

       collect.setName("Animals");
    //    _collections.push_back();
}
