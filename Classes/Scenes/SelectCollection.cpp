#include "SelectCollection.h"
#include "MainMenu.h"
#include "Draw/Card.h"
#include "InfoStyles.h"
#include "Logic/LevelSaves.h"
#include "Logic/Collection.h"
#include <vector>
using namespace cocos2d;

SelectCollection::SelectCollection()
{
}

CCScene* SelectCollection::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    // 'layer' is an autorelease object
    SelectCollection *layer = SelectCollection::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}


SelectCollection* SelectCollection::create()
{

    SelectCollection *pRet = new SelectCollection();
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

void SelectCollection::onBackClick()
{

    CCDirector::sharedDirector()->replaceScene(MainMenu::scene());
}


bool SelectCollection::init()

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
    title_select_collection = CCLabelTTF::create(_("select_collection.title"),
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
    LevelSaves s;
    s.readLevels();
    const std::vector<Collection>& collect = s.getCollections();
    //menu
    CCMenu* menu =CCMenu::create();
    menu->setPosition(ccp(0,0));

    this->addChild(menu);

    for(unsigned int i = 0; i < collect.size(); ++i)
    {


        Card* card = Card::create(CCSprite::create(collect[i].getImage().c_str()),
                                  collect[i].getName(),
                                  2,CardType::WithoutBorder);

        ADMenuItem* button_card = ADMenuItem::create(card);
        //CONNECT(button_card->signalOnClick, this, &SelectCollection::onCardClick);
        button_card->setAnchorPoint(ccp(0,0));
        button_card->setPositionY(200/SCALE);
        button_card->setPositionX(200+i*200 +i*100/SCALE);
        CollectionID id = collect[i].getID();
        button_card->setClickAction([id](){
            CCLog("Collection click: %d", id);
        });
        menu->addChild(button_card);

        card->setCardColor(collect[i].getColor());
        card->setTitleColor(InfoStyles::COLOR_WHITE);
        //card->setBorderType(BorderType::None);
    }



    return true;




}
void SelectCollection::onCardClick()
{
    CCLog("CardClick Clicked");
}
