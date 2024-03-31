# Expense Management System (Under Development)

This is an Expense Management System developed as part of the Project Track assignment at the Programming Club, NFSU. The system is currently under development and aims to provide users with a comprehensive tool for tracking and managing their expenses, income, and transfers.

## Features

- Add expenses with categories
- Add income with categories
- Record transfers (borrowing or lending)
- View detailed records of expenses, income, and transfers
- View summary of current balance, total expenses, total income, and category-wise breakdowns
- Set the current day for tracking purposes

## Known Issues and Limitations

- **Limited Record Storage**: The current implementation uses fixed-size arrays to store records, limiting the number of entries that can be added.
- **No Persistent Data Storage**: The program does not currently support saving data to a file or database, meaning all records are lost when the program is closed.
- **Limited Editing Capabilities**: While deleting records is supported, editing existing records is not yet implemented.
- **No Date Handling**: The program uses a simple "day" concept instead of handling actual dates, which may be limiting for long-term tracking.
- **No User Authentication**: The program does not have any user authentication or data separation, making it suitable for single-user use only.

## Usage

1. Compile the C++ source code using a compatible compiler.
2. Run the compiled program.
3. The program will display a menu with various options.
4. Enter the corresponding choice number to perform the desired operation.
5. Follow the prompts to provide the necessary input (e.g., expense name, amount, category) for each operation.
6. To exit the program, select the "Exit application" option.

## Contributing

As this is an ongoing project, contributions are welcome. If you find any issues or have suggestions for improvements, please open an issue or submit a pull request. Please note that this project is primarily for educational purposes and may not be actively maintained beyond the scope of the assignment.

## Acknowledgments

This project is being developed as part of the Programming Club's Project Track at NFSU. Special thanks to the club mentors and organizers for their guidance and support.