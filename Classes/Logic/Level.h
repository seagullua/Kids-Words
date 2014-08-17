#ifndef LEVEL_H
#define LEVEL_H
#include <string>
#include "Word.h"
//#include "Collection.h"
class Level
{
public:
    Level();
    typedef unsigned int LevelID;
    LevelID _id;
    std::string _level_image;

    Word _word;
    std::string _translation;
    void setID(LevelID id);
    void setImage(std::string image);
    const LevelID getID() const;
    const std::string getImage() const;

};


#endif // LEVEL_H
