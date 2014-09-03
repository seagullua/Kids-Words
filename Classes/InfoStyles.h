#ifndef INFOSTYLES_H
#define INFOSTYLES_H
#include "cocos2d.h"
#include <vector>
#include <string>
class InfoStyles
{
public:
    InfoStyles();
    //sizes
    static const int SIZE_SETTINGS_BUTTON;
    static const int SIZE_DEVELOPERS_TITLE;
    static const int SIZE_LINE_TITLE;
    static const int SIZE_SETTINGS_BUTTON_TURN;
    static const int SIZE_MENU_TITLE;
    static const int SIZE_LETTER;
    //% letter by difficult
    static const int EASY ;
    static const int MIDDLE;
    static const int DIFFICULT ;
    //number words by difficult
    static const int EASY_WORD;
    static const int MIDDLE_WORD;
    static const int DIFFICULT_WORD;
    //min number letter by difficult
    static const int EASY_NUMBER;
    static const int MIDDLE_NUMBER;
    static const int DIFFICULT_NUMBER;
    //colors
    static const cocos2d::ccColor3B COLOR_WHITE;
    static const cocos2d::ccColor3B COLOR_BLUE;
    static const cocos2d::ccColor3B COLOR_RED;
    static const cocos2d::ccColor3B COLOR_GREEN;
    static const cocos2d::ccColor3B COLOR_YELLOW;
    static const cocos2d::ccColor3B COLOR_ORANGE;
    static const cocos2d::ccColor3B COLOR_MAGENTA;

};

#endif // INFOSTYLES_H
