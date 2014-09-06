#include "LevelScene.h"
#include "SelectLevel.h"
#include <ADLib/ADString.h>
#include "InfoStyles.h"
#include "Logic/Alphabete.h"
#include "Logic/LevelSaves.h"
#include "Draw/TopPanell.h"
#include "Logic/OneSeason.h"
#include "Draw/GameNode.h"
#include <vector>
#include <string>

using namespace cocos2d;

LevelScene::LevelScene(CollectionID id, int difficult)
    :
      _current_one_season(id,difficult)
{
    _collection_id = id;
    _difficult = difficult;
}
CCScene* LevelScene::scene(CollectionID id, int difficult)
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    // 'layer' is an autorelease object
    LevelScene *layer = LevelScene::create(id,difficult);

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}



LevelScene* LevelScene::create(CollectionID id, int difficult)
{

    LevelScene *pRet = new LevelScene(id,difficult);
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
    CCDirector::sharedDirector()->replaceScene(SelectLevel::scene(_collection_id));
}
void LevelScene::onOneGameEnd()
{
    _game_node->removeFromParent();
    selectOneGame();

}

bool LevelScene::init()
{
    if(!SceneStyle::init())
        return false;

    //CCLog("Level click: %d", _collection_id);
    //    CCLog("_difficult: %d", _difficult);

    //Get the screen start of cordinates
    const CCPoint ORIGIN = ADScreen::getOrigin();
    const CCSize VISIBLE_SIZE = ADScreen::getVisibleSize();
    const float SCALE = ADScreen::getScaleFactor();
    float x_middle_of_sheet = (VISIBLE_SIZE.width-200/SCALE)/2 + ORIGIN.x;
    float padding = 25/SCALE;

    showBackground(BackgroundType::None);
  //  OneSeason _current_one_season(_collection_id,_difficult);
    int number_of_word = _current_one_season.getNumberWord(_difficult);
    TopPanell* top_panel = TopPanell::create(1,number_of_word,7);

    top_panel->setAnchorPoint(ccp(0,1));
    //   top_panel->setPositionX(0);

    //top_panel->setPositionY();

    top_panel->setPositionX(ORIGIN.x);
    top_panel->setPositionY(ORIGIN.y + VISIBLE_SIZE.height +padding*0.5f);
    CONNECT(top_panel->signalAudioClicked, this, &LevelScene::onSignalAudioClicked);
    CONNECT(top_panel->signalUseHint, this, &LevelScene::onSignalUseHintClicked);
//    float use_node_sise_panel = VISIBLE_SIZE.height*0.2f;
//    float panel_scale = use_node_sise_panel/top_panel->getContentSize().height;
//    if (panel_scale < 1)
//    {
//        top_panel->setScaleY(panel_scale);

//    }
    _use_h=VISIBLE_SIZE.height - top_panel->getContentSize().height;
    this->addChild(top_panel);
    showButtonBack();

//    button_back->setAnchorPoint(ccp(0,1));
//    button_back->setPositionY(ORIGIN.y + VISIBLE_SIZE.height +padding*0.5f);

    selectOneGame();
    CONNECT(_game_node->signalGameEnd, this, &LevelScene::onOneGameEnd);

    return true;
}
void LevelScene::onSignalAudioClicked()
{
    CCLog("Level scene");
}
void LevelScene::onSignalUseHintClicked()
{
    CCLog("Level scene onSignalUseHintClicked");
}
void LevelScene::setOneGame(const OneGame* one_game)
{
    _one_game = one_game;
}
void LevelScene::selectOneGame()
{

    _one_game = _current_one_season.getNextLevel();

    setOneGame(_one_game);
    _game_node= GameNode::create(_one_game,_use_h);
    _game_node->setAnchorPoint(ccp(0,0));
    _game_node->setPositionX(0);
    _game_node->setPositionY(0);
    this->addChild(_game_node);
}
