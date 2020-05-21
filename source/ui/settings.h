#ifndef _SETINGS_H_
#define _SETTINGS_H_


#include <switch/services/ncm_types.h>


typedef enum
{
    SettingFlag_Off = 0,
    SettingFlag_On = 1,
} SettingFlag;

typedef enum
{
    SettingsInstallLocation_Default = -1,
    SettingsInstallLocation_User = NcmStorageId_BuiltInUser,
    SettingsInstallLocation_SdCard = NcmStorageId_SdCard,
} SettingsInstallLocation;

typedef struct {
    SettingFlag g_install_base;
    SettingFlag g_install_upp;
    SettingFlag g_install_dlc;
    SettingsInstallLocation g_install_base_location;
    SettingsInstallLocation g_install_upp_location;
    SettingsInstallLocation g_install_dlc_location;
    SettingFlag g_overwrite_newer_version;
    SettingFlag g_install_lower_key_gen;
    SettingFlag g_install_standard_crypto;
    SettingFlag g_install_backlight;
    SettingFlag g_sounds_sound;
    SettingFlag g_sounds_music;
} SettingsConfig;
extern SettingsConfig settingsConfig;

#endif