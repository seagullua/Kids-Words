#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H
#include <ADLib/Storage.h>


class SettingsInfo
{
public:
    SettingsInfo(bool music_on = true,
                 bool sound_on = true):
        _music(music_on),
        _sound(sound_on)
    {

    }


    const bool isMusic() const
    {
        return _music;
    }
    const bool isSound() const
    {
        return _sound;
    }

    void setMusic(bool music)
    {
        _music = music;
    }
    void setSound(bool sound)
    {
        _sound = sound;
    }

    friend ADStreamOut& operator<<(ADStreamOut& os, const SettingsInfo& info);
    friend ADStreamIn& operator>>(ADStreamIn& is, SettingsInfo& info);

private:
    bool _music;
    bool _sound;
};

bool operator<(const SettingsInfo& info1, const SettingsInfo& info2);

class SettingsManager: public HasSlots
{
    static const int BLOCK_SETTINGS = 30001;
public:
    static SettingsManager* getInstance();

    bool isMusicOn();
    bool isSoundOn();

    void setMusic(bool music);
    void setSound(bool sound);

private:
    static SettingsManager instance;

    SettingsManager();
    SettingsManager(SettingsManager const&);
    void operator=(SettingsManager const&);

    SettingsInfo _info;

    void updateValues();

    void initStorageBlocks();
    void initDefaultValues();

    void correctMusic();
    void correctSound();
};

#endif // SETTINGSMANAGER_H
