#ifndef LEVEL_H
#define LEVEL_H
#include <string>
#include "Word.h"
//#include "Collection.h"
typedef unsigned int LevelID;
class Level
{
public:
    Level();

    LevelID _id;
    std::string _level_image;

    Word _word;
    std::string _translation;
    void setID(LevelID id);

    void setImage(std::string image);
    const LevelID getID() const;
    const std::string getImage() const;
    void setWord(Word word);
    void setTranslation(std::string translation);
    const Word getWord() const;
    const std::string getTranslation() const;

};


#endif // LEVEL_H
