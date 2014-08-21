#include "LevelScene.h"
#include "SelectLevel.h"
#include <ADLib/ADString.h>
#include "InfoStyles.h"
using namespace cocos2d;
LevelScene::LevelScene()
{
}
CCScene* LevelScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    // 'layer' is an autorelease object
    LevelScene *layer = LevelScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}



LevelScene* LevelScene::create()
{

    LevelScene *pRet = new LevelScene();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

void LevelScene::onBackClick()
{
    //CCDirector::sharedDirector()->replaceScene(SelectLevel::scene());
}
bool LevelScene::init()
{
    if(!SceneStyle::init())
        return false;

    return true;
}
