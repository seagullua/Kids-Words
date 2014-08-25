#include "LevelSaves.h"
#include "Collection.h"
#include "CollectionPart.h"
#include "Level.h"
#include "InfoStyles.h"
#include "Alphabete.h"
LevelSaves::LevelSaves()
{
}
const std::vector<Collection>& LevelSaves::getCollections()
{
    return _collections;
}
//const std::vector<Level>& LevelSaves::getLevels(CollectionID coll_id)
//{
//    return _levels;
//}
LevelSaves& LevelSaves::getInstance()
{
    static LevelSaves obj;
    return obj;
}
const Collection* LevelSaves::getCollectionById(CollectionID coll_id)
{
    for(unsigned int i = 0; i < _collections.size(); ++i)
    {
        if (_collections[i].getID() == coll_id)
        {
            return &_collections[i];

        }
    }
    return nullptr;

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
    CollectionPart collect_part_easy;
    CollectionPart collect_part_dificult;
    CollectionPart collect_part_middle;
    collect_part_easy.setImage("collections/c1.png");
    collect_part_dificult.setImage("collections/c2.png");
    collect_part_middle.setImage("collections/c3.png");
    collect.setCollectionPartEasy(collect_part_easy);
    collect.setCollectionPartMiddle(collect_part_middle);
    collect.setCollectionPartDifficult(collect_part_dificult);
    _collections.push_back(collect);
    Collection collect1;
    collect1.setID(2);
    collect1.setColor(InfoStyles::COLOR_BLUE);
    collect1.setImage("collections/c2.png");
    collect1.setName("Food");
    collect1.setCollectionPartEasy(collect_part_dificult);
    collect1.setCollectionPartMiddle(collect_part_middle);
    collect1.setCollectionPartDifficult( collect_part_easy);

    _collections.push_back(collect1);
    Collection collect2;
    collect2.setID(3);
    collect2.setColor(InfoStyles::COLOR_MAGENTA);
    collect2.setImage("collections/c3.png");
    collect2.setName("Family");
    collect2.setCollectionPartEasy(collect_part_easy);
    collect2.setCollectionPartMiddle(collect_part_dificult);
    collect2.setCollectionPartDifficult( collect_part_middle);

    _collections.push_back(collect2);

    Alphabete::getInstance().setApphabete();
    Alphabete::getInstance().setAlphabeteColor();
}
