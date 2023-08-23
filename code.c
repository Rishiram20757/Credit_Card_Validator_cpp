#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

// Function to check if a string contains only digits
bool isDigitsOnly(const std::string& str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

// Function to validate a credit card number using the Luhn algorithm
bool isValidCreditCard(const std::string& cardNumber) {
    int sum = 0;
    bool alternate = false;

    for (int i = cardNumber.length() - 1; i >= 0; i--) {
        int digit = cardNumber[i] - '0';

        if (alternate) {
            digit *= 2;
            if (digit > 9) {
                digit = (digit % 10) + 1;
            }
        }

        sum += digit;
        alternate = !alternate;
    }

    return (sum % 10 == 0);
}

int main() {
    std::string cardNumber;

    std::cout << "Credit Card Validator" << std::endl;

    while (true) {
        std::cout << "Enter a credit card number (0 to exit): ";
        std::getline(std::cin, cardNumber);

        if (cardNumber == "0") {
            break;
        }

        // Remove spaces and non-digit characters from input
        cardNumber.erase(std::remove_if(cardNumber.begin(), cardNumber.end(), [](char c) {
            return !isdigit(c);
        }), cardNumber.end());

        if (!isDigitsOnly(cardNumber)) {
            std::cout << "Invalid input. Please enter digits only." << std::endl;
            continue;
        }

        if (cardNumber.length() < 13 || cardNumber.length() > 19) {
            std::cout << "Invalid card number length." << std::endl;
            continue;
        }

        if (isValidCreditCard(cardNumber)) {
            std::cout << "Valid credit card number." << std::endl;
        } else {
            std::cout << "Invalid credit card number." << std::endl;
        }
    }

    std::cout << "Exiting the program." << std::endl;

    return 0;
}
