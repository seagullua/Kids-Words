#include "LevelScene.h"
#include "SelectLevel.h"
#include <ADLib/ADString.h>
#include "InfoStyles.h"
#include "Logic/Alphabete.h"
#include "Logic/LevelSaves.h"
#include "Logic/Hint.h"
#include "Logic/OneSeason.h"
#include "Draw/GameNode.h"
#include <vector>
#include <string>
#include "PopUp/LevelEnd.h"

using namespace cocos2d;

LevelScene::LevelScene(CollectionID id, int difficult)
    :
      _current_one_season(id,difficult),
      _top_panel(nullptr)
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
    _number_of_word = _current_one_season.getNumberWord(_difficult);
    _current_number_of_word = 1;
    if (!_top_panel)
    {

        _top_panel= TopPanell::create(_current_number_of_word,_number_of_word,10);

        _top_panel->setAnchorPoint(ccp(0,1));


        _top_panel->setPositionX(ORIGIN.x);
        _top_panel->setPositionY(ORIGIN.y + VISIBLE_SIZE.height +padding*0.5f);
        CONNECT(_top_panel->signalAudioClicked, this, &LevelScene::onSignalAudioClicked);
        CONNECT(_top_panel->signalUseHint, this, &LevelScene::onSignalUseHintClicked);

        _use_h=VISIBLE_SIZE.height - _top_panel->getContentSize().height;
        this->addChild(_top_panel);
    }
    showButtonBack();

    //    button_back->setAnchorPoint(ccp(0,1));
    //    button_back->setPositionY(ORIGIN.y + VISIBLE_SIZE.height +padding*0.5f);

    selectOneGame();
//    CONNECT(this->signalNextLesson, this, &LevelScene::onSignalNextLesson);
    return true;
}
void LevelScene::onSignalAudioClicked()
{
    CCLog("Level scene");
}
void LevelScene::onSignalUseHintClicked()
{
    //    if(_one_game->isCanUseHint())
    //    {
    //        _one_game->setNumberOfHint();
    //        int number_of_use_hint = _one_game->getNumberOfHint();
    //        _top_panel->starsDrawChanged(10-number_of_use_hint);
    //        OneHint current_hint = _one_game->getHint().getOneHint();
    //          _game_node->showHint(current_hint);

    //    }
    //    else
    //    {
    //        //TODO сказать что нет подсказок
    //    }
}
void LevelScene::setOneGame(const OneGame* one_game)
{
    _one_game = one_game;
}
void LevelScene::selectOneGame()
{

    if (_current_number_of_word < _number_of_word)
    {

        _one_game = _current_one_season.getNextLevel();
        _current_number_of_word = _current_one_season.getSetTaskNumber();
        _top_panel->setTitleNumberWord(_current_number_of_word);

        setOneGame(_one_game);
        _game_node= GameNode::create(_one_game,_use_h);
        _game_node->setAnchorPoint(ccp(0,0));
        _game_node->setPositionX(0);
        _game_node->setPositionY(0);
        this->addChild(_game_node);
        CONNECT(_game_node->signalGameEnd, this, &LevelScene::onOneGameEnd);
    }
    else
    {
        EndLevel();
    }
}
void LevelScene::selectNextSeason()
{
    _current_number_of_word = 1;
    OneSeason new_one_season (_collection_id,_difficult);
    _current_one_season = new_one_season;
    selectOneGame();

}

void LevelScene::EndLevel()
{
    int star_number = getStarNumber();
    _pop_up_manager.openWindow(new LevelEnd(this,_collection_id,star_number,_difficult));

}
int LevelScene::getStarNumber()
{
    return 7;
}
void LevelScene::onSignalNextLesson()
{
    selectNextSeason();
}
