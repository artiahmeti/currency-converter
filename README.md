# C++ Currency Converter

A simple, lightweight command-line currency converter written in C++. It allows users to convert amounts between several major global currencies using predefined exchange rates relative to the US Dollar (USD).

---

## Features

* **Multiple Currencies Supported**: Includes USD, EUR, GBP, JPY, CHF, CAD, AUD, and CNY.
* **Input Validation**: Robust error handling to ensure users enter valid positive amounts and recognized currency codes.
* **Formatted Output**: Automatically normalizes currency codes (handling capitalization and spaces) and displays converted rates cleanly with fixed-point precision.

---

## Supported Exchange Rates (Per USD)

| Currency Code | Illustrative Rate |
| :--- | :--- |
| **USD** | 1.0000 |
| **EUR** | 0.9200 |
| **GBP** | 0.7900 |
| **JPY** | 150.2500 |
| **CHF** | 0.8800 |
| **CAD** | 1.3600 |
| **AUD** | 1.5200 |
| **CNY** | 7.1800 |

---

## Getting Started

### Prerequisites
* A C++ compiler supporting C++11 or later (e.g., `g++`, `clang++`, or MSVC).

### Compilation and Running
1. Clone the repository or download `CurrencyConverter.cpp`.
2. Open your terminal and compile the program:
   ```bash
   g++ -std=c++11 CurrencyConverter.cpp -o CurrencyConverter
