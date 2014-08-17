#include "Loading.h"

#include "SimpleAudioEngine.h"
#include <ADLib/Device/ADInApp.h>
#include "Scenes/MainMenu.h"
#include "Logic/LevelSaves.h"
using namespace cocos2d;
Loading::Loading() : _sprites_to_load(0), _loaded_sprites(0)
{
}
CCScene* Loading::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    // 'layer' is an autorelease object
    Loading *layer = Loading::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

void Loading::drawEverything(float)
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    CCSprite* logo = CCSprite::create("universal/logo.png");
    this->addChild(logo);

    logo->setPosition(ccp(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height/2));

}

void Loading::loadSprite(const char* name)
{
    _sprites_to_load++;

    CCTextureCache::sharedTextureCache()->
            addImageAsync(name, this, callfuncO_selector(Loading::loadingCallBack));
	
}
void Loading::hideLogo()
{
    this->runAction(CCCallFunc::create(this, callfunc_selector(Loading::openMenu)));
}

void Loading::openMenu()
{
    CCDirector::sharedDirector()->replaceScene(MainMenu::scene());
}

void Loading::loadingCallBack(CCObject *)
{
    _loaded_sprites++;

    if(_loaded_sprites == _sprites_to_load)
    {
        const float splash_screen_time = 1;

        this->runAction(CCSequence::create(
                            CCDelayTime::create(splash_screen_time),
                            CCCallFunc::create(this, callfunc_selector(Loading::hideLogo)),
                            NULL));


    }
}

#include "AppDelegate.h"
void Loading::initRW()
{
	//TODO: write cleanup
    //RW::onInit();
}
void Loading::addAll()
{
//    addSpriteToLoad("banners/mif_kids.png");

//    addSpriteToLoad("collection-menu/collection_button.png");
//    addPlistToLoad("collection-menu/collection_button.plist");

//    addSpriteToLoad("level-end/big_stars.png");
//    addPlistToLoad("level-end/big_stars.plist");

//    addSpriteToLoad("level-end/level_end.png");
//    addPlistToLoad("level-end/level_end.plist");

//    addSpriteToLoad("level-menu/level_buttons.png");
//    addPlistToLoad("level-menu/level_buttons.plist");

//    addSpriteToLoad("level-menu/save_stars.png");
//    addPlistToLoad("level-menu/save_stars.plist");

//    addSpriteToLoad("level-scene/flow.png");
//    addPlistToLoad("level-scene/flow.plist");

//    addSpriteToLoad("level-scene/level_stars.png");
//    addPlistToLoad("level-scene/level_stars.plist");

//    addSpriteToLoad("level-scene/level_novigation.png");
//    addPlistToLoad("level-scene/level_novigation.plist");

//    addSpriteToLoad("level-scene/line.png");
//    addSpriteToLoad("level-scene/line_v.png");
//    addSpriteToLoad("level-scene/progress_bar.png");
//    addSpriteToLoad("level-scene/progress_bar_title.png");


//    addSpriteToLoad("main-menu/facebook_logo.png");
//    addSpriteToLoad("main-menu/main-logo.png");
//    addSpriteToLoad("main-menu/play-button.png");
//    addSpriteToLoad("main-menu/settings-button.png");

//    addSpriteToLoad("pop-up/background.png");

//    addSpriteToLoad("settings-menu/flag.png");
//    addSpriteToLoad("settings-menu/music.png");
//    addSpriteToLoad("settings-menu/node.png");
//    addSpriteToLoad("settings-menu/settings_4Enjoy.png");
//    addSpriteToLoad("settings-menu/sound.png");

//    addSpriteToLoad("universal/back_button.png");
//    addSpriteToLoad("universal/game_background.jpg");
//    addSpriteToLoad("universal/white-background.png");
//    addSpriteToLoad("universal/x4Enjoy.png");

    LevelSaves::getInstance().readLevels();
    LevelSaves::getInstance().readLevels();
    LevelSaves::getInstance().readLevels();
    ADInApp::loadStore(ADInApp::Mode::Production);

//    //addSoundToLoad("music/silly_fun.mp3");
//    addMusicToLoad(MusicSettings::BACKGROUND_MUSIC);
//    addMusicToLoad(MusicSettings::LEVEL_SCENE_MUSIC);
//    addSoundToLoad("music/choose.wav");
//    addSoundToLoad("music/flow_click.wav");

}
void Loading::addSpriteToLoad(const char* sp)
{
	_q_sprites_to_load.push(sp);
}
void Loading::addMusicToLoad(const char* s)
{
	_q_music_to_load.push(s);
}
void Loading::addSoundToLoad(const char* s)
{
	_q_sound_to_load.push(s);
}
void Loading::addPlistToLoad(const char* s)
{
	_q_plists_to_load.push(s);
}
void Loading::loadAll()
{
	CCTextureCache* cache = CCTextureCache::sharedTextureCache();
	while(!_q_sprites_to_load.empty())
	{
		std::string str = _q_sprites_to_load.front();
		cache->addImage(str.c_str());
		_q_sprites_to_load.pop();
	}

	CocosDenshion::SimpleAudioEngine* engine = CocosDenshion::SimpleAudioEngine::sharedEngine();
	while(!_q_music_to_load.empty())
	{
		std::string str = _q_music_to_load.front();
		engine->preloadBackgroundMusic(str.c_str());
		_q_music_to_load.pop();
	}

	while(!_q_sound_to_load.empty())
	{
		std::string str = _q_sound_to_load.front();
		engine->preloadEffect(str.c_str());
		_q_sound_to_load.pop();
	}

	CCSpriteFrameCache* plist_cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	while(!_q_plists_to_load.empty())
	{
		std::string str = _q_plists_to_load.front();
		plist_cache->addSpriteFramesWithFile(str.c_str());
		_q_plists_to_load.pop(); 
	}
}
void Loading::onLoadFinished()
{
	const float splash_screen_time = float(SPLASH_SCREEN_TIME);


    this->runAction(CCSequence::create(
                        CCDelayTime::create(splash_screen_time),
                        CCCallFunc::create(this, callfunc_selector(Loading::hideLogo)),
                        NULL));

}

void Loading::loadAllAsync(float)
{
    addAll();
    loadAll();
    onLoadFinished();
}

bool Loading::init()
{
    if (!SceneStyle::init())
    {
        return false;
    }


	drawEverything(0);
	initRW();
    this->getScheduler()->scheduleSelector(SEL_SCHEDULE(&Loading::loadAllAsync), this, 0.1, 0, 0, false);

    return true;
}
