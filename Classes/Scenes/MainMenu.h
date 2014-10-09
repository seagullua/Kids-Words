#ifndef MAINSCENE_H
#define MAINSCENE_H
#include "cocos2d-A.h"
#include "SceneStyle.h"

class MainMenu: public SceneStyle
{
public:
    MainMenu();
    static cocos2d::CCScene* scene();
    static MainMenu* create();

private:
    bool init();
    void onBackClick();
    void onPlayClick();
    void onSettingsClick();
};

#endif // MAINSCENE_H
