/**
 * @file integer_overflow.cpp
 * @brief Cyber Security Oriented C++ Journey - Phase 1: Integer Overflow
 * @details This project demonstrates how memory boundaries react when an integer
 * exceeds its maximum allocated limit, causing a critical security vulnerability.
 */

#include <iostream>

int main() {
	// We are renting a small 2-byte (16-bit) storage room. Its maximum capacity is 32,767.
	short wallet_balance = 32767;

	std::cout << "=== BEFORE OVERFLOW ===" << std::endl;
	std::cout << "Current Wallet Balance: " << wallet_balance << std::endl;
	std::cout << "Memory Size of short: " << sizeof(wallet_balance) << " bytes." << std::endl;

	std::cout << "----------------------------------------" << std::endl;

	// We are triggering the cyber-overflow moment!
	// We add 1 more gold to the money at the limit (quota).
	wallet_balance = wallet_balance + 1;

	std::cout << "=== AFTER OVERFLOW (CYBER ANOMALY) ===" << std::endl;
	std::cout << "Wallet Balance after adding 1: " << wallet_balance << std::endl;

	return 0;
}