## Arbitrary Precision Calculator (APC)

The **Arbitrary Precision Calculator (APC)** is a command-line calculator implemented in **C** that supports arithmetic operations on numbers with an **arbitrary number of digits**, far beyond the limitations of standard data types like `int` or `long`.

This project demonstrates how to implement **high-precision arithmetic** — including **addition**, **subtraction**, **multiplication**, and **division** — using **big-number (multiple-precision) arithmetic** techniques. To support arbitrarily large values, APC stores numbers in a **custom data structure**: a **linked list Abstract Data Type (ADT)**, allowing precise operations on numbers of virtually any size, limited only by available system memory.

### Use Cases
The calculator is ideal for applications where **mathematical precision** is critical, such as:

- **Scientific computing**
- **Cryptography**
- **Financial and banking systems**
