#include "AppDelegate.h"
//#include "Scenes/Loading.h"
#include "AppMacros.h"
#include "SimpleAudioEngine.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Scenes/Loading.h"
#include <ADLib/UTF8/ADUTF8.h>
#include <ADLib.h>
USING_NS_CC;


AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

class InAppDelegate : public ADInApp::Delegate
{
public:
    void purchaseSuccessful(const ADInApp::ProductID & id)
    {
        cocos2d::CCLog("Purchase %s finished successful", id.c_str());

    }
    void purchaseFailed(const ADInApp::ProductID & id,
                        const ADInApp::ErrorType error)
    {
        typedef ADInApp::ErrorType Error;
        if(error == ADInApp::ErrorType::BillingUnavaliable)
        {
            ADNotification::showNotification(_("iap.error.billing_unavaliable"));
        }
        else if(error == ADInApp::ErrorType::DeveloperError ||
                error == ADInApp::ErrorType::Error)
        {
            ADNotification::showNotification(_("iap.error.purchase_error"));
        }

        CCLog("Purchase %s failed", id.c_str());
    }

    void restorePurchasesSuccessfully()
    {
        ADNotification::showNotification(_("iap.restore_purchases.success"));
    }

    void restorePurchasesFailed()
    {
        ADNotification::showNotification(_("iap.restore_purchases.failed"));
    }
};

class VirtualCurrencyDelegate : public ADVirtualCurrency::Delegate
{
    void onCurrencyAdded(const unsigned int number)
    {

    }
};


void initInAppPurchases()
{
    typedef ADInApp::Product Product;
    Product disable_ads("disable_ads", "$0.99");

    ADStore store = ADInfo::getStore();
    if(store == ADStore::GooglePlay)
    {
        //it is a new key - do not delete
        ADInApp::setStoreKey("MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEArJf6WM+vkPCXquFJMRYC7Ld0lc1Q3nv99I1qpMkHTzNi1X9AioIZURRp73v8VoSdRjDytW8+TUEG5xtuDxojA+hWBap70xpkCbVFXV+bHlPmZ+uWbxtZax73rpByiYpSehmgrfzXCb1INFrPGj1vZdTLLALvg0wBt3QxGL742NRC5TPtm9O1m2xaPrUw6KmAH4oMWGcPrIE5KGrOkv5tAQw4+D1Ztx0P5hIrrUmNwH8jKM6ZwpgHAE1R9aHhQaEGemqvhw/3VpyU0CC3F4mLrQnHdhQEePgZtfrVs7zHs7D7fGCbRzsL0VjweHy8y95hjMQR2UtuxpCe1thBmWxtVQIDAQAB");

        disable_ads.setParameter("type","noconsumable");
     }
    else if(store == ADStore::SamsungStore)
    {
        ADInApp::setStoreKey("100000103339");
//TODO set parametr
        disable_ads.setParameter("samsung-id","000001017534");

    }
    else if(store == ADStore::AmazonStore)
    {
      //TODO set parametr
        disable_ads.setParameter("asku","disable_ads");
      }
    else if(store == ADStore::iTunes)
    {
      //TODO set parametr
        disable_ads.setParameter("asku","disable_ads");
      }

    ADInApp::addProduct(disable_ads);

    ADInApp::setDelegate(std::make_shared<InAppDelegate>());



}

/**
 * @brief Performs init and configuration of AdMob and home ads
 */
void initAds()
{

}

void initTapJoy()
{

}



bool AppDelegate::applicationDidFinishLaunching() {


    //Statistics in

    ADStatistics::startSession();
    ADInfo::getStore();

    //Language init
    std::string latin_font = "fonts/Comfortaa Bold.ttf";
    std::string latin_bmfont = "fonts/Comfortaa Bold.fnt";

    //std::string cyrilic_font = "fonts/Comfortaa.ttf";
    //std::string cyrilic_bmfont = "fonts/Comfortaa.fnt";

    ADLanguage::addSupportedLanguage("en", latin_font, latin_bmfont);
    ADLanguage::addSupportedLanguage("uk", latin_font, latin_bmfont);
    //ADLanguage::addSupportedLanguage("pt", latin_font, latin_bmfont);
    ADLanguage::addSupportedLanguage("ru", latin_font, latin_bmfont);
    //ADLanguage::addSupportedLanguage("hu", latin_font, latin_bmfont);
    //ADLanguage::addSupportedLanguage("de", latin_font, latin_bmfont);


    ADLanguage::setDefaultLanguage("en");
    ADLanguage::getLanguage();

    //Init facebook start

    //Init facebook end

    initInAppPurchases();
    initTapJoy();
    //initHighscoreServer();

    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();


    pDirector->setOpenGLView(pEGLView);

    CCSize frameSize = pEGLView->getFrameSize();

    CCSize designResolutionSize = designResolutionSize_;


        // Set the design resolution
    pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionNoBorder);
    CCSize vsize = pEGLView->getVisibleSize();



    float width_change = vsize.width / designResolutionSize.width;
    std::string resource_directory = "images-normal";
    float resource_scale = 1;

    if(frameSize.height < 500)
    {
        resource_directory = "images-small";
        resource_scale = 0.5;
    }

    std::vector<std::string> searchPath;
    searchPath.push_back(resource_directory);

    ADScreen::setDesignScale(resource_scale);
    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPath);
    pDirector->setContentScaleFactor(
                MIN(
                    mediumResource.size.height*resource_scale/
                    designResolutionSize.height/
                    width_change,

                    mediumResource.size.width*resource_scale/
                    designResolutionSize.width/
                    width_change));

    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    
    //std::ifstream is(CCFileUtils::sharedFileUtils()->fullPathFromRelativeFile());
    // create a scene. it's an autorelease object
    CCScene *pScene = Loading::scene();

    // run
    pDirector->runWithScene(pScene);



    initAds();

    //Init ADMenuItem
    ADMenuItem::setAllClicksAction([](){
        ADSoundManager::playSoundEffect("music/choose.wav");
    });

    ADStorage::loadInitialData();
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    ADDeviceEvents::onPause();


}
//#include "Core/MusicSettings.h"
//#include "Core/DrawLayer.h"
// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    ADDeviceEvents::onResume();



}
