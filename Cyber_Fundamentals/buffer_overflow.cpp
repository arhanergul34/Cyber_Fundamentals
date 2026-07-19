/**
 * @file buffer_overflow.cpp
 * @brief Cyber Security Oriented C++ Journey - Phase 6: Buffer Overflow
 * @details This project demonstrates a stack-based buffer overflow vulnerability.
 * By writing more data than the buffer can hold, we overwrite adjacent memory locations.
 * */

 /*
#include <iostream>
#include <cstring> // Required for using strcpy

int main() {
	// 1. Target Variable (System's "Access Permission" – Initially 0, i.e., Closed)
	int isAuthenticated = 0;

	// 2. Buffer (Can hold only 8 characters)
	char buffer[8];

	std::cout << "=== SECURE LOGIN SYSTEM INITIALIZED ===" << std::endl;
	std::cout << "Enter your username (Max 7 chars): ";

	// DANGER: Functions like 'std::cin' or 'strcpy' write to the buffer without checking, 
	// even if the input is longer than 8 characters.
	std::cin >> buffer;

	// 3. Control Mechanism
	if (isAuthenticated != 0) {
		std::cout << "\n[!] VULNERABILITY EXPLOITED!" << std::endl;
		std::cout << "[+] ACCESS GRANTED! Welcome to the system." << std::endl;
	}
	else {
		std::cout << "\n[-] Access Denied." << std::endl;
	}

	std::cout << "Debug Info - isAuthenticated value: " << isAuthenticated << std::endl;
	return 0;
}
*/