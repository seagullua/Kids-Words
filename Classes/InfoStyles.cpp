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
    if(InfoStyles::VERSION_LEVEL == VersionLevel::NewBasics1)
    {
        return "abc_words_english";
    }
    assert(false);
    return "disable_ads";
}
#include <ADLib/Device/ADInfo.h>

std::string InfoStyles::getStoreID()
{
    if(ADInfo::getStore() == ADStore::GooglePlay)
    {
        if(InfoStyles::VERSION_LEVEL == VersionLevel::KidsEasy)
        {
            if(InfoStyles::WORDS_LANGUAGE == WordsLanguage::English)
                return "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAgGblxZcYRIW5O6sXEwdESzA7PjkzguQyI5F6aKNAhBW4/KZ49LGJsvKNKA4Y1iWvWSqd8BhbNsNKocBTQkYtni5IkZ0QDU9W/B3Qgcjx2CI4LYUPjXbKvzE7zYYtz6k7YerNwV7/GST1q3OrUMSaCBfcewIF9x6BTfBMjfuJhYWPEnycK6ylQF1cDGpu6+7pKZVBOwFnZovrNMG9On6p80gfmlLRnCl7u8nm+asI1m91y18sJl62+uIiVlPLYIiuTGKXab46fUVQp/k9+8OqeaMEvZp7fHh2YSGb7k5MvyrOk/Cd95evUGh8sNqsFdmKrt0LWY9Imdd4PKqwf+8vCwIDAQAB";
            else if (InfoStyles::WORDS_LANGUAGE == WordsLanguage::Russian)
                return "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAjMWaN8ud8FSn1p8XqeMYo2gU7djTWrV53F49THa1FbgfCvWwrb8PDKXGi9HoMl8xhZ8DVUykyqIHhpqplXnZdWiD5TLOceDconFF0CpISqkmlMxmaIWqzIQiaVDxHQZNgdad6nbY3LGn2XriRt68h27cM8bLbGiccX4V6ERDRZATTumW0JRBATiJt4bm/4uEiOKGHj1Hmk7yD9X8uP0aFRORomB00NIojpoju4HZq9eILvL0D59507lanw4GbdI4qiwcy3IRnX5j0EnaZ3FbrWormkLr+IqmKJ4YzgWT4N5YlNs2T4bJmC51xNLd1WDsNgzQPabGy7r3pF4Sz+H2sQIDAQAB";
            else if (InfoStyles::WORDS_LANGUAGE == WordsLanguage::Ukrainian)
                return "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA3JWDN3EF6p/Mt03bKCsoy/+GyKm7dXUYodQUEodLlL5yNBLD6KshP47w6Tf1OKjudl0bltic9FCX1h/8iq0YFgFv/OhzNSfntYQ7EZKeOni3buHoKiH580ZUwsEXfw76rauiVRuahA3HZbXJNtWkiMLYbrud5wWIBqvGTsYIQS+Or2yBbA9wZJKLlvdTdR9cf2y6rOIw88WbhxVVf17pGaEfs7KXtcWsFVVxmlhw9cvc9nIHaRXv3fQgat5z8HXc04+/ZcU4C+LJFHT94CbDTFG+nethz4QjvYxwev2Mi+JjJS8oymg6dBiYSdx3fZMCoSIZuhiuOaOKgDCNPEStjwIDAQAB";
        }
        else if(InfoStyles::VERSION_LEVEL == VersionLevel::KidsMedium)
        {
            if(InfoStyles::WORDS_LANGUAGE == WordsLanguage::English)
                return "";
            else if (InfoStyles::WORDS_LANGUAGE == WordsLanguage::Russian)
                return "";
            else if (InfoStyles::WORDS_LANGUAGE == WordsLanguage::Ukrainian)
                return "";
        }
        else if(InfoStyles::VERSION_LEVEL == VersionLevel::NewBasics1)
        {
            if(InfoStyles::WORDS_LANGUAGE == WordsLanguage::English)
                return "";
            else if (InfoStyles::WORDS_LANGUAGE == WordsLanguage::Russian)
                return "";
            else if (InfoStyles::WORDS_LANGUAGE == WordsLanguage::Ukrainian)
                return "";
        }
    }
    else if(ADInfo::getStore() == ADStore::SamsungStore)
    {
        if(InfoStyles::VERSION_LEVEL == VersionLevel::KidsEasy)
        {
            if(InfoStyles::WORDS_LANGUAGE == WordsLanguage::English)
                return "100000104661";
            else if (InfoStyles::WORDS_LANGUAGE == WordsLanguage::Russian)
                return "100000104662";
            else if (InfoStyles::WORDS_LANGUAGE == WordsLanguage::Ukrainian)
                return "100000104663";
        }
        else if(InfoStyles::VERSION_LEVEL == VersionLevel::KidsMedium)
        {
            if(InfoStyles::WORDS_LANGUAGE == WordsLanguage::English)
                return "100000104804";
            else if (InfoStyles::WORDS_LANGUAGE == WordsLanguage::Russian)
                return "";
            else if (InfoStyles::WORDS_LANGUAGE == WordsLanguage::Ukrainian)
                return "100000104805";
        }
        else if(InfoStyles::VERSION_LEVEL == VersionLevel::NewBasics1)
        {
            if(InfoStyles::WORDS_LANGUAGE == WordsLanguage::English)
                return "";
            else if (InfoStyles::WORDS_LANGUAGE == WordsLanguage::Russian)
                return "";
            else if (InfoStyles::WORDS_LANGUAGE == WordsLanguage::Ukrainian)
                return "";
        }
    }

    return "";
}
