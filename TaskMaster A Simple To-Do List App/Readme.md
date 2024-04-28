This project is a simple "To-Do List App" implemented in C. The application is designed to manage a list of tasks with functionality for adding, deleting, and viewing tasks based on their urgency. Here's a detailed description of the project:

---

## To-Do List App

### Overview
The To-Do List App is a console-based application written in C that helps users manage a list of tasks. It provides a simple interface for adding new tasks, deleting existing tasks by ID, and viewing tasks based on their urgency (urgent or non-urgent). This project can be used to understand basic operations with data structures, input validation, recursion, and handling simple authentication.

### Features
- **Authentication**: The app requires a valid username and password for access. After three incorrect password attempts, the account is locked.
- **Task Management**: Users can add new tasks with a title, description, and state (urgent or non-urgent). The app assigns a unique ID to each task.
- **Task Deletion**: Users can delete tasks by entering the task's unique ID.
- **Viewing Tasks**: Users can view all urgent and non-urgent tasks separately.
- **Random ID Generation**: Each task is assigned a random ID within a specified range to ensure uniqueness.

### User Workflow
1. **Authentication**: The user is prompted to enter a username and password. If the username and password are correct, the user can proceed to the main menu. If the password is incorrect three times, the program exits with a message indicating the account is locked.
2. **Main Menu**: Once authenticated, the user can choose from the following options:
    - Add a new task.
    - Delete a task by its ID.
    - Show all urgent tasks.
    - Show all non-urgent tasks.
    - Exit the application.
3. **Task Operations**: The user can perform various operations based on their choice. When adding a task, the user specifies the task title, description, and urgency (urgent or non-urgent). When deleting a task, the user provides the task ID.
4. **Exit**: The user can choose to exit the application from the main menu.

### Technical Highlights
- **Recursion**: Used in functions like `show_urgent_tasks`, `show_non_urgent_tasks`, and `find_task_index` to traverse through the task list.
- **Input Validation**: Ensures valid inputs, such as when users enter the task state or make choices from the menu.
- **Data Structure**: Uses an array of structs to represent tasks, allowing efficient storage and retrieval.
- **Clear Output Structure**: Includes separator lines between steps in the console output for improved readability.

### Use Cases
This To-Do List App is suitable for learning basic C programming concepts, including data structures, loops, recursion, and input validation. It can be used as a foundation for more complex task management applications or extended with additional features like task editing, deadlines, or priorities.

---

Let me know if you'd like more details on specific aspects of the project or if you'd like additional information on how to implement specific features.