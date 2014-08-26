#ifndef ALPHABETE_H
#define ALPHABETE_H
#include <vector>
#include <string>
#include "cocos2d.h"
class Alphabete
{
public:
    static Alphabete& getInstance();
    void setApphabete();
    const std::vector<std::string>& getAlphabete();
    std::vector<cocos2d::ccColor3B> _alphabete_color;
    void setAlphabeteColor();
    cocos2d::ccColor3B  getColorLetterById(int id);
    const std::vector<cocos2d::ccColor3B >& getAlphabeteColor();

private:

    Alphabete();
    std::vector<std::string> _alphabete;

};

#endif // ALPHABETE_H