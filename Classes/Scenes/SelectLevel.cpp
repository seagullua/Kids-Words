#include "SelectLevel.h"
#include "SelectCollection.h"
#include "MainMenu.h"
#include "Draw/Card.h"
#include "InfoStyles.h"
#include "Logic/LevelSaves.h"
#include "Logic/Level.h"
#include "LevelScene.h"
#include "Logic/Collection.h"
#include <vector>
#include <ADLib/Rendering/ADScrollView.h>
#include "Managers/SaveStarsManager.h"
using namespace cocos2d;

SelectLevel::SelectLevel(CollectionID id)

{
    _collection_id = id;
}

CCScene* SelectLevel::scene(CollectionID id)
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    // 'layer' is an autorelease object
    SelectLevel *layer = SelectLevel::create(id);

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}


SelectLevel* SelectLevel::create(CollectionID id)
{

    SelectLevel *pRet = new SelectLevel(id);
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

void SelectLevel::onBackClick()
{
    hideEverything([](){
            CCDirector::sharedDirector()->replaceScene(SelectCollection::scene());
        });
}


bool SelectLevel::init()

{
    if(!SceneStyle::init())
        return false;

    ADSoundManager::playMusic(InfoStyles::MENU_MUSIC);

    //Get curren collection
    const Collection* current_collection;
    current_collection =LevelSaves::getInstance().getCollectionById(
                _collection_id);

    //Get the screen start of cordinates
    const CCPoint ORIGIN = ADScreen::getOrigin();
    const CCSize VISIBLE_SIZE = ADScreen::getVisibleSize();
    const float SCALE = ADScreen::getScaleFactor();
    float x_middle_of_sheet = (VISIBLE_SIZE.width-133/SCALE)/2 + ORIGIN.x;
    float padding = 25/SCALE;
    showBackground(BackgroundType::Dark);

    showButtonBack();
    //window title
    cocos2d::CCLabelTTF* title_select_collection;


    title_select_collection = CCLabelTTF::create(current_collection->getName().c_str(),
                                                 ADLanguage::getFontName(),
                                                 InfoStyles::SIZE_MENU_TITLE);
    title_select_collection->setPositionX(x_middle_of_sheet+padding*2);

    title_select_collection->setPositionY(ORIGIN.y + VISIBLE_SIZE.height+25);

    title_select_collection->setColor(InfoStyles::COLOR_TITLE);
    this->addChild(title_select_collection);
    title_select_collection->runAction(CCSequence::create(
                     CCEaseElasticOut::create(
                        CCMoveTo::create(1.0f,
                                         ccp(x_middle_of_sheet+padding*2,
                                           (ORIGIN.y + VISIBLE_SIZE.height-25/SCALE -
                                           title_select_collection->getContentSize().height*0.5f)))
                         ),
                     NULL
                 ));

    //menu
    CCMenu* menu =CCMenu::create();
    float position_menu_y = VISIBLE_SIZE.height -padding*0.25f -
            title_select_collection->getContentSize().height*0.5f;


    float collection_width = 0;
    float card_height = 0;
    float card_width = 0;
    int current_dificult;
    current_dificult = 0;
    for(unsigned int j = 0; j < 3; ++j)
    {
        current_dificult = j;
        Card* card;
        if (j == 0)
        {
            int star_number = SaveStarsManager::getInstance()->getStars(
                        _collection_id, j);

            card = Card::create(CCSprite::create(current_collection->getCollectionPartEasy().getImage().c_str()),
                                _("select_level.easy"),
                                star_number,CardType::WithBorder);

        }
        else if (j == 1)
        {
            int star_number = SaveStarsManager::getInstance()->getStars(
                        _collection_id, j);

            card = Card::create(CCSprite::create(current_collection->getCollectionPartMiddle().getImage().c_str()),
                                _("select_level.middle"),
                                star_number,CardType::WithBorder);

        }
        else if (j == 2)
        {
            int star_number = SaveStarsManager::getInstance()->getStars(
                        _collection_id, j);

            card = Card::create(CCSprite::create(current_collection->getCollectionPartDifficult().getImage().c_str()),
                                _("select_level.difficult"),
                                star_number,CardType::WithBorder);

        }

        ADMenuItem* button_card = ADMenuItem::create(card);
        button_card->setAnchorPoint(ccp(0.5f,0.5f));
        float one_card_width = 340/SCALE;
        collection_width += one_card_width;
        card_height = button_card->getContentSize().height;
        card_width = button_card->getContentSize().width;
        button_card->setPositionY(ORIGIN.y+button_card->getContentSize().height*0.5f);
        button_card->setPositionX(one_card_width*j + button_card->getContentSize().width*0.5f);
        CollectionID id = current_collection->getID();

        button_card->setClickAction([id,current_dificult,this](){
            hideEverything([id,current_dificult](){
                    CCDirector::sharedDirector()->replaceScene(LevelScene::scene(id,current_dificult));
                });

        });
        menu->addChild(button_card);

        card->setCardColor(LevelSaves::getInstance().getColor(_collection_id));
        card->setTitleColor(InfoStyles::COLOR_WHITE);
        if (j == 0)
        {
            card->setBorderType(BorderType::Easy);
        }
        else if (j == 1)
        {
            card->setBorderType(BorderType::Middle);
        }
        else if (j == 2)
        {
            card->setBorderType(BorderType::Difficult);
        }

        /////////////////////////////
        float target_scale = card->getScale();
        float first_scale  = target_scale*0.9f;
        button_card->setScale(first_scale);

        button_card->runAction(CCSequence::create(
                                   CCDelayTime::create(0.0f),
                                   CCEaseElasticOut::create(
                                     CCScaleTo::create(0.7f,target_scale),
                                       0.4f),
                                   NULL
                               ));
    }

    menu->setAnchorPoint(ccp(0,0));
    float position_menu_x = VISIBLE_SIZE.width -collection_width ;
    menu->setPositionX(ORIGIN.x +position_menu_x*0.5f);
    menu->setPositionY((position_menu_y-card_height)*0.5f);
    this->addChild(menu);
    return true;

}

void SelectLevel::hideEverything(ADCallFunc::Action action)
{
    ///////////////////////////////////////////////////////////
    //next action
    this->runAction(
                CCSequence::createWithTwoActions(
                    CCDelayTime::create(0.6f),
                    ADCallFunc::create(action)
                    )
                );
}
