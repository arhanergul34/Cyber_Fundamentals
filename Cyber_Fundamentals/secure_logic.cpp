/*
#include <iostream>

int main() {
	// Initial State of the Application
	int user_balance = 500;		// User's wallet
	int withdraw_amount = -200;	// HACKER'S MOVE: Negative withdrawal request!
	
	std::cout << "=== BANKING SYSTEM INITIALIZED ===" << std::endl;
	std::cout << "Initial User Balance: $" << user_balance << std::endl;
	std::cout << "Requested Withdraw Amount: $" << withdraw_amount << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	// 2. VULNERABLE LOGIC CHECK (Developer's Flawed Check)
	// The developer only checks whether the withdrawn amount exceeds the balance.
	if (withdraw_amount > user_balance) {
		std::cout << "[ERROR] Security Alert: Insufficent funds!" << std::endl;
	}
	else {
		// ERROR HERE: Mathematically, (-200) is NOT greater than 500.
		// The program enters here and attempts to deduct the money from the account.
		// Mathematical rule: 500 - (-200) = 500 + 200 = 700!
		user_balance = user_balance - withdraw_amount;

		std::cout << "[SUCCESS] Transcation approved via logic shortcut." << std::endl;
	}

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "=== AFTER EXPLOITATION ===" << std::endl;
	std::cout << "Final User Balance: $" << user_balance << std::endl;
	return 0;
}
*/