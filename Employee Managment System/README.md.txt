# Employee Management System

This C++ program is an Employee Management System that allows users to perform various operations on employee records. It was built upon a similar project implemented in C as a part of a lab practical exam. The program utilizes object-oriented programming concepts and provides functionalities to add, display, search, update, and delete employee records.

## Features

- Add new employee records with details like name, employee number, and salary
- Display all employee records
- Search for employee records by employee number or name
- Update employee details such as name and salary
- Delete employee records
- Find the highest-paid employee

## Implementation Details

The program defines an `Employees` class that encapsulates the employee's data (employee number, name, and salary) and provides member functions to set and retrieve these values. An array of `Employees` objects is used to store the employee records.

### Deletion Algorithm

The deletion of an employee record is implemented as follows:

1. The user is prompted to enter the employee number (or search by name) of the record they want to delete.
2. If the employee number exists in the record, the program shifts all subsequent records one position to the left, overwriting the record to be deleted.
3. The last record in the array is reset to default values (employee number = 0, salary = 0, name = '\0').
4. The `stored_records` variable, which keeps track of the total number of records, is decremented by 1.

This approach effectively removes the desired record from the array and maintains the contiguous storage of the remaining records.

## Usage

1. Compile the C++ source code using a compatible compiler.
2. Run the compiled program.
3. The program will display a menu with various options.
4. Enter the corresponding choice number to perform the desired operation.
5. Follow the prompts to provide the necessary input (e.g., employee number, name, salary) for each operation.
6. To exit the program, select the "Exit the application" option (choice 0).

# Known Issues
1. Spaces in the text fields are not handled well and can cause unexpected behaviour
2. Not saving to file, all data is lost once the program is closed.

## Contributing

Contributions to this project are welcome. If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.
