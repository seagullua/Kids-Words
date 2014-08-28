#include "LevelScene.h"
#include "SelectLevel.h"
#include <ADLib/ADString.h>
#include "InfoStyles.h"
#include "Logic/Alphabete.h"
#include "Logic/LevelSaves.h"
#include "Draw/TopPanell.h"
#include "Logic/OneSeason.h"
#include <vector>
#include <string>

using namespace cocos2d;

LevelScene::LevelScene(CollectionID id, int difficult)
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
    TopPanell* top_panel = TopPanell::create(1,10,7);

    top_panel->setAnchorPoint(ccp(0,1));
    //   top_panel->setPositionX(0);

    //top_panel->setPositionY();

    top_panel->setPositionX(ORIGIN.x);
    top_panel->setPositionY(ORIGIN.y + VISIBLE_SIZE.height +padding*0.5f);
    CONNECT(top_panel->signalAudioClicked, this, &LevelScene::onSignalAudioClicked);
   CONNECT(top_panel->signalUseHint, this, &LevelScene::onSignalUseHintClicked);

    //    top_panel->setPositionY(ORIGIN.y +
    //                                          + VISIBLE_SIZE.height-padding*0.25f -
    //                                          top_panel->getContentSize().height*0.5f);


    //    float node_scale = (VISIBLE_SIZE.width-(x_middle_of_sheet+padding*2)/top_panel->getContentSize().width);
    //    if(node_scale < 1)
    //    {
    //        top_panel->setScale(node_scale);
    //    }
    this->addChild(top_panel);
    showButtonBack();
    OneSeason current_one_season(_collection_id,_difficult);
    const OneGame*  current_one_game = current_one_season.getNextLevel();

    setOneGame(current_one_game);

//    CCNode* node = CCNode::create();
//    node->setContentSize(ccp(400, 500));
//    node->setAnchorPoint(ccp(0,0));
//    std::vector<std::string> current_alphabete;
//    current_alphabete =Alphabete::getInstance().getAlphabete();

//    std::vector<cocos2d::ccColor3B > current_alphabete_color;
//    current_alphabete_color =Alphabete::getInstance().getAlphabeteColor();
//    unsigned int j = 1;
//    unsigned int k = 1;
//    for(unsigned int i = 0; i < current_alphabete.size(); ++i)
//    {
//        k = ++k;
//        if (i <= 9)
//        {
//            j = 1;
//            k = 1;
//        }
//        if (i > 9 && i <=  19)
//        {
//            j = 2;
//            k = 1;
//        }
//        if (i > 19 && i <=  29)
//        {
//            j = 3;
//            k = 1;
//        }
//        if (i > 29 && i <=  33)
//        {
//            j = 4;
//            k = 1;
//        }
//        cocos2d::CCLabelTTF* current_letter;
//        std::string  let;
//        let = current_alphabete[i].c_str();
//        cocos2d::ccColor3B col;
//        col = current_alphabete_color[i];

//        current_letter = CCLabelTTF::create(current_alphabete[i].c_str(),
//                                            ADLanguage::getFontName(),
//                                            InfoStyles::SIZE_DEVELOPERS_TITLE);

//        current_letter->setColor(col);

//        current_letter->setAnchorPoint(ccp(0,0));
//        //        if (k == 1)
//        //        {
//        //                 current_letter->setPositionX(padding*5+current_letter->getContentSize().width*i;
//        //        }
//        //else
//        //        {
//        //                 current_letter->setPositionX(padding*5*i);
//        //        }
//        //        current_letter->setPositionY(padding*5*j);
//        current_letter->setPositionX(padding*5+current_letter->getContentSize().width*i);
//        current_letter->setPositionY(padding*5*j);
//        node->addChild(current_letter);


//    }
//    node->setPositionX(padding*5);

//    node->setPositionY(padding);

//    //node->setScale(2);
//    this->addChild(node);
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
void LevelScene::setOneGame(const OneGame*  one_game)
{
    _one_game = one_game;
}
