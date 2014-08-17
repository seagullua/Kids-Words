#include "SelectLevel.h"
#include "SelectCollection.h"
#include "MainMenu.h"
#include "Draw/Card.h"
#include "InfoStyles.h"
#include "Logic/LevelSaves.h"
#include "Logic/Collection.h"
#include <vector>
#include <ADLib/Rendering/ADScrollView.h>
using namespace cocos2d;

SelectLevel::SelectLevel(CollectionID id)
{
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

    CCDirector::sharedDirector()->replaceScene(MainMenu::scene());
}


bool SelectLevel::init()

{
    if(!SceneStyle::init())
        return false;

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
    title_select_collection = CCLabelTTF::create(_("select_level.title"),
                                                 ADLanguage::getFontName(),
                                                 InfoStyles::SIZE_MENU_TITLE);
    //title_select_collection->setAnchorPoint(ccp(0.5, 1));
    title_select_collection->setPositionX(x_middle_of_sheet+padding*2);

    title_select_collection->setPositionY(ORIGIN.y +
                                          + VISIBLE_SIZE.height-padding*0.25f -
                                          title_select_collection->getContentSize().height*0.5f);

    title_select_collection->setColor(InfoStyles::COLOR_WHITE);
    this->addChild(title_select_collection);

    //Card* card = Card::create(CCSprite::create("card/color.png"),
    //                          "dddd ",
    //                          2,CardType::WithoutBorder);



    //LevelSaves::readLevels();
    const std::vector<Level>& level = LevelSaves::getInstance().getLevels(id);

    //menu
    CCMenu* menu =CCMenu::create();
    //    menu->setPosition(ccp(0,0));
    float position_menu_y = VISIBLE_SIZE.height -padding*0.25f -
            title_select_collection->getContentSize().height*0.5f;


    float collection_width = 0;
    float card_height = 0;


    for(unsigned int i = 0; i < level.size(); ++i)
    {

        if (i=0)
        {
            Card* card = Card::create(CCSprite::create(level[i].getImage().c_str()),
                                      _("select_level.easy",
                                        2,CardType::WithBorder);

        }
        else if (i=1)
        {
            Card* card = Card::create(CCSprite::create(level[i].getImage().c_str()),
                                      _("select_level.middle",
                                        2,CardType::WithBorder);

        }
        else if (i=2)
        {
            Card* card = Card::create(CCSprite::create(level[i].getImage().c_str()),
                                      _("select_level.difficult",
                                        2,CardType::WithBorder);

        }

        ADMenuItem* button_card = ADMenuItem::create(card);
        //CONNECT(button_card->signalOnClick, this, &SelectCollection::onCardClick);
        button_card->setAnchorPoint(ccp(0.5f,0.5f));
        float one_card_width = 340/SCALE;
        collection_width += one_card_width;
        card_height=button_card->getContentSize().height;
        button_card->setPositionY(button_card->getContentSize().height*0.5f);
        button_card->setPositionX(one_card_width*i + button_card->getContentSize().width*0.5f);
        CollectionID id = level[i].getID();
        button_card->setClickAction([id](){
            CCLog("Level click: %d", id);
        });
        menu->addChild(button_card);

        card->setCardColor(InfoStyles::COLOR_ORANGE);
        card->setTitleColor(InfoStyles::COLOR_WHITE);
        if (i=0)
        {
            card->setBorderType(BorderType::Easy);
        }
        else if (i=1)
        {
            card->setBorderType(BorderType::Middle);
        }
        else if (i=2)
        {
            card->setBorderType(BorderType::Difficult);
        }
    }

    menu->setAnchorPoint(ccp(0,0));
    menu->setPosition(ccp(100/SCALE,(position_menu_y-card_height)*0.5f));
    this->addChild(menu);
    //menu->setPosition();
    return true;




}
void SelectLevel::onCardClick()
{
    CCLog("CardClick Clicked");
}
