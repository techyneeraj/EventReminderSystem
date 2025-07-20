#ifndef EVENT_H
#define EVENT_H

#include <string>

class Event {
public:
    Event() = default;
    Event(const std::string &title, const std::string &date, const std::string &time);

    std::string getTitle() const;
    std::string getDate() const;
    std::string getTime() const;

    void setTitle(const std::string &title);
    void setDate(const std::string &date);
    void setTime(const std::string &time);

    bool isDueSoon(int minutesThreshold = 5) const;
    bool isPast() const;

private:
    std::string title;
    std::string date;
    std::string time;
};

#endif
