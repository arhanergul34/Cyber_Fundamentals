/**
 * @file crypto_basics.cpp
 * @brief Cyber Security Oriented C++ Journey - Phase 4: Strings & Cryptography Basics
 * @details This project demonstrates how characters are stored as ASCII numbers in RAM
 * and implements a basic Caesar Cipher algorithm for data obfuscation.
 * */

#include <iostream>
#include <string> // We add this library to use text strings.

int main() {
	// 1. Numerical Representation of Characters in RAM (ASCII Logic)
	char secret_char = 'A'; // Box holding a single letter

	std::cout << "=== CRYPTOGRAPHY KEYBOARD ANATOMY ===" << std::endl;
	std::cout << "Charachter: " << secret_char << std::endl;
	// By writing (int), we tell the processor: "Show me the numerical equivalent of this character in RAM!"
	std::cout << "ASCII Number in RAM: " << (int)secret_char << std::endl;
	std::cout << "------------------------------------------------" << std::endl;

	// 2. CAESAR CIPHER SIMULATION (Data Obfuscation)
	std::string secret_message = "HACK"; // The secret word we want to encrypt
	int cipher_key = 3; // We will shift each letter 3 steps forward in the alphabet.

	std::cout << "Original Message: " << secret_message << std::endl;

	// We iterate through all the letters in the word one by one and shift them forward by 3.
	for (int i = 0; i < secret_message.length(); i++) {
		secret_message[i] = secret_message[i] + cipher_key;
	}

	std::cout << "Encrypted Message (Sent to Hacker Server): " << secret_message << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	// 3. DECRYPTION
	// The hacker shifts back 3 steps to decrypt this nonsensical text arriving at their server.
	for (int i = 0; i < secret_message.length(); i++) {
		secret_message[i] = secret_message[i] - cipher_key;
	}

	std::cout << "Decrypted Message (Recovered by Hacker): " << secret_message << std::endl;
	std::cout << "------------------------------------------------" << std::endl;

	return 0;

}
