#include "LevelEnd.h"
#include <ADLib/PopUp/ADPopUpWindow.h>
#include "InfoStyles.h"
#include "Scenes/SelectCollection.h"
#include "Logic/LevelSaves.h"
#include "Draw/Stars.h"
#include "Scenes/LevelScene.h"

using namespace cocos2d;
LevelEnd::LevelEnd(cocos2d::CCNode* parent,CollectionID collection_id,int stars_number, int difficult):
    IADStandardWindow(CCSize(1,1),
                      InfoStyles::COLOR_BLUE,
                      Animation::DownToTop),
    _collection_id(collection_id),
    _stars_number(stars_number),
    _difficult(difficult),
    _parent(parent)
{

}


void LevelEnd::onCollection()
{
    CCDirector::sharedDirector()->replaceScene(SelectCollection::scene());

}

void LevelEnd::onNextLesson()
{
    CCDirector::sharedDirector()->replaceScene(LevelScene::scene(_collection_id,_difficult));
 }

void LevelEnd::onCreate(cocos2d::CCNode *parent)
{
    //background
    CCSprite* background = CCSprite::create("pop-ups/pop-up-background.png");

    background->setPosition(ccp(0,0));
    parent->addChild(background);


    cocos2d::CCSize size = background->getContentSize();
    float x_middle = size.width / 2;
    const Collection* current_collection;
    current_collection =LevelSaves::getInstance().getCollectionById(
                _collection_id);

    //label
    cocos2d::CCLabelTTF* label = cocos2d::CCLabelTTF::create(current_collection->getName().c_str(),
                                                             ADLanguage::getFontName(),
                                                             InfoStyles::SIZE_MENU_TITLE_POP_UP);

    label->setColor(InfoStyles::COLOR_BLUE_LIGHT);
    label->setPosition(ccp(x_middle, size.height*0.8f));
    background->addChild(label);

    ///////////////////////////////////////////////////////

    cocos2d::CCMenu* menu = cocos2d::CCMenu::create();
    menu->setPosition(0,0);
    background->addChild(menu);

    float vertical = size.height * 0.25f;
    cocos2d::CCSize button_size(size.width*0.25,size.width*0.15);

    ///////////////////////////////////////////////////////
    // button_collection
    CCSprite* button_collection_image = CCSprite::create("pop-ups/level-end/level-end-button.png");

    ADMenuItem* button_collection = ADMenuItem::create(button_collection_image);


    button_collection->setPosition(ccp(size.width*0.275f, vertical));
    CONNECT(button_collection->signalOnClick,
            this,
            &LevelEnd::onCollection);
    button_collection->setColor(InfoStyles::COLOR_BLUE_LIGHT);
    CCLabelTTF* button_collection_title = CCLabelTTF::create(_("pop_up_end_level.collection.title"),
                                                             ADLanguage::getFontName(),
                                                             InfoStyles::SIZE_BUTTON_POP_UP);

    button_collection_title->setColor(InfoStyles::COLOR_WHITE);
    button_collection_title->setAnchorPoint(ccp(0.5f,0.5f));
    button_collection_title->setPosition(ccp(button_collection->getContentSize().width*0.5f,
                                             button_collection->getContentSize().height*0.5f));
    button_collection->addChild(button_collection_title);
    menu->addChild(button_collection);


    //////////////////////////////////////////////////////

    //button_lesson
    CCSprite* button_lesson_image = CCSprite::create("pop-ups/level-end/level-end-button.png");

    ADMenuItem* button_lesson = ADMenuItem::create(button_lesson_image);
    button_lesson->setPosition(ccp(size.width*0.725f, vertical));
    CONNECT(button_lesson->signalOnClick,
            this,
            &LevelEnd::onNextLesson);
    button_lesson->setColor(InfoStyles::COLOR_ORANGE);
    CCLabelTTF* button_lesson_title = CCLabelTTF::create(_("pop_up_end_level.lesson.title"),
                                                         ADLanguage::getFontName(),
                                                         InfoStyles::SIZE_BUTTON_POP_UP);

    button_lesson_title->setColor(InfoStyles::COLOR_WHITE);
    button_lesson_title->setAnchorPoint(ccp(0.5f,0.5f));
    button_lesson_title->setPosition(ccp(button_lesson->getContentSize().width*0.5f,
                                         button_lesson->getContentSize().height*0.5f));
    button_lesson->addChild(button_lesson_title);

    menu->addChild(button_lesson);
    // stars_node
    Stars* stars_node;
    stars_node = Stars::create(_stars_number);
    stars_node->setAnchorPoint(ccp(0.5f,0.5f));
    stars_node->setPositionX(background->getContentSize().width*0.5f);
    stars_node->setPositionY(background->getContentSize().height*0.55f);
    stars_node->setScale(2);
    background->addChild(stars_node);



}
