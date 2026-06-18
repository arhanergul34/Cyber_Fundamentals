/**
 * @file infinite_dos.cpp
 * @brief Cyber Security Oriented C++ Journey - Phase 2: Loop Structures & DoS
 * @details This project demonstrates how an unvalidated loop condition can lead
 * to an infinite loop, causing a local Denial of Service (DoS) by exhausting CPU resources.
 * */

 /** #include <iostream>

int main() {
	// 1. Simulation of a network packet counter or a login attempt rate limiter
	int system_reboot_counter = 10;
	int trigger_hack = 1; // 1 means activate the simulation, 0 means normal operation

	std::cout << "=== CRITICAL INFRASTRUCTURE ONLINE ===" << std::endl;
	std::cout << "Initial System Reboot Counter: " << system_reboot_counter << std::endl;
	std::cout << "---------------------------------------" << std::endl;

	// 2. THE INFECTED LOOP (Vulnerable Implementation)
	// Normally, this loop should count down and stop when it reaches 0.
	// However, cyber manipulation or a logic error is locking the loop.
	while (system_reboot_counter > 0) {

		std::cout << "[PROCESSING] Counter State: " << system_reboot_counter << std::endl;

		if (trigger_hack == 1) {
		// HACKER MOVE: Instead of decrementing the counter, we keep increasing it or keep it constant!
		// Since the number can mathematically never drop to 0 or below, the loop will run forever.
			system_reboot_counter++;
		} else {
			// Normal, safe flow:
			system_reboot_counter--;
		}

		// A small safety brake to prevent the simulation from completely locking up the computer:
		if (system_reboot_counter > 100) {
			std::cout << "---------------------------------------" << std::endl;
			std::cout << "[SECURITY ALERT] Local DoS Detected! CPU Exhaustion Prevented via Safety Brake." << std::endl;
			break; // We break the infinite loop using the safety brake we implemented.
		}
	}
			
}
*/