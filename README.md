# Online Banking System (C)

A console-based online banking application written in C that simulates core banking operations including account creation, deposits, withdrawals, fund transfers, and password management.

---

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Compilation](#compilation)
  - [Running the Program](#running-the-program)
- [Usage](#usage)
  - [Creating an Account](#creating-an-account)
  - [Logging In](#logging-in)
  - [Banking Operations](#banking-operations)
- [Project Structure](#project-structure)
- [Known Limitations & Bugs](#known-limitations--bugs)
- [Potential Improvements](#potential-improvements)
- [Contributing](#contributing)
- [License](#license)

---

## Features

- **Account Creation** — Register a new user with name, password, email, and phone number.
- **Secure Login** — Authenticate with username and password before accessing banking features.
- **Deposit Funds** — Add money to your account balance.
- **Withdraw Funds** — Withdraw money with an insufficient-balance check.
- **Transfer Funds** — Send money to another user by name with a balance check.
- **Change Password** — Update your account password during a session.
- **Check Balance** — View your current account balance at any time.
- **Logout** — Safely end your banking session.

---

## Getting Started

### Prerequisites

- A C compiler such as **GCC** (GNU Compiler Collection) or **Clang**
- A terminal or command prompt
- Windows, Linux, or macOS

> **Note:** The program uses `system("cls")` to clear the screen, which is Windows-specific. On Linux/macOS, replace `system("cls")` with `system("clear")` before compiling.

### Compilation

Using GCC:

```bash
gcc OnlineBankingC.c -o banking
```

Using Clang:

```bash
clang OnlineBankingC.c -o banking
```

### Running the Program

```bash
./banking         # Linux/macOS
banking.exe       # Windows
```

---

## Usage

### Creating an Account

When the program starts, select option **1** to create a new account:

```
WELCOME TO ONLINE BANKING SYSTEMS

Hello, How can I assist you today?

1. Create Account
2. Login to an Account

Please enter your choice:
> 1

CREATING A NEW ACCOUNT!!!

Enter your name:
> JohnDoe

Enter your New password:
> mypassword

Confirm your New password:
> mypassword

Enter your Email Address:
> john@example.com

Enter your phone number:
> 0712345678

ACCOUNT CREATED SUCCESSFULLY!!
ACCOUNT BALANCE = 0.0
```

### Logging In

Select option **2** from the main menu:

```
Enter your name to login:
> JohnDoe

Enter your password to login:
> mypassword
```

### Banking Operations

Once logged in, you will be presented with the following menu:

```
1. Deposit Funds
2. Withdraw Funds
3. Transfer Funds
4. Change Password
5. Check Balance
6. Logout
```

| Option | Action | Description |
|--------|--------|-------------|
| 1 | Deposit Funds | Enter an amount to add to your balance |
| 2 | Withdraw Funds | Enter an amount to deduct; rejected if balance is insufficient |
| 3 | Transfer Funds | Enter a recipient name and amount; rejected if balance is insufficient |
| 4 | Change Password | Enter a new password to replace the current one |
| 5 | Check Balance | Displays your current balance |
| 6 | Logout | Ends the current session and exits the menu |

**Example — Deposit:**
```
Enter amount to deposit:
> 500.00

Successfully deposited 500.00. New balance: 500.00
```

**Example — Withdrawal (insufficient funds):**
```
Enter amount to withdraw:
> 1000.00

Insufficient balance!
```

**Example — Transfer:**
```
Enter recipient's name:
> JaneDoe

Enter amount to transfer:
> 200.00

Successfully transferred 200.00 to JaneDoe. New balance: 300.00
```

---

## Project Structure

```
OnlineBankingC.c        # Main source file (single-file program)
README.md               # Project documentation
```

### Key Components

**`struct user`** — Holds all data for a single user account:

| Field | Type | Description |
|-------|------|-------------|
| `name` | `char[50]` | Account holder's name |
| `password` | `char[50]` | Account password |
| `email` | `char[20]` | Email address |
| `phone_number` | `int` | Phone number |
| `balance` | `float` | Current account balance |

**`display_menu()`** — Prints the banking operations menu to the console.

**`main()`** — Handles the full program flow: account creation, login, and all banking operations via a `switch` statement loop.

---

## Known Limitations & Bugs

These are existing issues in the current version of the code:

1. **Password confirmation is broken** — During account creation, the confirmation password overwrites the original password in the same field rather than comparing them. A mismatch will not be detected.

2. **No data persistence** — All account data is stored in memory only. When the program exits, all user data is lost. There is no file or database storage.

3. **Single user only** — The system supports only one active user per program run. Multiple accounts cannot be created or stored.

4. **No actual login verification** — The login step copies whatever password is entered into the user struct without comparing it to any stored credential. Any password will "succeed."

5. **Buffer overflow risk** — `scanf("%s", ...)` is used without length limits, making the program vulnerable to buffer overflow if input exceeds the struct field sizes.

6. **Phone number stored as `int`** — Phone numbers can exceed the range of a 32-bit integer and may also require leading zeros. Using a string (`char[15]`) would be more appropriate.

7. **Email field is too small** — `email[20]` may truncate valid email addresses that exceed 20 characters.

8. **`system("cls")` is Windows-only** — This call will fail on Linux and macOS without modification.

9. **No input validation** — The program does not validate negative deposit/withdrawal amounts or non-numeric inputs, which can cause undefined behavior.

---

## Potential Improvements

The following enhancements would significantly improve the robustness and usability of this application:

- **File-based persistence** — Use `fread`/`fwrite` or CSV files to save and load user accounts between sessions.
- **Multi-user support** — Store an array or linked list of `struct user` to support multiple registered accounts.
- **Proper password confirmation** — Compare the two passwords entered during registration before saving.
- **Real authentication** — Verify the entered password against the stored one during login.
- **Input validation** — Check for negative amounts, non-numeric input, and empty strings.
- **Password hashing** — Use a hashing function (e.g., SHA-256 via OpenSSL) instead of storing plain-text passwords.
- **Cross-platform screen clearing** — Replace `system("cls")` with a conditional that uses `system("clear")` on Unix systems.
- **Transaction history** — Log all deposits, withdrawals, and transfers with timestamps.
- **Use `fgets` instead of `scanf`** — Safer string input that prevents buffer overflows.

---

## Contributing

Contributions are welcome. To contribute:

1. Fork the repository.
2. Create a new branch: `git checkout -b feature/your-feature-name`
3. Make your changes and test them.
4. Commit your changes: `git commit -m "Add your feature"`
5. Push to your branch: `git push origin feature/your-feature-name`
6. Open a pull request.

Please document any new functions and follow consistent C coding style.

---

## License

This project is released for educational purposes. No license is currently specified — add one (e.g., MIT, GPL) if you intend to distribute this project.
