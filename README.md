# University Management System (Backend)

A high-performance C++ backend system for managing student records, course prerequisites, and fast data retrieval. This project implements core Data Structures **from scratch** without relying on STL containers for the primary logic.

##  Features & Data Structures:

This system is built upon three custom-implemented data structures:

### 1. Student Records (Singly Linked List [SLL])
* **Dynamic Storage:** Manages an unlimited number of student records.
* **Optimization:** Includes a `tail` pointer for **$O(1)$** insertion time (vs standard O(n)).
* **Sorting:** Implements **Merge Sort** (O(n log n)) for efficient data organization.
* **Search:** Includes both **Linear Search** and **Binary Search** for optimized retrieval.

### 2. Fast Access Table (Hash Table **with Chaining**)
* **Architecture:** Uses an array of Linked Lists (Buckets) to manage collisions.
* **Efficiency:** Provides near-instant **$O(1)$** average time complexity for student lookups.
* **Collision Handling:** Chaining strategy implemented using the `SRecords` (Student Records) class.

### 3. Prerequisite Manager (Stack)
* **Logic:** LIFO (Last In, First Out) structure to validate course dependency chains.
* **Safety:** Memory-safe implementation with error handling for empty states.

---

##  Algorithms & Complexity:

In case you're looking for the time complexities of the programs here's a table specified for calculating the **time complexity** of the methods used in this project:
| Operation | Algorithm | Time Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Sort** | Merge Sort (Recursive) | $O(n \log n)$ | _ |
| **Search** | Binary Search | $O(n)$ | $O(\log n)$ comparisons, but linear traversal. |
| **Search** | Linear Search | $O(n)$ | _ |
| **Insert** | Tail-Optimized Append | $O(1)$ | _ |
| **Access** | Hash Table Lookup | $O(1)$ (Avg) | _ |

---

##  How to Run:

This project relies on `g++`. No external libraries are required.

1. **Compile the project:**
   ```bash
   g++ main.cpp -o app

---

##  Made by:

| Name | ID | Assigned Tasks |
| :--- | :--- | :--- |
| **SEIF ALLAH HAYTHAM** | 241001283 | Student Records, Sorting & Searching Algorithms, Fast-access Hash Table, Prerequisite Stack |
| **AHMED MOHABA** | 241... | *[Awaiting to be edited]* |

<br>

### Personal Reminder:
This is the first serious project I made as a Sophomore implementing custom data structures without relying on existing STL libraries, and using git/github for version controlling.
