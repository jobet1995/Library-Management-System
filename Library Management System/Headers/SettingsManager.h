#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <string>
#include <unordered_map>

class SettingsManager {
private:
    std::unordered_map<std::string, std::string> settings;

public:
    SettingsManager();

    void setSetting(const std::string& key, const std::string& value);
    std::string getSetting(const std::string& key, const std::string& defaultValue = "") const;
    bool hasSetting(const std::string& key) const;
    void removeSetting(const std::string& key);
    void clearSettings();
};

#endif
