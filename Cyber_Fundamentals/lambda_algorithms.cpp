/**
 * @file lambda_algorithms.cpp
 * @brief Cyber Security Oriented C++ Journey - Phase 11: Lambdas & STL Algorithms
 * @details Real-time network packet inspection and malicious signature filtering
 * using C++ inline lambda expressions and std::remove_if algorithms.
 * */

 /**
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  //C++ Standard Algorithm Library

 // Simple structure representing a network packet
struct NetworkPacket {
	int packetId;
	std::string payload;
	bool isMalicious;
};

int main() {
	std::cout << "=== NETWORK TRAFFIC INSPECTION & LAMBDA FILTERS ===" << std::endl;

	// 1. Simulated Network Traffic (Packet List)
	std::vector<NetworkPacket> traffic = {
		{101, "GET /index.html HTTP/1.1", false},
		{102, "SELECT * FROM users WHERE '1'='1'", true},  // SQL Injection (Malicious)
		{103, "POST /contact.php HTTP/1.1", false},
		{104, "<script>alert('XSS')</script>", true},		// Cross-Site Scripting (Malicious)
		{105, "GET /favicon.ico HTTP/1.1", false}
	};

	std::cout << "\n[INFO] Total incoming packets in stream: " << traffic.size() << std::endl;

	// 2. DELETING/FILTERING MALICIOUS PACKETS USING A LAMBDA EXPRESSION
	// std::remove_if moves packets that meet the condition (isMalicious == true) to the end of the range.
	auto maliciousBoundary = std::remove_if(traffic.begin(), traffic.end(), [](const NetworkPacket& pkt) {
		// Here is our Lambda function!
		// If the packet is malicious, it returns 'true', and the algorithm flags the packet.
		return pkt.isMalicious;
	});

	// Update the size of the filtered (cleaned) data
	traffic.erase(maliciousBoundary, traffic.end());

	// 3. PRINTING THE CLEANED TRAFFIC TO THE SCREEN (Using another Lambda)
	std::cout << "\n--- Clenaed Traffic Stream (Malicious Packets Dropped) ---" << std::endl;
	std::for_each(traffic.begin(), traffic.end(), [](const NetworkPacket& pkt) {
		std::cout << "[CLEAN PACKET ID: " << pkt.packetId << "] Payload: " << pkt.payload << std::endl;
		});

	std::cout << "\n[SUCCESS] Remaining clean packets count: " << traffic.size() << std::endl;

	return 0;


}

*/