#include "LevelSaves.h"
#include "Collection.h"
#include "CollectionPart.h"
#include "Level.h"
#include "Word.h"
#include "InfoStyles.h"
#include "Alphabete.h"
using namespace cocos2d;
#include <ADLib/UTF8/ADUTF8.h>
#include <ADLib/Device/ADLanguage.h>
//ADUTF8::splitToChars("aaaa");


class XMLParser : public CCSAXDelegator
{
public:
    XMLParser(const std::string& file)
    {
        GAME_VERSION = "uk";
        APPLICATION_LANG = ADLanguage::getLanguage();

        std::string file_name = CCFileUtils::sharedFileUtils()->fullPathForFilename(file.c_str());
        unsigned long size = 0;
        unsigned char* data = CCFileUtils::sharedFileUtils()->getFileData(file_name.c_str(), "r", &size);

        CCSAXParser parser;

        parser.setDelegator(this);
        bool res = false;
        if(size > 0)
            _collection_id = 0;
        res = parser.parse((char*)data, size);

        delete[] data;
    }
    void startElement(void *ctx, const char *name, const char **atts)
    {
        CC_UNUSED_PARAM(ctx);
        CC_UNUSED_PARAM(atts);
        std::string sName((char*)name);

        if(sName == "collection")
        {
            _collection = Collection();
            _in_collection = true;
            _collection_id = _collection_id + 1;
            _level_id = 0;

        }
        if(sName == "level")
        {
            _level = Level();
            _level_id = _level_id +1;
        }


    }
    void endElement(void *ctx, const char *name)
    {
        CC_UNUSED_PARAM(ctx);
        std::string sName((char*)name);
        if(sName == GAME_VERSION)
        {
            _text_game_version = _text;
        }
        if(sName == APPLICATION_LANG)
        {
            _text_application_language = _text;
        }

        if(sName == "collection")
        {
            _collection.setID(_collection_id);
            _collection.setColor(getColor(_collection_id));
            _collection.setLevels(_levels);
            LevelSaves::getInstance().addCollection(_collection);
            _in_collection = false;
            _level_id = 0;
            _levels.clear();
        }
        if(sName == "collection_name")
        {
            _collection.setName(_text_application_language);
        }
        if(sName == "collection_image")
        {
            _collection.setImage(_text);
        }
        if(sName == "middle")
        {
            CollectionPart collect_part;
            collect_part.setImage(_text);
            _collection.setCollectionPartMiddle(collect_part);
        }
        if(sName == "easy")
        {
            CollectionPart collect_part;
            collect_part.setImage(_text);
            _collection.setCollectionPartEasy(collect_part);
        }
        if(sName == "difficult")
        {
            CollectionPart collect_part;
            collect_part.setImage(_text);
            _collection.setCollectionPartDifficult(collect_part);
        }
        if(sName == "alphabet")
        {
            Alphabete::getInstance().setApphabete(_text_game_version);
            Alphabete::getInstance().setAlphabeteColor();
        }
        if(sName == "level")
        {

            _level.setID(_level_id);
            _levels.push_back(_level);
        }

        if(sName == "word")
        {
            Word word(_text_game_version);
            _level.setWord(word);
            if(GAME_VERSION != APPLICATION_LANG)
            {
                _level.setTranslation(_text_application_language);
            }
        }
        if(sName == "image")
        {
            _level.setImage(_text);
        }

    }
    void textHandler(void *ctx, const char *ch, int len)
    {
        CC_UNUSED_PARAM(ctx);
        std::string text((char*)ch,0,len);
        _text = text;
    }
    const cocos2d::ccColor3B getColor(int id)
    {
        if (id == 1)
        {
            return  InfoStyles::COLOR_ORANGE;
        }
        else if (id == 2)
        {
            return  InfoStyles::COLOR_BLUE;

        }
        else if (id == 3)
        {
            return  InfoStyles::COLOR_GREEN;

        }
        else if (id == 4)
        {
            return  InfoStyles::COLOR_MAGENTA;

        }
        else if (id == 5)
        {
            return  InfoStyles::COLOR_ORANGE_LIGHT;

        }
        else if (id == 6)
        {
            return  InfoStyles::COLOR_RED_LIGHT;

        }
        else if (id == 7)
        {
            return  InfoStyles::COLOR_BLUE_LIGHT;

        }
        else if (id == 8)
        {
            return  InfoStyles::COLOR_GREEN_LIGHT;

        }
        else if (id == 9)
        {
            return  InfoStyles::COLOR_PINK;

        }
        else if (id == 10)
        {
            return  InfoStyles::COLOR_ORANGE_LIGHT;

        }
    }

