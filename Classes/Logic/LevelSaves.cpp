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
       collect.setImage("collections/c1.png");
       collect.setName("Animals");
      _collections.push_back(collect);
      Collection collect1;
         collect1.setID(2);
         collect1.setColor(InfoStyles::COLOR_BLUE);
         collect1.setImage("collections/c2.png");
         collect1.setName("Food");
        _collections.push_back(collect1);
      Collection collect2;
         collect1.setID(3);
         collect1.setColor(InfoStyles::COLOR_MAGENTA);
         collect1.setImage("collections/c3.png");
         collect1.setName("Family");
        _collections.push_back(collect2);
}
