#include "LevelSaves.h"
#include "Collection.h"
#include "CollectionPart.h"
#include "Level.h"
#include "Word.h"
#include "InfoStyles.h"
#include "Alphabete.h"
using namespace cocos2d;

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
std::vector<Level> levels;
for (int i = 0 ; i<20; ++i)
{


Level current_level;
current_level.setID(i);
if (i == 0)
{
    current_level.setImage("collections/animals/tiger.jpg");
    Word word("TIGER");
    current_level.setWord(word);
    current_level.setTranslation("тигр");
}
else if (i == 1)
{
    current_level.setImage("collections/animals/bear.jpg");
    Word word("BEAR");
    current_level.setWord(word);
  //  current_level.setTranslation("ведмідь");
    current_level.setTranslation("BEAR");

}
else if (i == 2)
{
    current_level.setImage("collections/animals/cat.jpg");
    Word word("CAT");
    current_level.setWord(word);
    current_level.setTranslation("CAT");
}
else if (i == 3)
{
    current_level.setImage("collections/animals/chinchilla.jpg");
    Word word("CHINCHILLA");
    current_level.setWord(word);
    current_level.setTranslation("CHINCHILLA");
}
else if (i == 4)
{
    current_level.setImage("collections/animals/cow.jpg");
    Word word("COW");
    current_level.setWord(word);
    current_level.setTranslation("COW");
}
else if (i == 5)
{
    current_level.setImage("collections/animals/dog.jpg");
    Word word("DOG");
    current_level.setWord(word);
    current_level.setTranslation("DOG");
}
else if (i == 6)
{
    current_level.setImage("collections/animals/elephant.jpg");
    Word word("ELEPHANT");
    current_level.setWord(word);
    current_level.setTranslation("ELEPHANT");
}
else if (i == 7)
{
    current_level.setImage("collections/animals/fox.jpg");
    Word word("FOX");
    current_level.setWord(word);
    current_level.setTranslation("FOX");
}
else if (i == 8)
{
    current_level.setImage("collections/animals/frog.jpg");
    Word word("FROG");
    current_level.setWord(word);
    current_level.setTranslation("FROG");
}
else if (i == 9)
{
    current_level.setImage("collections/animals/lion.jpg");
    Word word("LION");
    current_level.setWord(word);
    current_level.setTranslation("LION");
}
else if (i == 10)
{
    current_level.setImage("collections/animals/monkey.jpg");
    Word word("MONKEY");
    current_level.setWord(word);
    current_level.setTranslation("MONKEY");
}

else if (i == 11)
{
    current_level.setImage("collections/animals/owl.jpg");
    Word word("OWL");
    current_level.setWord(word);
    current_level.setTranslation("OWL");
}
else if (i == 12)
{
    current_level.setImage("collections/animals/parrot.jpg");
    Word word("PARROT");
    current_level.setWord(word);
    current_level.setTranslation("PARROT");
}
else if (i == 13)
{
    current_level.setImage("collections/animals/penguin.jpg");
    Word word("PENGUIN");
    current_level.setWord(word);
    current_level.setTranslation("PENGUIN");
}
else if (i == 14)
{
    current_level.setImage("collections/animals/rabbit.jpg");
    Word word("RABBIT");
    current_level.setWord(word);
    current_level.setTranslation("RABBIT");
}
else if (i == 15)
{
    current_level.setImage("collections/animals/rhino.jpg");
    Word word("RHINO");
    current_level.setWord(word);
    current_level.setTranslation("RHINO");
}
else if (i == 16)
{
    current_level.setImage("collections/animals/rabbit.jpg");
    Word word("RABBIT");
    current_level.setWord(word);
    current_level.setTranslation("RABBIT");
}
else if (i == 17)
{
    current_level.setImage("collections/animals/sheep.jpg");
    Word word("SHEEP");
    current_level.setWord(word);
    current_level.setTranslation("SHEEP");
}
else if (i == 18)
{
    current_level.setImage("collections/animals/turtle.jpg");
    Word word("TURTLE");
    current_level.setWord(word);
    current_level.setTranslation("TURTLE");
}
else if (i == 19)
{
    current_level.setImage("collections/animals/zebra.jpg");
    Word word("ZEBRA");
    current_level.setWord(word);
    current_level.setTranslation("ZEBRA");
}


levels.push_back(current_level);
}
    Collection collect;
    collect.setID(1);
    collect.setColor(InfoStyles::COLOR_ORANGE);
    collect.setImage("collections/c1.png");
    collect.setName("Animals");
    collect.setLevels(levels);
    collect.setLevelNum(1);
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
