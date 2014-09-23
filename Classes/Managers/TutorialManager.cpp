#include "TutorialManager.h"

TutorialManager TutorialManager::instance;

TutorialManager* TutorialManager::getInstance( )
{
      return &instance;
}
TutorialManager::TutorialManager()
{

    //Add blocks to storage
    CONNECT(ADStorage::signalCreateBlocks, this,
                   &TutorialManager::initStorageBlocks);

    //Check if first launch and add bonuses
    CONNECT(ADStorage::signalInitialDataLoaded, this,
                   &TutorialManager::initDefaultValues);

}

void TutorialManager::initStorageBlocks()
{
    ADStorage::createValueBlock<int32_t>(BLOCK_TUTORIAL);
}

void TutorialManager::initDefaultValues()
{
    _first_game = !ADStorage::hasValue(BLOCK_TUTORIAL);
}


bool TutorialManager::isFirstGame()
{
    return _first_game;
}

void TutorialManager::setIsNotFirstGame()
{
    _first_game = false;
    updateValues();
}

void TutorialManager::updateValues()
{
    ADStorage::setValue<int32_t>(BLOCK_TUTORIAL, 1);
}
