#include "SettingsManager.h"
#include <ADLib/Storage.h>
#include <ADLib/Device/ADSoundManager.h>

SettingsManager SettingsManager::instance;

SettingsManager* SettingsManager::getInstance( )
{
    return &instance;
}
SettingsManager::SettingsManager()
{

    //Add blocks to storage
    CONNECT(ADStorage::signalCreateBlocks, this,
            &SettingsManager::initStorageBlocks);

    //Check if first launch and add bonuses
    CONNECT(ADStorage::signalInitialDataLoaded, this,
            &SettingsManager::initDefaultValues);

}

void SettingsManager::initStorageBlocks()
{
    ADStorage::createValueBlock<SettingsInfo>(BLOCK_SETTINGS);
}

void SettingsManager::initDefaultValues()
{
    const SettingsInfo default_info = SettingsInfo(true, true);

    if(!ADStorage::hasValue(BLOCK_SETTINGS))
    {
        //if there is no info in storage
        ADStorage::setValue(BLOCK_SETTINGS, default_info);
    }
    else
    {
        //normal case
        //if there is some problem set empty info
        _info = ADStorage::getValue(BLOCK_SETTINGS, default_info);
    }

    //set to ADSound turn on/off music
    correctMusic();
    correctSound();

}

void SettingsManager::correctMusic()
{
    if(_info.isMusic())
        ADSoundManager::turnOnMusic();
    else if(!_info.isMusic())
        ADSoundManager::turnOffMusic();
}

void SettingsManager::correctSound()
{
    if(_info.isSound())
        ADSoundManager::turnOnSound();
    else if(!_info.isSound())
        ADSoundManager::turnOffSound();
}

bool SettingsManager::isMusicOn()
{
    return _info.isMusic();
}

bool SettingsManager::isSoundOn()
{
    return _info.isSound();
}

void SettingsManager::setMusic(bool music)
{
    _info.setMusic(music);


    updateValues();
    correctMusic();
}

void SettingsManager::setSound(bool sound)
{
    _info.setSound(sound);
    updateValues();
    correctSound();
}

void SettingsManager::updateValues()
{
    ADStorage::setValue<SettingsInfo>(BLOCK_SETTINGS, _info);
}


ADStreamOut& operator<<(ADStreamOut& os, const SettingsInfo& info)
{
    os << info.isMusic()<<info.isSound();
    return os;
}

ADStreamIn& operator>>(ADStreamIn& is, SettingsInfo& info)
{
    bool music;
    bool sound;

    is >> music >> sound;

    if(is.isOK())
    {
        info.setMusic(music);
        info.setSound(sound);
    }
    return is;
}

bool operator<(const SettingsInfo& info1, const SettingsInfo& info2)
{
    if((info1.isMusic() && !info2.isMusic()) ||
            (info1.isSound() && !info2.isSound()))
    {
        return true;
    }
    else if((info2.isMusic() && !info1.isMusic()) ||
            (info2.isSound() && !info1.isSound()))
    {
        return false;
    }
    else return true;
}
