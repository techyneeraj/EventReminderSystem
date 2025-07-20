#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "event.h"
#include <vector>
#include <string>

class EventManager {
public:
    void addEvent(const Event &event);
    void listEvents() const;
    void deleteEvent(int index);
    void editEvent(int index, const Event &updatedEvent);

    void saveToFile(const std::string &filename) const;
    void loadFromFile(const std::string &filename);

    void checkUpcomingEvents() const;

private:
    std::vector<Event> events;
};

#endif
