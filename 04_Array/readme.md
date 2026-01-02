# 📚 Arrays: C++ vs Kotlin Guide

A quick reference guide for declaring, initializing, and manipulating arrays in **C++** (Legacy & Modern) and **Kotlin**.

## 📖 Table of Contents
- [C++ Arrays](#-c-arrays)
  - [C-Style (Raw)](#1-c-style-raw-arrays-legacy)
  - [std::vector (Dynamic)](#2-stdvector-dynamic--recommended)
  - [std::array (Fixed)](#3-stdarray-fixed--modern)
- [Kotlin Arrays](#-kotlin-arrays)
  - [Standard Arrays (Boxed)](#1-standard-arrays-boxed)
  - [Primitive Arrays (Optimized)](#2-primitive-arrays-optimized)
  - [Lists (Dynamic)](#3-lists-dynamic-resizable)
- [Cheat Sheet Comparison](#-cheat-sheet)

---

## 📘 C++ Arrays

In C++, you have three main options depending on whether you need a fixed size or a dynamic size.

### 1. C-Style Raw Arrays (Legacy)
*Fixed size, fast, but unsafe (no bounds checking).*

```cpp
// Declaration (Garbage values inside)
int numbers[5]; 

// Declaration with Initialization
int primes[] = {2, 3, 5, 7, 11}; 

// Partial Initialization (Remaining become 0)
int scores[10] = {100, 90, 80};
