/**
 * @file function_stack.cpp
 * @brief Cyber Security Oriented C++ Journey - Phase 3: Functions & Stack Architecture
 * @details This project demonstrates how functions isolate logic and how local variables
 * are allocated inside the Stack memory frame.
 * */

 /**
#include <iostream>
 // 1. AN AUTHENTICATION FUNCTION (Function Definition)
 // When this function is called, a temporary "Stack Frame" is created in RAM.
void check_access_level(int user_id) {
	// This variable exists only within this function (Local Variable)
	int internal_firewall_status = 1;

	std::cout << "--- Inside check_access_level() Funciton Stack ---" << std::endl;
	std::cout << "Processing User ID: " << user_id << std::endl;
	std::cout << "Local Firewall Status Variable Address: " << internal_firewall_status << std::endl;

	if (user_id == 999) {
		std::cout << "[ACCESS GRANTED] Welcome Admin!" << std::endl;
	}
	else {
		std::cout << "[ACCESS DENIED] Standart User Restrictions Applied." << std::endl;
	}
	// The moment the function finishes, this stack area is completely cleared from RAM (Pop)!
}

int main() {
	std::cout << "=== CORE SECURITY SYSTEM INITIALIZED ===" << std::endl;
	std::cout << "Main Funciton Address Space: " << &main << std::endl;
	std::cout << "------------------------------------------------" << std::endl;

	// 2. FUNCTION CALLS
	// With each call, the processor pauses the main() function, jumps up to execute the task, and returns once finished.
	std::cout << "[CALL 1] Requesting standart access..." << std::endl;
	check_access_level(101);
	std::cout << "------------------------------------------------" << std::endl;

	std::cout << "=== SYSTEM TERMINATED CLEANLY ===" << std::endl;
	return 0;
}
 * */
