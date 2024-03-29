#include "AdsManager.h"
#include <ADLib.h>

AdsManager AdsManager::instance;

AdsManager* AdsManager::getInstance( )
{
    return &instance;
}
AdsManager::AdsManager()
{

    //Add blocks to storage
    CONNECT(ADStorage::signalCreateBlocks, this,
            &AdsManager::initStorageBlocks);

    //Check if first launch and add bonuses
    CONNECT(ADStorage::signalInitialDataLoaded, this,
            &AdsManager::initDefaultValues);

}

void AdsManager::initStorageBlocks()
{
    ADStorage::createValueBlock<int32_t>(BLOCK_ADS);
}

void AdsManager::initDefaultValues()
{
    _ads_included = ADStorage::hasValue(BLOCK_ADS);
}


bool AdsManager::isAdsPurchased()
{
    return _ads_included;
}

void AdsManager::setAdsIncluded(bool current_ads)
{
    bool should_notify = false;
    if(!_ads_included)
    {
        should_notify = true;
    }
    _ads_included = current_ads;
    ADAds::disableAds();
    updateValues();

    if(should_notify)
    {
        emit signalAdsWasDisabled();
    }
}

void AdsManager::updateValues()
{
    if (_ads_included)
    {
        ADStorage::setValue<int32_t>(BLOCK_ADS, 1);

    }
    else
    {
        ADStorage::setValue<int32_t>(BLOCK_ADS, 0);

    }

}
