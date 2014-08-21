#ifndef LEVELSCENE_H
#define LEVELSCENE_H
#include "SceneStyle.h"

class LevelScene: public SceneStyle
{
public:
    LevelScene();
    static cocos2d::CCScene* scene();
    static LevelScene* create();
private:

    bool init();
    void onBackClick();
};

#endif // LEVELSCENE_H
