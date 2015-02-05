#include "InfoStyles.h"
#include "Managers/AdsManager.h"

InfoStyles::InfoStyles()
{
}

//sizes
const int InfoStyles::SIZE_SETTINGS_BUTTON = 80;
const int InfoStyles::SIZE_SETTINGS_BUTTON_TURN = 60;
const int InfoStyles::SIZE_BUTTON_POP_UP = 40;
const int InfoStyles::SIZE_DEVELOPERS_TITLE = 50;
const int InfoStyles::SIZE_LINE_TITLE = 30;
const int InfoStyles::SIZE_MENU_TITLE = 70;
const int InfoStyles::SIZE_MENU_TITLE_POP_UP = 100;
const int InfoStyles::SIZE_LETTER = 100;
const int InfoStyles::SIZE_EXIT_TITLE = 60;
const int InfoStyles::SIZE_TRANSLATED_WORD = 40;
//% letter by difficult
const int InfoStyles::EASY = 30;
const int InfoStyles::MIDDLE = 50;
const int InfoStyles::DIFFICULT = 70;
//number words by difficult
const int InfoStyles::EASY_WORD = 5;
const int InfoStyles::MIDDLE_WORD = 7;
const int InfoStyles::DIFFICULT_WORD = 10;
//min number letter by difficult
const int InfoStyles::EASY_NUMBER = 3;
const int InfoStyles::MIDDLE_NUMBER = 4;
const int InfoStyles::DIFFICULT_NUMBER = 5;


const char* InfoStyles::CORRECT_LETTER_MUSIC = "music/CorrectLetter" MUSIC_EXT;
const char* InfoStyles::IN_CORRECT_LETTER_MUSIC = "music/InCorrectLetter" MUSIC_EXT;
const char* InfoStyles::CORRECT_WORD_MUSIC = "music/CorrectWord" MUSIC_EXT;
const char* InfoStyles::MENU_MUSIC = "music/menu-music" MUSIC_EXT;



//colors
const cocos2d::ccColor3B InfoStyles::COLOR_WHITE = cocos2d::ccc3(255, 255, 255);
const cocos2d::ccColor3B InfoStyles::COLOR_BLUE = cocos2d::ccc3(9,154,255);
const cocos2d::ccColor3B InfoStyles::COLOR_BLUE_LIGHT = cocos2d::ccc3(9,206,255);
const cocos2d::ccColor3B InfoStyles::COLOR_RED = cocos2d::ccc3(250,70,10);
const cocos2d::ccColor3B InfoStyles::COLOR_GREEN = cocos2d::ccc3(20,167,0);
const cocos2d::ccColor3B InfoStyles::COLOR_YELLOW = cocos2d::ccc3(255,221,30);
const cocos2d::ccColor3B InfoStyles::COLOR_ORANGE= cocos2d::ccc3(255,78,9);
const cocos2d::ccColor3B InfoStyles::COLOR_ORANGE_LIGHT= cocos2d::ccc3(255,120,0);
const cocos2d::ccColor3B InfoStyles::COLOR_MAGENTA= cocos2d::ccc3(200,9,255);
const cocos2d::ccColor3B InfoStyles::COLOR_RED_LIGHT = cocos2d::ccc3(255,20,12);
const cocos2d::ccColor3B InfoStyles::COLOR_GREEN_LIGHT = cocos2d::ccc3(26,219,0);
const cocos2d::ccColor3B InfoStyles::COLOR_DARK_LIGHT = cocos2d::ccc3(90,90,90);
const cocos2d::ccColor3B InfoStyles::COLOR_YELLOW_LIGHT = cocos2d::ccc3(255,255,0);
const cocos2d::ccColor3B InfoStyles::COLOR_DARK = cocos2d::ccc3(0,0,0);
const cocos2d::ccColor3B InfoStyles::COLOR_PINK = cocos2d::ccc3(250,0,120);

const cocos2d::ccColor3B InfoStyles::COLOR_TITLE = cocos2d::ccc3(224,94,174);

bool InfoStyles::showAds()
{
    bool show_ads = false;
    if (InfoStyles::VERSION == Version::AdsPurchase)
    {
        show_ads = !AdsManager::getInstance()->isAdsPurchased();
    }
    if (InfoStyles::VERSION == Version::NoAds)
    {
        show_ads = false;
    }
    if (InfoStyles::VERSION == Version::AdsNoPurchase)
    {
        show_ads = true;
    }
    return show_ads;


}

bool InfoStyles::showPurchase()
{
    bool show_purchase = false;
    if (InfoStyles::VERSION == Version::AdsPurchase)
    {
        show_purchase = !AdsManager::getInstance()->isAdsPurchased();
    }
    if (InfoStyles::VERSION == Version::NoAds)
    {
        show_purchase = false;
    }
    if (InfoStyles::VERSION == Version::AdsNoPurchase)
    {
        show_purchase = false;
    }
    return show_purchase;
}

std::string InfoStyles::getPurchaseID()
{
     return "abc_words_english";

}
#include <ADLib/Device/ADInfo.h>

std::string InfoStyles::getStoreID()
{
    if(ADInfo::getStore() == ADStore::GooglePlay)
    {
        return "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAguP1yjaQD89uz4XGIYUr6w0DSQ14YzQbXKvhD29w0TCZVm5rDQete30nOH8w+Dqu2aTWuKFbLu/VmCeSSBRy4yvIfPyhKtlPghiQdKGZPlGWOlIbuoZ0XvnWi/ftsP7f9IuCrjq8dyXCQwf21T9t/00oIQOuMb3bMMbKJlXGwf99JOSw2GFUq//p4PT3fI8MaQK/g/xgt7ZpFiH4ACKYLkfETUZAZHiSOugclxzAtanS92hZQZCHsgme7qOppiYkR+sAUUenArkSwB4hH3P+noVZA01X02VYqt2+xQt/XJKGmqsOr/Isju8OmATltgfLJWL6Xpxs36wBLKYbmIyhUwIDAQAB";
    }
    else if(ADInfo::getStore() == ADStore::SamsungStore)
    {
        return "100000104962";
    }

    return "";
}
