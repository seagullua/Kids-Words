#include "main.h"
#include "../Classes/AppDelegate.h"
#include <Testing/ADDeviceEmulator.h>
#include <ADLib/Device/ADAds.h>
#include "Logic/LevelSaves.h"
using namespace cocos2d;

void openAllCollectionsScene(TestInfo info);
void openSelectLevelScene(TestInfo info, CollectionID id);
void openLevelScene(TestInfo info, CollectionID id, int difficulty);

int CALLBACK WinMain(
        _In_  HINSTANCE,
        _In_  HINSTANCE,
        _In_  LPSTR,
        _In_  int
        )
{
    //Create AppDelegate
    AppDelegate app;

    //Configure emulator
    ADDeviceEmulator* emulator = ADDeviceEmulator::getInstance();


    DeviceConfig custom(Device::Custom);
    custom.setDeviceName("Custom");
    custom.setScreenDencity(1.0);
    custom.setScreenWidth(1920);
    custom.setScreenHeight(1200);
    emulator->setCustomDevice(custom);


    emulator->setFitTheScreen(true);
    emulator->setDevice(Device::Galaxy_Tab2_7);
    //emulator->setDevice(Device::Galaxy_Tab2_7);
    //emulator->setDevice(Device::Galaxy_Tab2_10);
 //   emulator->setLanguage("en");
 //   emulator->setLanguage("ru");
    emulator->setLanguage("uk");
    emulator->setOrientation(Orientation::Landscape);

    //open all collections
    emulator->addTestCase([](TestInfo info)
    {
        openAllCollectionsScene(info);
    });

    //open one collection

    CollectionID collection_id;
    emulator->addTestCase([&collection_id](TestInfo info)
    {
        const std::vector<Collection>& collections = LevelSaves::getInstance().getCollections();
        collection_id=collections[0].getID();
        openSelectLevelScene(info,collection_id);
    });
    emulator->addTestCase([&collection_id](TestInfo info)
    {
        const std::vector<Collection>& collections = LevelSaves::getInstance().getCollections();
        collection_id=collections[1].getID();
        openSelectLevelScene(info,collection_id);
    });
    emulator->addTestCase([&collection_id](TestInfo info)
    {
        const std::vector<Collection>& collections = LevelSaves::getInstance().getCollections();
        collection_id=collections[2].getID();
        openSelectLevelScene(info,collection_id);
    });

    //open one level
    int difficulty = 0;

    emulator->addTestCase([&collection_id,&difficulty](TestInfo info)
    {
        const std::vector<Collection>& collections = LevelSaves::getInstance().getCollections();
        collection_id=collections[1].getID();
        openLevelScene(info,collection_id,difficulty);
    });
    //difficulty = 1;
    emulator->addTestCase([&collection_id,&difficulty](TestInfo info)
    {
        openLevelScene(info,collection_id,difficulty);
    });
    //difficulty = 2;
    emulator->addTestCase([&collection_id,&difficulty](TestInfo info)
    {
        openLevelScene(info,collection_id,difficulty);
    });



    emulator->addTestCase([&collection_id,&difficulty](TestInfo info)
    {
        const std::vector<Collection>& collections = LevelSaves::getInstance().getCollections();
        collection_id=collections[0].getID();
        openLevelScene(info,collection_id,difficulty);
    });
    //difficulty = 1;
    emulator->addTestCase([&collection_id,&difficulty](TestInfo info)
    {
        openLevelScene(info,collection_id,difficulty);
    });
    //difficulty = 2;
    emulator->addTestCase([&collection_id,&difficulty](TestInfo info)
    {
        openLevelScene(info,collection_id,difficulty);
    });

    return emulator->run();
}
#include "Scenes/SelectCollection.h"
void openAllCollectionsScene(TestInfo info)
{
    CCDirector::sharedDirector()->replaceScene(SelectCollection::scene());
    ADDeviceEmulator::runLater(2.5f, [info](){

        ADDeviceEmulator::createScreenShoot(info);
        info.finish();
    });
}
#include "Scenes/SelectLevel.h"
void openSelectLevelScene(TestInfo info,CollectionID id)
{
    CCDirector::sharedDirector()->replaceScene(SelectLevel::scene(id));
    ADDeviceEmulator::runLater(2.5f, [info](){

        ADDeviceEmulator::createScreenShoot(info);
        info.finish();
    });
}

#include "Scenes/LevelScene.h"
void openLevelScene(TestInfo info, CollectionID id, int difficulty)
{
    CCDirector::sharedDirector()->replaceScene(LevelScene::scene(id,difficulty));
    ADDeviceEmulator::runLater(2.5f, [info](){

        ADDeviceEmulator::createScreenShoot(info);
        info.finish();
    });
}
