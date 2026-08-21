/**
 * @file file_logger.cpp
 * @brief Cyber Security Oriented C++ Journey - Phase 13: File I/O & Logging
 * @details Demonstrates file output/input streams (ofstream, ifstream) to write
 * and audit persistent security logs on disk.
 */

#include <iostream>
#include <fstream> // File Operations Library
#include <string>

 // 1. FUNCTION THAT SAVES THE SECURITY EVENT TO DISK
void LogSecurityEvent(const std::string& filename, const std::string& logLevel, const std::string& message) {
	// std::ios::app -> "Append" mode. It appends to the end of the file; it does not delete the existing content!
	std::ofstream logFile(filename, std::ios::app);

	// Check if the file was opened successfully
	if (!logFile.is_open()) {
		std::cerr << "[CRITICAL ERROR] Could not open log file for writing!" << std::endl;
		return;
	}

	// We format the log and write it to the file.
	logFile << "[" << logLevel << "] " << message << std::endl;

	// The file is closed manually
	logFile.close();
	std::cout << "[LOGGER] Event successfully persisted to disk." << std::endl;
}

// 2. FUNCTION THAT READS THE LOG FILE FROM DISK
void ReadSecurityLogs(const std::string& filename) {
	std::ifstream logFile(filename);

	// HATA BURADAYDI: Eğer dosya AÇILAMADISA uyarı verip fonksiyondan çıkıyoruz (return)
	if (!logFile.is_open()) {
		std::cerr << "[CRITICAL ERROR] Could not open log file for reading!" << std::endl;
		return;
	}

	// Dosya BAŞARIYLA AÇILDIĞI İÇİN okuma işlemini if'in DIŞINDA yapıyoruz
	std::string line;

	// Reads all lines in the file one by one until the end
	while (std::getline(logFile, line)) {
		std::cout << "[FILE LINE] " << line << std::endl; // 'line' değişkeni eklendi
	}

	logFile.close();
}

int main() {
	std::cout << "=== FILE I/O & PERSISTENT SECURITY LOGGER ===" << std::endl;

	const std::string logFileName = "security_audit.log";

	// A) Writing Security Logs to Disk
	std::cout << "\n--- 1. Writing Security Events ---" << std::endl;
	LogSecurityEvent(logFileName, "INFO", "System security module initialized.");
	LogSecurityEvent(logFileName, "WARNING", "Failed login attempt detected from IP: 192.168.1.50");
	LogSecurityEvent(logFileName, "ALERT", "SQL Injection payload blocked in HTTP Request.");

	// B) Reading and Auditing Logs on Disk
	std::cout << "\n--- 2. Auditing Stored Logs ---" << std::endl;
	ReadSecurityLogs(logFileName);

	return 0;
}