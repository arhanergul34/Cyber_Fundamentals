/**
 * @file param_manipulation.cpp
 * @brief Cyber Security Oriented C++ Journey - Phase 3: Function Parameters
 * @details This project demonstrates the architectural difference between Pass-by-Value
 * and Pass-by-Reference, and how reference parameters can lead to unintended memory manipulation.
 * */

 /**
#include <iostream>

 // 1. PASS BY VALUE (Passing by Copying – Safe Quarantine)
 // This function cannot modify the original data because it creates a new copy in RAM.
void attempt_isolated_bypass(int security_level) {
	security_level = 0; // Sets only its own internal temporary copy to 0.
	std::cout << "[INFO] Inside isolated funciton, copy modified to: " << security_level << std::endl;
}

// 2. PASS BY REFERENCE (Passing by Address - Direct Memory Access)
// Because we place an '&' before it, this function directly accesses the RAM address of the original data!
void attempt_reference_exploit(int &security_level_ref) {
	security_level_ref = 0;
	std::cout << "{ATTACK] Inside reference function, direct memory overwritten to: " << security_level_ref << std::endl;
}

int main() {
	int SYSTEM_SECURITY_LEVEL = 5; // Our original protection level

	std::cout << "=== FIRMWARE SECURITY BLOCK INITIALIZED ===" << std::endl;
	std::cout << "Initial System Security Level: " << SYSTEM_SECURITY_LEVEL << std::endl;
	std::cout << "------------------------------------------------" << std::endl;

	// Scenario A: Copying Method Triggered
	std::cout << "[TEST 1] Triggering Isolated Bypass (Pass by Value)..." << std::endl;
	attempt_isolated_bypass(SYSTEM_SECURITY_LEVEL);
	std::cout << "[RESULT] Main Memory state after Test 1: " << SYSTEM_SECURITY_LEVEL << " (Secure - Unchanged)" << std::endl;
	std::cout << "------------------------------------------------" << std::endl;

	// Scenario B : Address / Reference Method Triggered
	std::cout << "[TEST 2] Triggering Reference Exploit (Pass by reference)..." << std::endl;
	attempt_reference_exploit(SYSTEM_SECURITY_LEVEL);
	std::cout << "[RESULT] Main memory state after Test 2: " << SYSTEM_SECURITY_LEVEL << " (COMPROMISED - Overwritten!)" << std::endl;
	std::cout << "------------------------------------------------" << std::endl;

	return 0;
}
* */