/**
 * @file oop_polymorphism.cpp
 * @brief Cyber Security Oriented C++ Journey - Phase 9: OOP & Virtual Functions
 * @details Demonstrates polymorphism and dynamic dispatch using virtual functions,
 * laying the foundation for understanding vtable mechanics in reverse engineering.
 * */

#include <iostream>
#include <memory>

 // 1. Base Class
class SecurityModule {
public: 
	// The 'virtual' keyword tells C++ to create a vtable (virtual table)
	virtual void Analyze() {
		std::cout << "[BASE] Generic security analysis executing..." << std::endl;
	}

	// Virtual destructor - Essential for preventing memory leaks
	virtual ~SecurityModule() = default;
};

// 2. SUBCLASS 1 (Derived Class - Firewall)
class FirewallModule : public SecurityModule {
public: 
	void Analyze() override {
		// We override the Analyze function in the base class.
		std::cout << "[FIREWALL] Inspecting incoming TCP/UDP traffic on port 80/443..." << std::endl;
	}
};

// 3. SUBCLASS 2 (Derived Class - Antivirus)
class AntivirusModule : public SecurityModule {
public:
	void Analyze() override {
		std::cout << "[ANTIVIRUS] Scanning process memory signatures for malware..." << std::endl;
	}
};

int main() {
	std::cout << "=== OOP POLYMORPHISM & DYNAMIC DISPATCH ===" << std::endl;

	// We are creating an array of smart pointers of the base class type.
	std::unique_ptr<SecurityModule> module1 = std::make_unique<FirewallModule>();
	std::unique_ptr<SecurityModule> module2 = std::make_unique<AntivirusModule>();

	std::cout << "\n--- Triggering Dynamic Behavior (vtable lookup) ---" << std::endl;

	// Even though both are pointers of type 'SecurityModule', 
	// thanks to the vtable in RAM, they will call their own specific 'Analyze' functions!
	module1->Analyze();
	module2->Analyze();
	
	std::cout << "\n[SUCCESS] Polymorphic function execution completed safely." << std::endl;

	return 0;
}
