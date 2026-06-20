/**
 * @file array_overflow.cpp
 * @brief Cyber Security Oriented C++ Journey - Phase 2: Arrays & Buffer Overflow
 * @details This project demonstrates how C++ allows out-of-bounds array indexing,
 * leading to critical memory leaks or memory corruption (Buffer Overflow foundations).
 * */

 /**

#include <iostream>

int main() {
	// 1. Memory Layout Simulation
	// We define a hidden system password in RAM (data that a hacker should not normally see)
	int SECRET_SYSTEM_KEY = 7777;

	// The military base's 3 valid gate codes (We are renting a space consisting of only 3 rooms)
	int gate_codes[3] = { 1010, 2020, 3030 };

	std::cout << "=== MILITARY BASE FIREWALL ONLINE ===" << std::endl;
	std::cout << "Valid Array Indexes: 0, 1, 2," << std::endl;
	std::cout << "---------------------------------------" << std::endl;

	// 2. NORMAL OPERATION 
	std::cout << "[LEGAL ACCESS] Reading Gate 0: " << gate_codes[0] << std::endl;
	std::cout << "[LEGAL ACCESS] Reading Gate 2: " << gate_codes[2] << std::endl;
	std::cout << "---------------------------------------" << std::endl;


	// 3. EXPLORING THE MEMORY LEAK (Hacker Move)
	// We are attempting to read indices 3 and 4 (out-of-bounds memory), which do not exist!
	// C++ won't stop us; it will read the neighboring memory locations right next to that array in RAM.
	int target_malicious_index = 3;
	
	std::cout << "[ATTACK] Attempting to read index " << target_malicious_index << " (Out of Bounds)..." << std::endl;

	// Due to the lack of bounds checking (input validation), C++ will leak neighboring data in RAM.
	std::cout << "[EXPLOIT SUCCES] Data leaked from RAM: " << gate_codes[target_malicious_index] << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	return 0;

}

 * */
