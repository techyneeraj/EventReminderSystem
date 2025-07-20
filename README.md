📌 Event Reminder System (C++ Console App)
The Event Reminder System is a simple, console-based C++ application that allows users to schedule, view, edit, and delete personal events. It checks for upcoming events and displays alerts if any are due within the next 5 minutes. The project demonstrates practical use of Object-Oriented Programming (OOP) principles without any GUI or external libraries.

🚀 Features
Add new events with title, date, and time

View a list of all scheduled events

Edit or delete existing events

Alert notification in the terminal for events due within 5 minutes

Uses standard C++ and STL only — no Qt, no GUI, no frameworks

🛠 Technologies Used
C++17

Standard Library (STL)

Console I/O

Date/Time logic using <chrono>, <ctime>

📂 Project Structure
csharp
Copy code
EventReminderSystem/
├── main.cpp
├── event.h / event.cpp
├── eventmanager.h / eventmanager.cpp
├── eventreminder.exe (ignored)
├── .gitignore
└── README.md
📦 How to Compile
bash
Copy code
g++ main.cpp event.cpp eventmanager.cpp -o eventreminder
▶️ How to Run
bash
Copy code
./eventreminder
You’ll see a menu with options to add, list, edit, or delete events.

🔔 Alert System
Whenever you run the program, it checks if any event is due within the next 5 minutes and shows an alert message at the top.
