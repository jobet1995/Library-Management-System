#include "Headers/NotificationManager.h"
#include <algorithm>
#include <ctime>

NotificationManager::NotificationManager() : nextId(1) {}

void NotificationManager::addNotification(const std::string& message) {
    Notification notif;
    notif.id = nextId++;
    notif.message = message;
    notif.timestamp = std::time(nullptr);
    notif.isRead = false;
    notifications.push_back(notif);
}

void NotificationManager::markAsRead(int id) {
    auto it = std::find_if(notifications.begin(), notifications.end(),
                           [id](const Notification& n) { return n.id == id; });
    if (it != notifications.end()) it->isRead = true;
}

std::vector<Notification> NotificationManager::getUnreadNotifications() const {
    std::vector<Notification> unread;
    for (const auto& n : notifications) {
        if (!n.isRead) unread.push_back(n);
    }
    return unread;
}

std::vector<Notification> NotificationManager::getAllNotifications() const {
    return notifications;
}

void NotificationManager::clearAll() {
    notifications.clear();
    nextId = 1;
}
