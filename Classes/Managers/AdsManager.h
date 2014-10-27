#ifndef ADSMANAGER_H
#define ADSMANAGER_H
#include <ADLib/Storage.h>

class AdsManager: public HasSlots
{
    static const int BLOCK_ADS = 60002;
public:

    static AdsManager* getInstance();
    Signal<> signalAdsWasDisabled;
    bool isAdsPurchased();
    void setAdsIncluded(bool current_ads);
private:
    static AdsManager instance;

    AdsManager();
    AdsManager(AdsManager const&);
    void operator=(AdsManager const&);
    bool _ads_included;
    void updateValues();
    void initStorageBlocks();
    void initDefaultValues();

};





#endif // ADSMANAGER_H
