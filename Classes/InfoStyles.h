#ifndef INFOSTYLES_H
#define INFOSTYLES_H
#include "cocos2d.h"
#include <vector>
#include <string>
#include <ADLib/ADString.h>
#include <ADLib/Device/ADSoundManager.h>

enum class WordsLanguage
{
    English,
    Ukrainian,
    Russian
};

enum class Version
{
    AdsPurchase,
    AdsNoPurchase,
    NoAds
};


class InfoStyles
{
public:
    static const Version VERSION;
    static const WordsLanguage WORDS_LANGUAGE;
    InfoStyles();
    //sizes
    static const int SIZE_SETTINGS_BUTTON;
    static const int SIZE_DEVELOPERS_TITLE;
    static const int SIZE_LINE_TITLE;
    static const int SIZE_SETTINGS_BUTTON_TURN;
    static const int SIZE_MENU_TITLE;
    static const int SIZE_MENU_TITLE_POP_UP;
    static const int SIZE_BUTTON_POP_UP;
    static const int SIZE_LETTER;
    static const int SIZE_TRANSLATED_WORD;
    static const int SIZE_EXIT_TITLE;
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
    static const cocos2d::ccColor3B COLOR_BLUE_LIGHT;
    static const cocos2d::ccColor3B COLOR_RED_LIGHT;
    static const cocos2d::ccColor3B COLOR_GREEN_LIGHT;
    static const cocos2d::ccColor3B COLOR_DARK_LIGHT;
    static const cocos2d::ccColor3B COLOR_YELLOW_LIGHT;
    static const cocos2d::ccColor3B COLOR_DARK;
    static const cocos2d::ccColor3B COLOR_PINK;
    static const cocos2d::ccColor3B COLOR_ORANGE_LIGHT;

    static const char* CORRECT_LETTER_MUSIC;
    static const char* CORRECT_WORD_MUSIC;
    static const char* IN_CORRECT_LETTER_MUSIC;
    static bool showAds();
    static bool showPurchase();

};

#endif // INFOSTYLES_H
