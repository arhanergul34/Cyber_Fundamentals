/**
 * @file exception_handling.cpp
 * @brief Cyber Security Oriented C++ Journey - Phase 12: Exception Handling
 * @details Demonstrates try, catch, and custom throw mechanisms for fault-tolerant
 * security modules and unauthorized access handling.
 * */

#include <iostream>
#include <string>
#include <stdexcept> // Standard Error Library

 // Function that checks user login and authorization
void AuthenticateUser(const std::string& username, int accessLevel) {
	std::cout << "[AUTH CHECK] Validating credentials for user: " << username << std::endl;

	// 1. RULE: The username cannot be empty!
	if (username.empty()) {
		throw std::invalid_argument("ERROR: Username cannot be empty!");
	}

	// 2. RULE: The access level must be between 1 and 5!
	if (accessLevel < 1 || accessLevel > 5) {
		throw std::out_of_range("CRITICAL: Access level out of bounds! Potential privilege escalation attack!");
	}

	// 3. RULE: Level 5 is the System Administrator (Admin)
	if (accessLevel == 5) {
		std::cout << "[SUCCESS] Administrator access granted to " << username << std::endl;
	}
	else {
		std::cout << "[SUCCESS] Standard user access granted to " << username << std::endl;
	}
}

int main() {
    std::cout << "=== EXCEPTION HANDLING & SECURITY FAULT-TOLERANCE ===" << std::endl;

    // TEST 1: Invalid Access Level Attempt (Error Expected)
    std::cout << "\n--- Test 1: Simulating Privilege Escalation Attack ---" << std::endl;
    try {
        // A rule violation is occurring by granting access level 99!
        AuthenticateUser("hacker_user", 99);
    }
    catch (const std::out_of_range& e) {
        std::cout << "[SECURITY ALERT] Out of Range Exception Caught: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "[GENERAL ERROR] An unexpected error occurred: " << e.what() << std::endl;
    }

    // TEST 2: Empty Username Attempt (Error Expected)
    std::cout << "\n--- Test 2: Simulating Empty Username Injection ---" << std::endl;
    try {
        AuthenticateUser("", 2);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "[SECURITY ALERT] Invalid Argument Exception Caught: " << e.what() << std::endl;
    }

    // TEST 3: Legitimate/Successful Login Attempt
    std::cout << "\n--- Test 3: Simulating Legitimate Admin Login ---" << std::endl;
    try {
        AuthenticateUser("sys_admin", 5);
    }
    catch (const std::exception& e) {
        std::cout << "[ERROR] This line will NOT execute because no error occurred." << std::endl;
    }

    std::cout << "\n[SUCCESS] Application handled all security exceptions without crashing." << std::endl;

    return 0;
}