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

## 🎯 Step 7: Functions & Stack Memory Architecture (`function_stack.cpp`)
I have implemented structural code modularity using functions and analyzed the mechanics of Stack Memory frames. In C++, when a function is invoked, a temporary Stack Frame is allocated in memory to manage local parameters and variables. Upon function termination, this frame is implicitly popped (deallocated) from the RAM stack, returning execution flow to the main thread via the stored return address. Understanding this layout serves as the absolute baseline for studying Stack Smashing vulnerabilities and control-flow hijack attacks.

## 🎯 Step 8: Function Parameters & Memory Manipulation (`param_manipulation.cpp`)
I have analyzed the security and architectural differences between Pass-by-Value and Pass-by-Reference in C++. Pass-by-Value creates an isolated copy of the data in memory, preventing the function from modifying the original state. Conversely, Pass-by-Reference (`&`) exposes the exact memory address of the variable to the function. This project simulates a parameter manipulation attack scenario, showing how unsafe reference mapping can allow functions to directly overwrite core system registers (`SYSTEM_SECURITY_LEVEL` compromised from 5 to 0).

## 🎯 Step 9: Cryptography Foundations & Data Obfuscation (`crypto_basics.cpp`)
I have implemented a baseline cryptographic simulation using the Caesar Cipher algorithm to demonstrate data obfuscation. In C++, characters (`char`) are fundamentally mapped to numerical values in RAM via the ASCII encoding standard. By utilizing a type-casting directive `(int)`, I extracted the raw memory representation of characters. Through a bounded conditional loop (`for`), the application programmatically manipulates memory by adding a shift-key to text indices, effectively masking sensitive data payloads before simulation of external transmission.

## 🎯 Step 10: Dynamic Memory & Use-After-Free (UAF) Simulation (`use_after_free.cpp`)
I have simulated a critical memory corruption vulnerability known as Use-After-Free (UAF). In C++, deallocating memory via `delete` frees the resource but leaves the pointer holding the historical RAM address, creating a "Dangling Pointer". By attempting to access this deallocated memory boundary, the simulation successfully triggered a hardware-level `0xc0000005 (Access Violation)` exception enforced by the Windows operating system memory protection layer. This laboratory workflow validates the absolute necessity of pointer nullification (`nullptr`) in defensive secure coding.

## 🎯 Step 11: Stack-Based Buffer Overflow & Compiler Defenses (`buffer_overflow.cpp`)
I have investigated the behavioral mechanics of a stack-based buffer overflow vulnerability and modern compiler mitigation strategies through a two-phase hands-on laboratory simulation:

### 🧪 Experimental Workflow & Results:
1. **Normal Input Test (`arhan`):** Entered a standard 5-character string. The static bounded buffer (`char[8]`) safely held the data, and the adjacent status register (`isAuthenticated`) remained undisturbed at `0`, resulting in a legitimate `Access Denied`.
2. **Boundary Test (`aaaaaaaa`):** Entered exactly 8 characters to fill the allocation limit. Due to structural memory alignment (padding) applied by the CPU/compiler, the boundary was not breached, and `isAuthenticated` remained `0`.
3. **Massive Payload Injection Test (`a...a`):** Injected a massive sequential stream of characters (over 100+ bytes) directly into the console to forcefully overflow the buffer and overwrite adjacent memory components. 

### 🛡️ Analytical Conclusion:
Despite the severe payload size, the application successfully isolated the critical conditional primitive (`isAuthenticated = 0`), and the system did not crash. This operational outcome directly proves the execution of modern compiler defenses—specifically MSVC's **Automatic Stack Reordering** and **Buffer Security Check (`/GS`)**. The compiler programmatically restructured the memory map by pushing critical primitives out of the payload trajectory, showcasing how modern development environments neutralize legacy memory exploitation vectors at runtime.

## 🎯 Step 12: Function Pointers & Instruction Pointer Hijacking (`function_pointers.cpp`)
I have analyzed dynamic execution flows and runtime control flow hijacking using Function Pointers in C++. By isolating the raw executable boundaries of `NormalUserAccess()` and `AdminAccess()` in the `.text` segment of RAM, I observed their distinct hexadecimal base addresses at runtime. Using a specialized function pointer prototype `void (*execution_flow_ptr)()`, I simulated how application routing behaves. Overwriting this pointer's target address successfully redirected the execution flow into an unprivileged block without modifying the core logic, demonstrating the foundational mechanics behind dynamic function dispatch vulnerabilities and Return-Oriented Programming (ROP) concepts.

## 🎯 Step 13: Modern Secure C++ & RAII Mechanics (`smart_pointers.cpp`)
I have implemented modern memory safety primitives utilizing `std::unique_ptr` and the RAII (Resource Acquisition Is Initialization) pattern to prevent memory leaks and Use-After-Free (UAF) vulnerabilities. By scoping the object inside a deterministic local block (`{}`), I demonstrated how C++ automatically invokes the destructor (`~SecureSession`) and frees heap memory upon scope exit. This approach completely eliminates manual memory management pitfalls (`new`/`delete`) and ensures exception-safe resource lifecycle handling.

