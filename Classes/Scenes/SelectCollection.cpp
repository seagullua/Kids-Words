#include "SelectCollection.h"
#include "MainMenu.h"
#include "Draw/Card.h"
#include "InfoStyles.h"
#include "Logic/LevelSaves.h"
#include "Logic/Collection.h"
#include <vector>
#include <ADLib/Rendering/ADScrollView.h>
#include "SelectLevel.h"
#include "Managers/StarsCollectionManager.h"
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
    const std::vector<Collection>& collect = LevelSaves::getInstance().getCollections();
    //menu
    CCMenu* menu =CCMenu::create();
    float padding_title = padding*0.25f +
            title_select_collection->getContentSize().height*0.5f;

    float position_menu_y = VISIBLE_SIZE.height -padding_title;

    //this->addChild(menu);
    float collection_width = 0;
    float card_height = 0;
    for(unsigned int i = 0; i < collect.size(); ++i)
    {


        CollectionID id = collect[i].getID();
        int star_number = StarsCollectionManager::getInstance()->getStars(
                    id);

        Card* card = Card::create(CCSprite::create(collect[i].getImage().c_str()),
                                  collect[i].getName(),
                                  star_number,CardType::WithoutBorder);

        ADMenuItem* button_card = ADMenuItem::create(card);
        //CONNECT(button_card->signalOnClick, this, &SelectCollection::onCardClick);
        button_card->setAnchorPoint(ccp(0.5f,0.5f));
        float one_card_width = 340/SCALE;
        card_height=button_card->getContentSize().height;
        collection_width += one_card_width;
        button_card->setPositionY(button_card->getContentSize().height*0.5f);
        button_card->setPositionX(one_card_width*i + button_card->getContentSize().width*0.5f);
         button_card->setClickAction([id](){
            //CCLog("Collection click: %d", id);
            CCDirector::sharedDirector()->replaceScene(SelectLevel::scene(id));
        });


        menu->addChild(button_card);

        card->setCardColor(collect[i].getColor());
        card->setTitleColor(InfoStyles::COLOR_WHITE);
        //card->setBorderType(BorderType::None);
    }

    menu->setAnchorPoint(ccp(0,0));
    menu->setPosition(ccp(100/SCALE,(position_menu_y-card_height)*0.5f));

    CCSize zone_size(VISIBLE_SIZE.width, VISIBLE_SIZE.height-padding_title*3);
    CCSize collections_size(collection_width, zone_size.height);

    //Create layer to fit all tiles
    CCLayer *layer = CCLayer::create();
    layer->setContentSize(collections_size);

    //Create scroll view for this layer
    ADScrollView* collections_scroll_view =
            ADScrollView::create(zone_size, layer);
    this->addChild(collections_scroll_view);
    collections_scroll_view->addChild(menu);
    collections_scroll_view->setPosition(ORIGIN);
    collections_scroll_view->updateInset();
    collections_scroll_view->setDirection(ADScrollView::Direction::Horizontal);
    collections_scroll_view->setContentOffset(collections_scroll_view->maxContainerOffset(), false);
    collections_scroll_view->addHighPriorityTouchListener(menu);

    //menu->setPosition();
    return true;




}
void SelectCollection::onCardClick()
{
    CCLog("CardClick Clicked");
}
