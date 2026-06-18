# Cyber Security Oriented C++ Journey - Phase 1: Memory & Anomalies

This repository contains the fundamental steps of my comprehensive C++ learning journey, tailored specifically for cyber security engineering, exploit development, and malware analysis concepts.

## 📌 Step 1: Memory Anatomy (`main.cpp`)
Unlike high-level languages like Python, C++ allows direct manipulation of system hardware. This initial project focuses on understanding how variables are physically structured inside the **RAM (Stack)** layout, inspecting their exact byte boundaries, and analyzing raw hexadecimal memory addresses.

## 🚨 Step 2: Integer Overflow Vulnerability (`integer_overflow.cpp`)
I have successfully simulated a critical **Integer Overflow** vulnerability on the local system memory. By assigning a `short` integer type to its absolute maximum capacity (32,767) and incrementing it by 1, the binary representation wrapped around the memory boundary due to the sign bit alteration, resulting in an unexpected negative value (-32,768). This exercise demonstrates how arithmetic anomalies can lead to severe software exploits.

## 🎯 Step 3: Pointer Anatomy & Memory Manipulation (`pointer_anatomy.cpp`)
I have successfully simulated a basic memory manipulation exploit. By creating a pointer (`int*`) that securely holds the exact hexadecimal RAM address of a target system variable, I executed a de-referencing operation (`*ptr`). This allowed me to bypass standard variable assignment and modify the application's internal data directly via its physical memory shortcut, altering the initial state from `100` to `999`.

## 🎯 Step 4: Logic Vulnerability & Input Validation (`secure_logic.cpp`)
I have simulated a critical Business Logic Flaw commonly found in poorly validated financial applications. By inputting a negative withdrawal amount (`-200`), the system's simple boundary check (`withdraw_amount > user_balance`) was bypassed. Due to signed arithmetic rules, subtracting a negative number resulted in an unintended balance addition ($500 - (-200) = 700$), successfully exploiting the application logic without triggering system crashes.

## 🎯 Step 5: Loop Structures & Local Denial of Service (DoS) Simulation (`infinite_dos.cpp`)
I have successfully simulated a code-level Denial of Service (DoS) vulnerability via resource exhaustion. By manipulating the exit criteria of a conditional loop (`while`), the counter was inverted to increment indefinitely (`counter++`). Since the loop boundary condition (`counter > 0`) mathematically remains permanently true, it forces the CPU into an infinite operational state, consuming local thread processing resources. A defensive control flow logic (`break`) was implemented as a safety circuit breaker to intercept the attack once boundaries were exceeded.

## 🎯 Step 6: Memory Boundaries & Out-of-Bounds Read Simulation (`array_overflow.cpp`)
I have simulated a foundational memory corruption vulnerability: Out-of-Bounds Read (Memory Leak). In C++, arrays do not have native bounds checking. By requesting an invalid index (`index 3`) on a 3-element array, the compiler successfully fetched data from the neighboring unallocated memory location in RAM instead of throwing an index error. This demonstrates how improper input validation at the memory layer can lead to sensitive data exposure or serve as a baseline for Buffer Overflow exploits.