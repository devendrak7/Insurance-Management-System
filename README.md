# 🛡️ Insurance Management System

A console-based Insurance Management System built using C++. This project demonstrates Object-Oriented Programming (OOP), file handling, modular programming, and STL to manage customers, insurance policies, payments, and menu navigation.

## ✨ Key Features

### 👥 1. Customer Management
- **Add Customer:** Register customers with automatically generated IDs.
- **Update Customer:** Modify existing customer details.
- **Delete Customer:** Remove customer records.
- **Search Customer:** Find customers using their IDs.
- **View Customers:** Display registered customer records.

### 📜 2. Policy Management
- **Multiple Insurance Types:** Supports Life, Health, Vehicle, and Property insurance.
- **Premium Calculation:** Calculates premiums based on insurance type, coverage or asset value, and policy duration.
- **Policy Registration:** Register policies for existing customers.
- **Update Policy:** Modify policy details and dates.
- **Cancel Policy:** Cancel active policies.
- **Policy Tracking:** View policy details and active policies.

### 💳 3. Payment Management
- **Make Payment:** Record full or partial payments against active policies.
- **Payment Status:** Track Pending, Partial, and Paid statuses.
- **Payment History:** View previous payment transactions.
- **Outstanding Balance:** Track the remaining premium amount.

### 🔙 4. Smart Back Navigation
- **Stack-Based Navigation:** Uses `std::stack` to manage menu and form navigation history.
- **Back Navigation:** Return to the previous menu or form step seamlessly.
- **Main Menu Navigation:** Return directly to the main menu.

### 🗄️ 5. File-Based Data Storage
- **Permanent Storage:** Stores customer, policy, and payment records in text files.
- **Indexing System:** Uses index files to locate customer and policy records.
- **File Operations:** Uses C++ file handling (`fstream`) to read, write, update, search, and delete records.

## 🛠️ Tech Stack
- **Language:** C++
- **Programming Concepts:** Object-Oriented Programming (OOP)
- **Standard Library:** STL (`std::stack`, `std::string`)
- **File Handling:** `fstream`, `ifstream`, and `ofstream`
- **Data Storage:** Text files (`.txt`)
- **Compiler:** GCC / MinGW

## 📂 Project Structure
```text
InsuranceManagementSystem/
├── data/
│   ├── customers/
│   ├── payments/
│   └── policies/
├── include/
│   ├── Customer.h
│   ├── FileManager.h
│   ├── Policy.h
│   └── UI.h
├── src/
│   ├── main.cpp
│   ├── Customer.cpp
│   ├── FileManager.cpp
│   ├── Policy.cpp
│   └── UI.cpp
├── README.md
└── app.exe
```

## 🚀 How to Run the Project

**Prerequisites:**
- GCC / MinGW C++ compiler
- Terminal or VS Code

**1. Clone the Repository**
```bash
git clone https://github.com/devendrak7/Insurance-Management-System.git
cd InsuranceManagementSystem
```

**2. Compile the Project**
Run this command from the project root directory:
```bash
g++ src/*.cpp -o app.exe
```

**3. Run the Application**
```bash
.\app.exe
```
> **Note:** Ensure the required `data/customers/`, `data/policies/`, and `data/payments/` empty directories exist in the root folder before running the application.

## 🎓 Academic Learning Outcomes
- Understanding Object-Oriented Programming in C++.
- Organizing code using modular approach (header and source files).
- Performing CRUD operations.
- Managing persistent data using C++ file handling.
- Using STL containers such as `std::stack` for real-world logic.
- Implementing modular programming and step-by-step navigation.

---

