#include "SelectCollection.h"
#include "MainMenu.h"
#include "Draw/Card.h"
#include "InfoStyles.h"
#include "Logic/LevelSaves.h"
#include "Logic/Collection.h"
#include <vector>
#include <ADLib/Rendering/ADScrollView.h>
#include "SelectLevel.h"
#include "Managers/SaveStarsManager.h"
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


    ADSoundManager::playMusic(InfoStyles::MENU_MUSIC);

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
    title_select_collection->setPosition(ccp(x_middle_of_sheet+padding*2,
                                          (ORIGIN.y + VISIBLE_SIZE.height + 25)));

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



    const std::vector<Collection>& collect = LevelSaves::getInstance().getCollections();
    //menu
    CCMenu* menu =CCMenu::create();
    float padding_title = 40/SCALE + title_select_collection->getContentSize().height*0.5f;

    float position_menu_y = VISIBLE_SIZE.height -padding_title;
    float collection_width = 0;
    float card_height = 0;
    float delay_time = 0.0f;
    for(unsigned int i = 0; i < collect.size(); ++i)
    {


        CollectionID id = collect[i].getID();
        int star_number = SaveStarsManager::getInstance()->getStarsCollection(
                    id);

        Card* card = Card::create(CCSprite::create(collect[i].getImage().c_str()),
                                  collect[i].getName(),
                                  star_number,CardType::WithoutBorder);

        ADMenuItem* button_card = ADMenuItem::create(card);
        button_card->setAnchorPoint(ccp(0.5f,0.5f));
        float one_card_width = 340/SCALE;
        card_height=button_card->getContentSize().height;
        collection_width += one_card_width*1.05f;
        button_card->setPositionY(button_card->getContentSize().height*0.5f);
        button_card->setPositionX(one_card_width*i + button_card->getContentSize().width*0.5f);
        button_card->setClickAction([id](){
            CCDirector::sharedDirector()->replaceScene(SelectLevel::scene(id));
        });


        menu->addChild(button_card);

        card->setCardColor(collect[i].getColor());
        card->setTitleColor(InfoStyles::COLOR_WHITE);

        /////////////////////////////////////
        float target_scale = card->getScale();
        float first_scale  = target_scale*0.9f;
        button_card->setScale(first_scale);

        //animation
        button_card->runAction(CCSequence::create(
                                   CCDelayTime::create(delay_time),
                                   CCEaseElasticOut::create(
                                     CCScaleTo::create(0.7f,target_scale),
                                       0.4f),
                                   NULL
                               ));
       //delay_time += 0.2f;
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
    collections_scroll_view->addRedirectTouchDelegate(menu);
    return true;

}
void SelectCollection::onCardClick()
{
    //CCLog("CardClick Clicked");
}
