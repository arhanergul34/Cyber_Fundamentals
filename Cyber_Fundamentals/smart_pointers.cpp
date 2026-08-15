/**
 * @file smart_pointers.cpp
 * @brief Cyber Security Oriented C++ Journey - Phase 8: Secure Memory Management
 * @details This project demonstrates modern C++ memory safety using std::unique_ptr
 * to eliminate Use-After-Free vulnerabilities and memory leaks automatically (RAII).
 * */

 /**
#include <iostream>
#include <memory> // It is mandatory for smart pointers (std::unique_ptr).

 // A safe memory object simulation
class SecureSession {
public:
	SecureSession() {
		std::cout << "[RESOURCE ALLOCATED] Encrypted Session buffer opened in Heap RAM." << std::endl;
	}

	void ExecuteSecureOperation() {
		std::cout << "[OPERATION] Running authenticated cryptographic check..." << std::endl;
	}

	~SecureSession() {
		// Destructor: Runs automatically the moment this object is deleted from memory.
		std::cout << "[RESOURCE FREED] Destructor invoked automatically! Memory safely wiped." << std::endl;
	}
};

int main() {
	std::cout << "=== MODERN SECURE C++ MEMORY MANAGEMENT ===" << std::endl;

	{// 1. LOCAL SCOPE (Block Start)}
		std::cout << "\n--- Entering Local Scope ---" << std::endl;

		// We create a safe, smart pointer using std::make_unique.
		// We do NOT need to write 'delete'!
		std::unique_ptr<SecureSession> session_ptr = std::make_unique<SecureSession>();

		// Smart pointers are used with the '->' operator, just like regular pointers.
		session_ptr->ExecuteSecureOperation();

		std::cout << "--- Exiting Local Scope ---" << std::endl;
	} // 2. End of block (session_ptr is automatically destroyed the moment the curly brace closes!)

	std::cout << "\n[SUCCESS] Porgram safely reached end of main without manuel 'delete'!" << std::endl;

	return 0;
}

*/

