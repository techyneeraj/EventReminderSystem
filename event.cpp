#include "event.h"
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;

Event::Event(const string &title, const string &date, const string &time)
    : title(title), date(date), time(time) {}

string Event::getTitle() const { return title; }
string Event::getDate() const { return date; }
string Event::getTime() const { return time; }

void Event::setTitle(const string &t) { title = t; }
void Event::setDate(const string &d) { date = d; }
void Event::setTime(const string &t) { time = t; }

bool Event::isPast() const {
    tm tm = {};
    istringstream ss(date + " " + time);
    ss >> get_time(&tm, "%Y-%m-%d %H:%M");
    time_t event_time = mktime(&tm);

    time_t now = time(nullptr);
    return now > event_time;
}

bool Event::isDueSoon(int minutesThreshold) const {
    tm tm = {};
    istringstream ss(date + " " + time);
    ss >> get_time(&tm, "%Y-%m-%d %H:%M");
    time_t event_time = mktime(&tm);

    time_t now = time(nullptr);
    double diff = difftime(event_time, now);
    return (diff > 0 && diff <= minutesThreshold * 60);
}
