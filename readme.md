📌 Event Reminder System (C++ OOP)
A simple terminal-based Event Reminder System built using C++ and Object-Oriented Programming concepts. It allows you to add, list, edit, and delete events, and also notifies you if any events are due within the next 5 minutes.

📁 Directory Structure
csharp
Copy
Edit
EventReminderSystem/
├── main.cpp
├── event.h
├── event.cpp
├── eventmanager.h
├── eventmanager.cpp
└── README.md
⚙️ Features
Add new events with date and time

View all scheduled events

Edit or delete existing events

Alerts if any event is due within 5 minutes of program start

Fully object-oriented (no GUI, no .ui files)

🧠 How It Works
The app checks all events at startup

If any event is scheduled within the next 5 minutes, it prints an alert

Events are not persistent between runs (stored in memory only)

🛠️ Build Instructions
✅ Requirements:
C++ compiler (MinGW or g++)

Windows PowerShell or Linux terminal

🧾 Compile:
bash
Copy
Edit
g++ main.cpp event.cpp eventmanager.cpp -o eventreminder.exe
If Permission denied, make sure eventreminder.exe is not running (close it from Task Manager or use Ctrl+C).

▶️ Run
bash
Copy
Edit
./eventreminder.exe
🔔 Alert Example
If system time is 04:40, and you add:

yaml
Copy
Edit
Enter title: Doctor Appointment  
Enter date: 2025-07-20  
Enter time: 04:44
Then immediately rerun the app:

bash
Copy
Edit
./eventreminder.exe