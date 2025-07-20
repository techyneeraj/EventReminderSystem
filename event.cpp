#include "event.h"
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

Event::Event(const std::string &title, const std::string &date, const std::string &time)
    : title(title), date(date), time(time) {}

std::string Event::getTitle() const { return title; }
std::string Event::getDate() const { return date; }
std::string Event::getTime() const { return time; }

void Event::setTitle(const std::string &t) { title = t; }
void Event::setDate(const std::string &d) { date = d; }
void Event::setTime(const std::string &t) { time = t; }

bool Event::isPast() const {
    std::tm tm = {};
    std::istringstream ss(date + " " + time);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M");
    std::time_t event_time = std::mktime(&tm);

    std::time_t now = std::time(nullptr);
    return now > event_time;
}

bool Event::isDueSoon(int minutesThreshold) const {
    std::tm tm = {};
    std::istringstream ss(date + " " + time);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M");
    std::time_t event_time = std::mktime(&tm);

    std::time_t now = std::time(nullptr);
    double diff = std::difftime(event_time, now);
    return (diff > 0 && diff <= minutesThreshold * 60);
}
