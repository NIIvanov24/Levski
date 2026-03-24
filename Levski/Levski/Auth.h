#pragma once
#pragma once
#ifndef AUTH_H
#define AUTH_H
// Auth.h - Login & Register system

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#ifdef _WIN32
#include <conio.h>   // _getch() for hidden password input
#endif

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BRED     "\033[91m"
#define BGREEN   "\033[92m"
#define BYELLOW  "\033[93m"
#define BBLUE    "\033[94m"
#define BMAGENTA "\033[95m"
#define BCYAN    "\033[96m"
#define BWHITE   "\033[97m"

// The file where usernames and passwords are stored (one per line: "username:password")
static const string USERS_FILE = "users.txt";

// ─────────────────────────────────────────────
// Read password character by character so it
// shows '*' instead of the actual letters.
// ─────────────────────────────────────────────
string readPassword()
{
    string pass = "";
    char ch;
    while (true)
    {
#ifdef _WIN32
        ch = (char)_getch();
#else
        // On Linux/Mac without conio: just read normally (no masking)
        ch = (char)cin.get();
#endif
        if (ch == '\r' || ch == '\n') break;   // Enter pressed
        if (ch == '\b' || ch == 127)            // Backspace
        {
            if (!pass.empty())
            {
                pass.pop_back();
                cout << "\b \b" << flush;
            }
            continue;
        }
        pass += ch;
        cout << '*' << flush;
    }
    cout << '\n';
    return pass;
}

// ─────────────────────────────────────────────
// Check if a username already exists in the file
// ─────────────────────────────────────────────
bool userExists(const string& username)
{
    ifstream file(USERS_FILE);
    if (!file.is_open()) return false;

    string line;
    while (getline(file, line))
    {
        size_t sep = line.find(':');
        if (sep == string::npos) continue;
        string storedUser = line.substr(0, sep);
        if (storedUser == username)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// ─────────────────────────────────────────────
// Validate login — returns true if match found
// ─────────────────────────────────────────────
bool validateLogin(const string& username, const string& password)
{
    ifstream file(USERS_FILE);
    if (!file.is_open()) return false;

    string line;
    while (getline(file, line))
    {
        size_t sep = line.find(':');
        if (sep == string::npos) continue;
        string storedUser = line.substr(0, sep);
        string storedPass = line.substr(sep + 1);
        if (storedUser == username && storedPass == password)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// ─────────────────────────────────────────────
// Save a new user to the file
// ─────────────────────────────────────────────
bool registerUser(const string& username, const string& password)
{
    if (userExists(username)) return false;   // duplicate

    ofstream file(USERS_FILE, ios::app);
    if (!file.is_open()) return false;

    file << username << ":" << password << "\n";
    file.close();
    return true;
}

// ─────────────────────────────────────────────
// REGISTER PAGE
// ─────────────────────────────────────────────
void showRegisterPage()
{
    while (true)
    {
        system("cls");
        cout << BBLUE << "==============================\n" << RESET;
        cout << BGREEN << "          REGISTER            \n" << RESET;
        cout << BBLUE << "==============================\n\n" << RESET;

        string username, password, confirm;

        cout << BCYAN << "  Username : " << RESET;
        cin >> username;

        if (username.empty())
        {
            cout << BRED << "\n  Username cannot be empty!\n" << RESET;
            cout << "\n  Press ENTER to try again...";
            cin.ignore(); cin.get();
            continue;
        }

        if (userExists(username))
        {
            cout << BRED << "\n  Username already taken! Choose another.\n" << RESET;
            cout << "\n  Press ENTER to try again...";
            cin.ignore(); cin.get();
            continue;
        }

        cout << BCYAN << "  Password : " << RESET;
        cin.ignore();
        password = readPassword();

        cout << BCYAN << "  Confirm  : " << RESET;
        confirm = readPassword();

        if (password != confirm)
        {
            cout << BRED << "\n  Passwords do not match!\n" << RESET;
            cout << "\n  Press ENTER to try again...";
            cin.get();
            continue;
        }

        if (password.size() < 4)
        {
            cout << BRED << "\n  Password must be at least 4 characters!\n" << RESET;
            cout << "\n  Press ENTER to try again...";
            cin.get();
            continue;
        }

        if (registerUser(username, password))
        {
            cout << BGREEN << "\n  Account created successfully!\n" << RESET;
            cout << BYELLOW << "  You can now log in.\n" << RESET;
            cout << "\n  Press ENTER to continue...";
            cin.get();
            return;
        }
        else
        {
            cout << BRED << "\n  Error saving user. Try again.\n" << RESET;
            cout << "\n  Press ENTER to try again...";
            cin.get();
        }
    }
}

// ─────────────────────────────────────────────
// LOGIN PAGE — returns the logged-in username,
// or empty string if the user chose to exit.
// ─────────────────────────────────────────────
string showLoginPage()
{
    while (true)
    {
        system("cls");
        cout << BBLUE << "=============================================================\n" << RESET;
        cout << BBLUE << "|||       ||||||||  |||        |||  ||||||||  |||   ||| |||||\n" << RESET;
        cout << BBLUE << "|||       |||        |||      |||  |||        |||  |||   |||\n" << RESET;
        cout << BBLUE << "|||       |||         |||    |||   |||        ||| |||    |||\n" << RESET;
        cout << BBLUE << "|||       |||||||     |||    |||   |||||||||  ||||       |||\n" << RESET;
        cout << BBLUE << "|||       |||           ||| |||          |||  ||| |||    |||\n" << RESET;
        cout << BBLUE << "|||       |||           ||| |||          |||  |||  |||   |||\n" << RESET;
        cout << BBLUE << "||||||||  ||||||||        |||      ||||||||   |||   ||| |||||\n" << RESET;
        cout << BBLUE << "=============================================================\n" << RESET;
        cout << BGREEN << "                  ELECTRONIC SCHOOL SYSTEM\n" << RESET;
        cout << BBLUE << "=============================================================\n\n" << RESET;

        cout << BWHITE << "  1. Login\n" << RESET;
        cout << BWHITE << "  2. Register\n" << RESET;
        cout << BRED << "  3. Exit\n\n" << RESET;
        cout << BYELLOW << "  Choice: " << RESET;

        int ch;
        cin >> ch;
        if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); continue; }

        if (ch == 3) return "";   // user wants to exit the whole program

        if (ch == 2)
        {
            showRegisterPage();
            continue;
        }

        if (ch == 1)
        {
            system("cls");
            cout << BBLUE << "==============================\n" << RESET;
            cout << BCYAN << "            LOGIN             \n" << RESET;
            cout << BBLUE << "==============================\n\n" << RESET;

            string username, password;

            cout << BCYAN << "  Username : " << RESET;
            cin >> username;

            cout << BCYAN << "  Password : " << RESET;
            cin.ignore();
            password = readPassword();

            if (validateLogin(username, password))
            {
                system("cls");
                cout << BBLUE << "==============================\n" << RESET;
                cout << BGREEN << "  Welcome back, " << username << "!\n" << RESET;
                cout << BBLUE << "==============================\n\n" << RESET;
                cout << "\n  Press ENTER to continue...";
                cin.get();
                return username;   // ← logged in successfully
            }
            else
            {
                cout << BRED << "\n  Wrong username or password!\n" << RESET;
                cout << "\n  Press ENTER to try again...";
                cin.get();
            }
        }
    }
}

#endif
