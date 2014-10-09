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
            _collection.setColor(LevelSaves::getInstance().getColor(_collection_id));
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

}
void LevelSaves::addCollection(Collection collect)
{
    _collections.push_back(collect);
}
const cocos2d::ccColor3B LevelSaves::getColor(int id)
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

