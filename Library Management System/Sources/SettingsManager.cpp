#include "Headers/SettingsManager.h"

SettingsManager::SettingsManager() {}

void SettingsManager::setSetting(const std::string& key, const std::string& value) {
    settings[key] = value;
}

std::string SettingsManager::getSetting(const std::string& key, const std::string& defaultValue) const {
    auto it = settings.find(key);
    if (it != settings.end()) {
        return it->second;
    }
    return defaultValue;
}

bool SettingsManager::hasSetting(const std::string& key) const {
    return settings.find(key) != settings.end();
}

void SettingsManager::removeSetting(const std::string& key) {
    settings.erase(key);
}

void SettingsManager::clearSettings() {
    settings.clear();
}
