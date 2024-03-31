# Billmaker Custom

This is a C++ program that generates a formatted bill for a retail store. It prompts the user to enter the bill number and details of the products purchased, including the product name, unit price, and quantity. The program then calculates the total amount, applies a 10% discount, and displays the final amount to be paid.

## Features

- Accepts user input for the bill number and product details
- Calculates the total amount based on the unit price and quantity of each product
- Applies a custom discount on the total amount
- Generates a formatted bill with product details, total amount, discount, and final amount to be paid
- Supports up to 100 products in a single bill

## Usage

1. Compile the C++ code using a compatible compiler.
2. Run the compiled program.
3. Enter the bill number, and the percentage of discount to be applied when prompted.
4. For each product, enter the name, unit price, and quantity when prompted.
5. After entering all the products, the program will generate a formatted bill and display it on the console.

## Known Issues

1. Cannot handle whitespaces in names of the products
2. May not handle prices which are very large (>10,00,000) well due to static widths of fields.

## Contributing

Contributions to this project are welcome. If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.