    Collection _collection;
    std::vector<Collection> _collections_readed;
    std::vector<Level> _levels;
    Level _level;
    std::string GAME_VERSION;
    std::string APPLICATION_LANG;
    std::string _text;

    std::string _text_game_version;
    std::string _text_application_language;
    int _collection_id;
    int _level_id;
    bool _in_collection;
    bool _in_level;

};

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
    XMLParser parser("collections/collections.xmld");


    //    for (int i = 0 ; i<20; ++i)
    //    {


    //        Level current_level;
    //        current_level.setID(i);
    //        if (i == 0)
    //        {
    //            current_level.setImage("collections/animals/tiger.jpg");
    //            Word word("TIGER");
    //            current_level.setWord(word);
    //            current_level.setTranslation("тигр");
    //        }
    //        else if (i == 1)
    //        {
    //            current_level.setImage("collections/animals/bear.jpg");
    //            Word word("BEAR");
    //            current_level.setWord(word);
    //            //  current_level.setTranslation("ведмідь");
    //            current_level.setTranslation("BEAR");

    //        }
    //        else if (i == 2)
    //        {
    //            current_level.setImage("collections/animals/cat.jpg");
    //            Word word("CAT");
    //            current_level.setWord(word);
    //            current_level.setTranslation("CAT");
    //        }
    //        else if (i == 3)
    //        {
    //            current_level.setImage("collections/animals/chinchilla.jpg");
    //            Word word("CHINCHILLA");
    //            current_level.setWord(word);
    //            current_level.setTranslation("CHINCHILLA");
    //        }
    //        else if (i == 4)
    //        {
    //            current_level.setImage("collections/animals/cow.jpg");
    //            Word word("COW");
    //            current_level.setWord(word);
    //            current_level.setTranslation("COW");
    //        }
    //        else if (i == 5)
    //        {
    //            current_level.setImage("collections/animals/dog.jpg");
    //            Word word("DOG");
    //            current_level.setWord(word);
    //            current_level.setTranslation("DOG");
    //        }
    //        else if (i == 6)
    //        {
    //            current_level.setImage("collections/animals/elephant.jpg");
    //            Word word("ELEPHANT");
    //            current_level.setWord(word);
    //            current_level.setTranslation("ELEPHANT");
    //        }
    //        else if (i == 7)
    //        {
    //            current_level.setImage("collections/animals/fox.jpg");
    //            Word word("FOX");
    //            current_level.setWord(word);
    //            current_level.setTranslation("FOX");
    //        }
    //        else if (i == 8)
    //        {
    //            current_level.setImage("collections/animals/frog.jpg");
    //            Word word("FROG");
    //            current_level.setWord(word);
    //            current_level.setTranslation("FROG");
    //        }
    //        else if (i == 9)
    //        {
    //            current_level.setImage("collections/animals/lion.jpg");
    //            Word word("LION");
    //            current_level.setWord(word);
    //            current_level.setTranslation("LION");
    //        }
    //        else if (i == 10)
    //        {
    //            current_level.setImage("collections/animals/monkey.jpg");
    //            Word word("MONKEY");
    //            current_level.setWord(word);
    //            current_level.setTranslation("MONKEY");
    //        }

    //        else if (i == 11)
    //        {
    //            current_level.setImage("collections/animals/owl.jpg");
    //            Word word("OWL");
    //            current_level.setWord(word);
    //            current_level.setTranslation("OWL");
    //        }
    //        else if (i == 12)
    //        {
    //            current_level.setImage("collections/animals/parrot.jpg");
    //            Word word("PARROT");
    //            current_level.setWord(word);
    //            current_level.setTranslation("PARROT");
    //        }
    //        else if (i == 13)
    //        {
    //            current_level.setImage("collections/animals/penguin.jpg");
    //            Word word("PENGUIN");
    //            current_level.setWord(word);
    //            current_level.setTranslation("PENGUIN");
    //        }
    //        else if (i == 14)
    //        {
    //            current_level.setImage("collections/animals/rabbit.jpg");
    //            Word word("RABBIT");
    //            current_level.setWord(word);
    //            current_level.setTranslation("RABBIT");
    //        }
    //        else if (i == 15)
    //        {
    //            current_level.setImage("collections/animals/rhino.jpg");
    //            Word word("RHINO");
    //            current_level.setWord(word);
    //            current_level.setTranslation("RHINO");
    //        }
    //        else if (i == 16)
    //        {
    //            current_level.setImage("collections/animals/rabbit.jpg");
    //            Word word("RABBIT");
    //            current_level.setWord(word);
    //            current_level.setTranslation("RABBIT");
    //        }
    //        else if (i == 17)
    //        {
    //            current_level.setImage("collections/animals/sheep.jpg");
    //            Word word("SHEEP");
    //            current_level.setWord(word);
    //            current_level.setTranslation("SHEEP");
    //        }
    //        else if (i == 18)
    //        {
    //            current_level.setImage("collections/animals/turtle.jpg");
    //            Word word("TURTLE");
    //            current_level.setWord(word);
    //            current_level.setTranslation("TURTLE");
    //        }
    //        else if (i == 19)
    //        {
    //            current_level.setImage("collections/animals/zebra.jpg");
    //            Word word("ZEBRA");
    //            current_level.setWord(word);
    //            current_level.setTranslation("ZEBRA");
    //        }


    //        levels.push_back(current_level);
    //    }



    //    Collection collect;
    //    collect.setID(1);
    //    collect.setColor(InfoStyles::COLOR_ORANGE);
    //    collect.setImage("collections/c1.png");
    //    collect.setName("Animals");
    //    collect.setLevels(levels);
    //    collect.setLevelNum(1);
    //    CollectionPart collect_part_easy;
    //    CollectionPart collect_part_dificult;
    //    CollectionPart collect_part_middle;
    //    collect_part_easy.setImage("collections/c1.png");
    //    collect_part_dificult.setImage("collections/c2.png");
    //    collect_part_middle.setImage("collections/c3.png");
    //    collect.setCollectionPartEasy(collect_part_easy);
    //    collect.setCollectionPartMiddle(collect_part_middle);
    //    collect.setCollectionPartDifficult(collect_part_dificult);


    //    _collections.push_back(collect);
    //    Collection collect1;
    //    collect1.setID(2);
    //    collect1.setColor(InfoStyles::COLOR_BLUE);
    //    collect1.setImage("collections/c2.png");
    //    collect1.setName("Food");
    //    collect1.setCollectionPartEasy(collect_part_dificult);
    //    collect1.setCollectionPartMiddle(collect_part_middle);
    //    collect1.setCollectionPartDifficult( collect_part_easy);

    //    _collections.push_back(collect1);
    //    Collection collect2;
    //    collect2.setID(3);
    //    collect2.setColor(InfoStyles::COLOR_MAGENTA);
    //    collect2.setImage("collections/c3.png");
    //    collect2.setName("Family");
    //    collect2.setCollectionPartEasy(collect_part_easy);
    //    collect2.setCollectionPartMiddle(collect_part_dificult);
    //    collect2.setCollectionPartDifficult( collect_part_middle);

    //    _collections.push_back(collect2);

}
void LevelSaves::addCollection(Collection collect)
{
    _collections.push_back(collect);
}
