#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

// Function to get the card type
std::string getCardType(const std::string &cardNumber) {
    if (cardNumber.size() == 15 && (cardNumber.substr(0, 2) == "34" || cardNumber.substr(0, 2) == "37")) {
        return "American Express";
    }
    if (cardNumber.size() == 16 && (cardNumber.substr(0, 2) >= "51" && cardNumber.substr(0, 2) <= "55")) {
        return "MasterCard";
    }
    if (cardNumber.size() == 16 && (cardNumber.substr(0, 4) >= "2221" && cardNumber.substr(0, 4) <= "2720")) {
        return "MasterCard";
    }
    if (cardNumber.size() == 13 || cardNumber.size() == 16 && cardNumber[0] == '4') {
        return "Visa";
    }
    return "Unknown";
}

// Function to perform the Luhn algorithm
bool luhnCheck(const std::string &cardNumber) {
    int sum = 0;
    bool alternate = false;
    for (int i = cardNumber.length() - 1; i >= 0; i--) {
        int n = cardNumber[i] - '0';
        if (alternate) {
            n *= 2;
            if (n > 9) {
                n -= 9;
            }
        }
        sum += n;
        alternate = !alternate;
    }
    return (sum % 10 == 0);
}

int main() {
    std::string cardNumber;

    while (true) {
        std::cout << "Enter a credit card number (or 'quit' to exit): ";
        std::getline(std::cin, cardNumber);

        if (cardNumber == "quit") {
            std::cout << "Exiting program.\n";
            break;
        }

        // Remove any spaces or hyphens from the input
        cardNumber.erase(std::remove(cardNumber.begin(), cardNumber.end(), ' '), cardNumber.end());
        cardNumber.erase(std::remove(cardNumber.begin(), cardNumber.end(), '-'), cardNumber.end());

        if (cardNumber.empty()) {
            std::cout << "Invalid input. Please enter a valid credit card number or 'quit' to exit.\n";
            continue;
        }

        std::string cardType = getCardType(cardNumber);
        bool isValid = luhnCheck(cardNumber);

        std::cout << "Card Type: " << cardType << std::endl;
        if (isValid) {
            std::cout << "The credit card number is valid." << std::endl;
        } else {
            std::cout << "The credit card number is invalid." << std::endl;
        }

        // Clear input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}