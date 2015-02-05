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
#include "InfoStyles.h"
#include "Managers/AdsManager.h"
#include <ADLib/Device/ADPushWoosh.h>
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
        if(id == InfoStyles::getPurchaseID())
        {
            AdsManager::getInstance()->setAdsIncluded(true);
        }
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
    Product disable_ads(InfoStyles::getPurchaseID(), "$1.99");
    ADInApp::setStoreKey(InfoStyles::getStoreID());
    ADStore store = ADInfo::getStore();
    if(store == ADStore::GooglePlay)
    {
        disable_ads.setParameter("type","non-consumable");
    }

    ADInApp::addProduct(disable_ads);
    ADInApp::setDelegate(std::make_shared<InAppDelegate>());

}

/**
 * @brief Performs init and configuration of AdMob and home ads
 */
void initAds()
{
    //ADStore store = ADInfo::getStore();
    //ADPlatform platform = ADInfo::getPlatform();

    std::stringstream pid_interstitial;


    pid_interstitial << "ca-app-pub-" << 16126979 << 60946304 << "/";



    //ca-app-pub-1612697960946304/5795034672


    //   ABC Words [English] iOS: 		ca-app-pub-1612697960946304/9144034273
    //   ABC Words [English] Android:	ca-app-pub-1612697960946304/1760368271
    //   ABC Words [English] WP8:		ca-app-pub-1612697960946304/3097500672
    if(ADInfo::getPlatform() == ADPlatform::Android)
        pid_interstitial << 1760368271;
    else if(ADInfo::getPlatform() == ADPlatform::iOS)
        pid_interstitial << 9144034273;
    else if(ADInfo::getPlatform() == ADPlatform::WindowsPhone)
        pid_interstitial << 3097500672;



    if(!InfoStyles::showAds())
    {
        ADAds::disableAds();
    }
    else
    {
        ADAds::registerInterstitialType(pid_interstitial.str());
        ADFullScreenAds::prepare();
    }

}

void initTapJoy()
{

}



bool AppDelegate::applicationDidFinishLaunching() {


    //Statistics in
    //init statistics

    if(ADInfo::getPlatform() == ADPlatform::Android)
        ADStatistics::setApplicationKey("GS5YS5P2RGG23FRJ83KJ");
    else if(ADInfo::getPlatform() == ADPlatform::iOS)
        ADStatistics::setApplicationKey("98NSHB3Q5BKKHTCQPXHY");
    else if(ADInfo::getPlatform() == ADPlatform::WindowsPhone)
        ADStatistics::setApplicationKey("H9343PB6S9J594P3XWNZ");




    ADStatistics::startSession();
    ADInfo::getStore();

    //Language init
    std::string latin_font = "fonts/Comfortaa Bold.ttf";
    std::string latin_bmfont = "fonts/Comfortaa Bold.fnt";
    
    if(ADInfo::getPlatform() == ADPlatform::iOS)
    {
        latin_font = "fonts/Comfortaa.ttf";
        latin_bmfont = "fonts/Comfortaa.fnt";
    }

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

//    if(frameSize.height < 500)
//    {
//        resource_directory = "images-small";
//        resource_scale = 0.5;
//    }

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
    pDirector->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    
    //std::ifstream is(CCFileUtils::sharedFileUtils()->fullPathFromRelativeFile());
    // create a scene. it's an autorelease object
    CCScene *pScene = Loading::scene();

    // run
    pDirector->runWithScene(pScene);



    initAds();

    if(InfoStyles::VERSION != Version::NoAds)
    {
        ADPushWoosh::inizialize("FC464-C9DF1", "511773446712");
    }


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
