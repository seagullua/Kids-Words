#ifndef LEVEL_H
#define LEVEL_H
#include <string>
#include "Word.h"

class Level
{
public:
    Level();
    typedef unsigned int LevelID;
    LevelID _id;
    std::string _level_image;

    Word _word;
    std::string _translation;

};


#endif // LEVEL_H
