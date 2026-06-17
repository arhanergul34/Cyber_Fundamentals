# Cyber Security Oriented C++ Journey - Phase 1: Memory & Anomalies

This repository contains the fundamental steps of my comprehensive C++ learning journey, tailored specifically for cyber security engineering, exploit development, and malware analysis concepts.

## 📌 Step 1: Memory Anatomy (`main.cpp`)
Unlike high-level languages like Python, C++ allows direct manipulation of system hardware. This initial project focuses on understanding how variables are physically structured inside the **RAM (Stack)** layout, inspecting their exact byte boundaries, and analyzing raw hexadecimal memory addresses.

## 🚨 Step 2: Integer Overflow Vulnerability (`integer_overflow.cpp`)
I have successfully simulated a critical **Integer Overflow** vulnerability on the local system memory. By assigning a `short` integer type to its absolute maximum capacity (32,767) and incrementing it by 1, the binary representation wrapped around the memory boundary due to the sign bit alteration, resulting in an unexpected negative value (-32,768). This exercise demonstrates how arithmetic anomalies can lead to severe software exploits.

## 🎯 Step 3: Pointer Anatomy & Memory Manipulation (`pointer_anatomy.cpp`)
I have successfully simulated a basic memory manipulation exploit. By creating a pointer (`int*`) that securely holds the exact hexadecimal RAM address of a target system variable, I executed a de-referencing operation (`*ptr`). This allowed me to bypass standard variable assignment and modify the application's internal data directly via its physical memory shortcut, altering the initial state from `100` to `999`.