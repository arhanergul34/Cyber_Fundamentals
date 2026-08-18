/**
 * @file stl_templates.cpp
 * @brief Cyber Security Oriented C++ Journey - Phase 10: STL & Templates
 * @details Demonstrates template classes and std::vector for safe, dynamic
 * payload buffering and anomaly detection.
 * */

#include <iostream>
#include <vector>
#include <string>

 // 1. GENERIC TEMPLATE CLASS (Type-Independent Buffer)
template <typename T>
class PacketBuffer {
private:
	std::vector<T> buffer; // Dynamic STL array

public:
	// Adds new data to the buffer
	void AddPacket(const T& packet) {
		buffer.push_back(packet);
		std::cout << "[BUFFER] Element stored successfully. Current size: " << buffer.size() << std::endl;
	}


	// Displays all elements in the buffer
	void InspectBuffer() const {
		std::cout << "\n--- Inspecting Buffer Contents ---" << std::endl;
		for (const auto& item : buffer) {
			std::cout << "[DATA ITEM] " << item << std::endl;
		}
	}

	// Returns the total number of packets
	size_t GetSize() const {
		return buffer.size();
	}
};

int main() {
	std::cout << "=== STL CONTAINERS & TEMPLATE ARCHITECTURE ===" << std::endl;

	// A) Buffer for Text-based (String) Network Payloads
	std::cout << "\n--- 1. String Payload Buffer ---" << std::endl;
	PacketBuffer<std::string> stringBuffer;
	stringBuffer.AddPacket("GET /index.html HTTP/1.1");
	stringBuffer.AddPacket("POST /login.php HTTP/1.1");
	stringBuffer.AddPacket("SELECT * FROM users WHERE '1'='1'"); // SQL Injection payload simulations
	stringBuffer.InspectBuffer();

	// B) Buffer for Integer Port/Signal Data (We use the same class!)
	std::cout << "\n--- 2. Port Scan Buffer (Integer) ---" << std::endl;
	PacketBuffer<int> portBuffer;
	portBuffer.AddPacket(80);
	portBuffer.AddPacket(443);
	portBuffer.AddPacket(8080);
	portBuffer.InspectBuffer();

	std::cout << "\n[SUCCESS] Generic STL buffer executed safely without memory leaks." << std::endl;

	return 0;
}
