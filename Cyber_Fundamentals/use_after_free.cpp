/**
 * @file use_after_free.cpp
 * @brief Cyber Security Oriented C++ Journey - Phase 5: Dynamic Memory & Use-After-Free
 * @details This project demonstrates how deleting dynamic memory without resetting the pointer
 * creates a Dangling Pointer, leading to Use-After-Free (UAF) vulnerabilities.
 * */

 /**
#include <iostream>

int main() {
    // 1. DYNAMIC MEMORY ALLOCATION (Allocating Space in the Heap)
    // In C++, the 'new' keyword dynamically allocates space from the persistent region of RAM known as the Heap.
    // Here, we place a variable that simulates the system's admin privilege (1 = Admin, 0 = User).
    int* admin_privilege = new int(1);

    std::cout << "=== CRITICAL PRIVILEGE CONTROL INITIALIZED ===" << std::endl;
    std::cout << "[INFO] Admin Privilege Pointer Address: " << admin_privilege << std::endl;
    std::cout << "[INFO] Admin Privilege Value: " << *admin_privilege << " (Access Granted)" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    // 2. DEALLOCATION (Freeing / Returning Memory)
    // When we are finished, we return this space in RAM to the operating system using 'delete'.
    delete admin_privilege;
    std::cout << "[SYSTEM] Memory freed via delete command." << std::endl;

    // This is a dangerous situation: The memory has been deallocated, but the pointer named 'admin_privilege' still points to that address!
    // In cybersecurity, this is known as a "Dangling Pointer."
    std::cout << "[WARNING] Pointer still points to the same address: " << admin_privilege << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    // 3. USE-AFTER-FREE ATTACK
    // That room no longer belongs to us; it belongs to the operating system. 
    // But since we still hold the pointer, we can attempt to read from or modify it!
    std::cout << "[ATTACK] Attempting to read/write freed memory space (Use-After-Free)..." << std::endl;

    // C++ won't stop us; it will let us leak or modify data from a deleted room.
    std::cout << "[EXPLOITT] Data read from freed memory: " << *admin_privilege << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    return 0;
}

*/