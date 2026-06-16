# Cyber Security Oriented C++ Journey - Phase 1: Memory Anatomy

This repository contains the first fundamental step of my comprehensive C++ learning journey, tailored specifically for cyber security engineering, exploit development, and malware analysis concepts.

## 📌 Project Overview
Unlike high-level languages like Python, C++ allows direct manipulation of system hardware. This initial project focuses on understanding how variables are physically structured inside the **RAM (Stack)** layout, inspecting their exact byte boundaries, and analyzing raw hexadecimal memory addresses.

## 🧠 Core Concepts Learned
- **Bit & Byte Architecture:** Deep dive into data sizes (1 Byte = 8 Bits).
- **The Stack Layout:** Understanding how local variables occupy static memory spaces.
- **Memory Addresses:** Fetching physical hardware addresses using the address-of (`&`) operator.
- **ASCII Representation:** Understanding how characters are stored as underlying integers.

## 💻 Code Structure
The implementation performs the following core operations:
1. Allocates a 4-Byte integer (`int`) on the Stack.
2. Allocates a 1-Byte character (`char`) on the Stack.
3. Inspects memory footprints using the compile-time `sizeof()` operator.
4. Outputs raw pointers (Hexadecimal addresses) directly from physical RAM.
