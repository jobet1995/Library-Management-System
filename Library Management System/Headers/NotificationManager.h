#ifndef NOTIFICATIONMANAGER_H
#define NOTIFICATIONMANAGER_H

#include <string>
#include <vector>
#include <ctime>

struct Notification {
    int id;
    std::string message;
    std::time_t timestamp;
    bool isRead;
};

class NotificationManager {
private:
    std::vector<Notification> notifications;
    int nextId;

public:
    NotificationManager();
    void addNotification(const std::string& message);
    void markAsRead(int id);
    std::vector<Notification> getUnreadNotifications() const;
    std::vector<Notification> getAllNotifications() const;
    void clearAll();
};

#endif
