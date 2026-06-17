/**
 * @file pointer_anatomy.cpp
 * @brief Cyber Security Oriented C++ Journey - Phase 1: Pointer Anatomy
 * @details This project demonstrates how pointer variables store memory addresses
 * and how to manipulate data directly via physical RAM shortcuts.
 */

#include <iostream>

int main() {
	// 1. Target variable: A secure system code inside the RAM
	int system_code = 100;

	// 2. Pointer creation: Storing the memory address of system_code
	int* ptr_security = &system_code;

	std::cout << "=== BEFORE MEMORY MANIPULATION ===" << std::endl;
	std::cout << "Original Value of system_code :" << system_code << std::endl;
	std::cout << "Target Room Address (&system_code): " << &system_code << std::endl;
	std::cout << "Address Stored Inside Pointer (ptr_security): " << ptr_security << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	*ptr_security = 999;

	std::cout << "=== AFTER MEMORY MANIPULATION (BACKDOOR) ===" << std::endl;
	std::cout << "New Value of system_code : " << system_code << std::endl;


return 0;
}