## 🎯 Step 14: OOP, Polymorphism & Virtual Method Tables (`oop_polymorphism.cpp`)
I have implemented a modular, object-oriented security framework to analyze dynamic method dispatch and runtime polymorphism in C++. Using a base class `SecurityModule` with `virtual` functions and derived subclasses (`FirewallModule`, `AntivirusModule`), I demonstrated how the compiler handles dynamic behaviors at runtime via `std::unique_ptr` and scope-bound RAII.

### 🔑 Key Concepts Covered:
* **Polymorphism & Dynamic Dispatch:** Enforced dynamic function binding at runtime using the `virtual` keyword and class inheritance (`public SecurityModule`).
* **Virtual Method Table (`vtable`) Mechanics:** Analyzed how C++ manages memory address pointers (`vptr`) internally to resolve method addresses dynamically.
* **Reversing & Exploitation Context:** Established foundational concepts for understanding `vtable` hijacking vulnerabilities, memory alignment, and reverse engineering binary call structures in disassemblers.
* **Safe Resource Management:** Leveraged `std::unique_ptr` to ensure exception-safe heap memory allocation and automatic cleanup without explicit `delete` statements.

## 🎯 Step 15: Standard Template Library (STL) & Generic Programming (`stl_templates.cpp`)
I implemented a dynamic, generic packet buffering mechanism to analyze memory-safe data structures and template metaprogramming concepts in Modern C++. Using `std::vector` and C++ templates (`template <typename T>`), I built a type-agnostic container capable of storing diverse payload types (such as network strings or port scan integers) without code duplication or manual memory management risks.

### 🔑 Key Concepts Covered:
* **Generic Programming (`template <typename T>`):** Designed type-independent container architectures to achieve zero code repetition and maximum code reusability.
* **Dynamic STL Containers (`std::vector`):** Utilized heap-allocated, self-resizing contiguous arrays to completely eliminate static buffer boundary limitations and Buffer Overflow zafiyet risks.
* **Const Correctness & Pass-by-Reference:** Applied `const T&` parameter passing to prevent unnecessary memory copy operations and ensure read-only safety during container inspections.
* **Memory Safety & RAII:** Leveraged STL container lifetime mechanics for safe, automatic scope-based memory allocation and deallocation without explicitly using `malloc`/`free` or `new`/`delete`.


## 🎯 Step 16: Lambdas, STL Algorithms & Traffic Inspection (`lambda_algorithms.cpp`)
I implemented a real-time network packet inspection and filtering engine leveraging C++ Lambda expressions (`[]`) and modern STL algorithms (`<algorithm>`). By utilizing inline predicates with `std::remove_if` and `std::for_each`, I demonstrated high-performance memory-safe packet filtering to instantly drop malicious signatures (such as SQL Injection and XSS payloads) from dynamic traffic streams.

### 🔑 Key Concepts Covered:
* **Modern C++ Lambdas (`[]`):** Constructed inline, anonymous function objects to execute localized filtering logic directly within algorithm scopes.
* **STL Predicate Algorithms (`std::remove_if`):** Processed contiguous memory blocks to partition and isolate unwanted data structures based on custom logical criteria.
* **Two-Step Erasure Idiom (`erase-remove`):** Combined logical partitioning with physical memory cleanup via `vector::erase` to prevent memory leaks and dangling elements.
* **Functional Data Processing:** Replaced legacy manual `for` loops with type-safe, optimized `<algorithm>` constructs (`std::for_each`) to maximize code readability and performance.

## 🎯 Step 17: Security Exception Handling & Fault Tolerance (`exception_handling.cpp`)
I implemented a robust error-handling mechanism using C++ exception handling structures (`try`, `catch`, `throw`) to design crash-resilient security software. By modeling privilege escalation attempts and unauthorized access controls via `<stdexcept>`, I demonstrated how security tools maintain operational continuity and prevent application termination during runtime anomalies.

### 🔑 Key Concepts Covered:
* **Fault-Tolerant Execution (`try`-`catch`):** Isolated high-risk security operations inside protective execution blocks to safely handle unexpected runtime failures without crashing the application process.
* **Explicit Exception Throwing (`throw`):** Enforced authorization boundary checks and security constraints by explicitly throwing standard exceptions like `std::out_of_range` and `std::invalid_argument`.
* **Standard Exception Library (`<stdexcept>`):** Utilized built-in C++ exception types and extracted descriptive diagnostic messages using the `e.what()` interface.
* **Security Resilience:** Prevented application manipulation and privilege escalation risks by redirecting unauthorized calls into dedicated security alert logger blocks.