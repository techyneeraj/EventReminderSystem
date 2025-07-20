#include "eventmanager.h"
#include <iostream>
#include <fstream>

void EventManager::addEvent(const Event &event) {
    events.push_back(event);
}

void EventManager::listEvents() const {
    if (events.empty()) {
        std::cout << "No events found.\n";
        return;
    }

    for (size_t i = 0; i < events.size(); ++i) {
        std::cout << i + 1 << ". " << events[i].getTitle()
                  << " on " << events[i].getDate()
                  << " at " << events[i].getTime();
        if (events[i].isPast()) std::cout << " (Expired)";
        std::cout << "\n";
    }
}

void EventManager::deleteEvent(int index) {
    if (index >= 0 && index < (int)events.size()) {
        events.erase(events.begin() + index);
    }
}

void EventManager::editEvent(int index, const Event &updatedEvent) {
    if (index >= 0 && index < (int)events.size()) {
        events[index] = updatedEvent;
    }
}

void EventManager::saveToFile(const std::string &filename) const {
    std::ofstream out(filename);
    for (const auto &ev : events) {
        out << ev.getTitle() << "\n"
            << ev.getDate() << "\n"
            << ev.getTime() << "\n";
    }
}

void EventManager::loadFromFile(const std::string &filename) {
    std::ifstream in(filename);
    if (!in) return;

    std::string title, date, time;
    while (getline(in, title) && getline(in, date) && getline(in, time)) {
        events.emplace_back(title, date, time);
    }
}

void EventManager::checkUpcomingEvents() const {
    std::cout << "\n⏰ Events Due Soon (within 5 minutes):\n";
    bool found = false;
    for (const auto &ev : events) {
        if (ev.isDueSoon()) {
            std::cout << "  ⚠ " << ev.getTitle()
                      << " at " << ev.getDate()
                      << " " << ev.getTime() << "\n";
            found = true;
        }
    }
    if (!found) std::cout << "  No upcoming events.\n";
}
