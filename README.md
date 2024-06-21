# Credit Card Validator
- This is a simple command-line tool written in C++ for validating credit card numbers. 
- It allows users to input credit card numbers and determines whether they are valid or not, 
as well as identifies the card type (Visa, MasterCard, American Express, or Unknown).

## Features
- Validates credit card numbers using the Luhn algorithm.
- Determines the type of credit card (Visa, MasterCard, American Express, or Unknown).
- Supports multiple credit card number inputs in one run.
- Provides clear instructions for user interaction.
## Usage
1. Compilation:
- Compile the program using a C++ compiler such as g++.
- g++ -o credit_card_validator credit_card_validator.cpp
2. Running the Program:
- Execute the compiled binary.
- ./credit_card_validator
3. Input:
- Enter a credit card number when prompted.
- Repeat for additional credit card numbers or type 'quit' to exit the program.

## Example
- Enter a credit card number (or 'quit' to exit): 5555-5555-5555-4444
- Card Type: MasterCard
- The credit card number is valid.
- Enter a credit card number (or 'quit' to exit): 4111 1111 1111 1111
- Card Type: Visa
- The credit card number is valid.
- Enter a credit card number (or 'quit' to exit): quit
- Exiting program.
