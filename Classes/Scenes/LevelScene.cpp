#include "LevelScene.h"
#include "SelectLevel.h"
#include <ADLib/ADString.h>
#include "InfoStyles.h"
#include "Logic/Alphabete.h"
#include "Logic/LevelSaves.h"
#include "Logic/OneSeason.h"
#include "Draw/GameNode.h"
#include <vector>
#include <string>
#include "PopUp/LevelEnd.h"
#include "Managers/SaveStarsManager.h"

using namespace cocos2d;

LevelScene::LevelScene(CollectionID id, int difficult)
    :
      _current_one_season(id,difficult),
      _top_panel(nullptr),
      _end_game_touch(false)
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

    auto open_next_level = [this](){
        openNextLevel();
    };
    _game_node->onGameEnd();
    if (_end_game_touch)
    {

        _end_game_touch = false;

        openNextLevel();

    }
    else
    {


        this->runAction(CCSequence::create(
                            CCDelayTime::create(2),
                            ADCallFunc::create(open_next_level),
                            NULL
                            ));

    }
    //_end_game_touch = false;

}
void LevelScene::onOneGameEndTouch()
{
    this->stopAllActions();
    openNextLevel();
}

void LevelScene::openNextLevel()
{
    const CCPoint ORIGIN = ADScreen::getOrigin();
    const CCSize VISIBLE_SIZE = ADScreen::getVisibleSize();
    CCNode* node = _game_node;
    auto remove_from_parent = [node](){
        node->removeFromParent();
    };
    _game_node->runAction(
                CCSequence::create(
                    CCMoveTo::create(0.5f,ccp(0-VISIBLE_SIZE.width,ORIGIN.y) ),
                    ADCallFunc::create(remove_from_parent),
                    NULL
                    )
                );

    selectOneGame();
}

bool LevelScene::init()
{
    if(!SceneStyle::init())
        return false;

    //Get the screen start of cordinates
    const CCPoint ORIGIN = ADScreen::getOrigin();
    const CCSize VISIBLE_SIZE = ADScreen::getVisibleSize();
    const float SCALE = ADScreen::getScaleFactor();
    float padding = 25/SCALE;

    showBackground(BackgroundType::None);
    int star_number = 10;

    _number_of_word = _current_one_season.getNumberWord(_difficult);
    _current_number_of_word = 1;
    if (!_top_panel)
    {
        _top_panel= TopPanell::create(_current_number_of_word,_number_of_word,star_number);
        _top_panel->setAnchorPoint(ccp(0,1));
        _top_panel->setPositionX(ORIGIN.x);
        _top_panel->setPositionY(ORIGIN.y + VISIBLE_SIZE.height +padding*0.5f);
        CONNECT(_top_panel->signalAudioClicked, this, &LevelScene::onSignalAudioClicked);
        CONNECT(_top_panel->signalUseHint, this, &LevelScene::onSignalUseHintClicked);

        _use_h=VISIBLE_SIZE.height - _top_panel->getContentSize().height;
        this->addChild(_top_panel);
    }
    showButtonBack();
    _tutorial = false;

    if(TutorialManager::getInstance()->isFirstGame())
    {
        _tutorial = true;
    }

    selectOneGame();
    return true;
}
void LevelScene::onSignalAudioClicked()
{
    CCLog("Level scene");
}
void LevelScene::onSignalUseHintClicked()
{


    if(_current_one_season.isCanUseHint())
    {

        _current_one_season.setNumberOfHint();
        int number_of_use_hint = _current_one_season.getNumberOfHint() ;
        _top_panel->starsDrawChanged(number_of_use_hint);
        _game_node->showHint();


    }
    else
    {

    }
}
void LevelScene::setOneGame(const OneGame* one_game)
{
    _one_game = one_game;
}
void LevelScene::selectOneGame()
{
    const CCPoint ORIGIN = ADScreen::getOrigin();
    const CCSize VISIBLE_SIZE = ADScreen::getVisibleSize();
    if (_current_number_of_word < _number_of_word)
    {

        _one_game = _current_one_season.getNextLevel();
        _current_number_of_word = _current_one_season.getSetTaskNumber();
        _top_panel->setTitleNumberWord(_current_number_of_word);
        Task task = _one_game->getTask();

        std::string translated_word = task.getTranslatedWord();
        if (translated_word.size() != 0)
        {
            // translated_word
            _top_panel->setTranslationWord(translated_word.c_str());
        }
        setOneGame(_one_game);
        _game_node= GameNode::create(_one_game,_use_h);
        _game_node->setAnchorPoint(ccp(0,0));
        _game_node->setPositionX(VISIBLE_SIZE.width);
        _game_node->setPositionY(0);
        _game_node->runAction(CCMoveTo::create(0.5f,ccp(0,0) ));
        if (_tutorial)
        {
            _game_node->showHint();
            TutorialManager::getInstance()->setIsNotFirstGame();
            _tutorial = false;
        }
        this->addChild(_game_node);
        CONNECT(_game_node->signalGameEnd, this, &LevelScene::onOneGameEnd);
        CONNECT(_game_node->signalTouchGameEnd, this, &LevelScene::onOneGameEndTouch);
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
    int star_number_old = SaveStarsManager::getInstance()->getStars(
                _collection_id, _difficult);

    int star_number_current = getStarNumber();\
 //   int star_number = star_number_current;
    int star_number = MAX(star_number_old,star_number_current);
    SaveStarsManager::getInstance()->setStars(
                _collection_id, _difficult, star_number);
    _pop_up_manager.openWindow(new LevelEnd(this,_collection_id,star_number,_difficult));

}
int LevelScene::getStarNumber()
{
    return  _current_one_season.getNumberOfHint();
    ;
}
void LevelScene::onSignalNextLesson()
{
    selectNextSeason();
}
