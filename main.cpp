#include <iostream>
#include "eventmanager.h"

int main() {
    EventManager manager;
    manager.loadFromFile("events.txt");
    manager.checkUpcomingEvents();  // alert check

    int choice;
    do {
        std::cout << "\n--- Event Reminder ---\n";
        std::cout << "1. Add Event\n";
        std::cout << "2. List Events\n";
        std::cout << "3. Edit Event\n";
        std::cout << "4. Delete Event\n";
        std::cout << "5. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string title, date, time;
            std::cout << "Enter title: ";
            getline(std::cin, title);
            std::cout << "Enter date (YYYY-MM-DD): ";
            getline(std::cin, date);
            std::cout << "Enter time (HH:MM): ";
            getline(std::cin, time);

            manager.addEvent(Event(title, date, time));
            manager.saveToFile("events.txt");

        } else if (choice == 2) {
            manager.listEvents();

        } else if (choice == 3) {
            int index;
            manager.listEvents();
            std::cout << "Enter event number to edit: ";
            std::cin >> index;
            std::cin.ignore();

            std::string title, date, time;
            std::cout << "New title: ";
            getline(std::cin, title);
            std::cout << "New date: ";
            getline(std::cin, date);
            std::cout << "New time: ";
            getline(std::cin, time);

            manager.editEvent(index - 1, Event(title, date, time));
            manager.saveToFile("events.txt");

        } else if (choice == 4) {
            int index;
            manager.listEvents();
            std::cout << "Enter event number to delete: ";
            std::cin >> index;
            manager.deleteEvent(index - 1);
            manager.saveToFile("events.txt");

        } else if (choice != 5) {
            std::cout << "Invalid option.\n";
        }

    } while (choice != 5);

    std::cout << "Goodbye!\n";
    return 0;
}
