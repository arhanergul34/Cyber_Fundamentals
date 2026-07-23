/**
 * @file function_pointers.cpp
 * @brief Cyber Security Oriented C++ Journey - Phase 7: Function Pointers
 * @details This project demonstrates how pointers can point to executable functions in memory
 * and how altering function pointers changes the execution flow of an application.
 * */

 /**
#include <iostream>

 // 1. Normal User Authorization Function in the System
void NormalUserAccess() {
	std::cout << "[USER] Standart user session started. Restricted access applied." << std::endl;
}

// 2. Critical Admin Authorization Function in the System
void AdminAccess() {
	std::cout << "[ALERT] Admin session started! Full system control granted." << std::endl;
}

int main() {
	std::cout << "=== DYNAMIC EXECUTION FORENICS ===" << std::endl;

	// Let's print the actual code addresses of the functions in RAM to the screen
	// By using (void*), we tell the processor: "Show the starting address of this function in RAM!"
	std::cout << "NormalUserAccess() RAM Address: " << (void*)NormalUserAccess << std::endl;
	std::cout << "AdminAccess() RAM Address:	  " << (void*)AdminAccess << std::endl;
	std::cout << "------------------------------------------------" << std::endl;

	// 3. DEFINING A FUNCTION POINTER
	// This pointer does not hold data; it points to functions that do not return data (void) and do not take parameters ().
	void (*execution_flow_ptr)();


	// 4. Redirecting the flow to the regular user
	std::cout << "[SYSTEM] Routing execution flow to Normal User..." << std::endl;
	execution_flow_ptr = NormalUserAccess;
	execution_flow_ptr(); // We trigger the function via the pointer (Call)
	std::cout << "------------------------------------------------" << std::endl;

	// 5. HIJACKING SIMULATION (Manipulating the Flow)
	// In a real cyberattack, the address of this pointer is changed via memory manipulation.
	std::cout << "[ATTACK] Manipulating function pointer target address..." << std::endl;
	execution_flow_ptr = AdminAccess;
	// The pointer now points to the RAM address of the Admin function!
	execution_flow_ptr(); // The same pointer is triggered, but this time the Admin code runs!
	std::cout << "------------------------------------------------" << std::endl;
	return 0;
}

*/


