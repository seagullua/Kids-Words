#ifndef LLEVEL_H
#define LLEVEL_H
#include "Word.h"
#include <vector>
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

#endif // LLEVEL_H
