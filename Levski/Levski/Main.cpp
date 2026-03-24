#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#ifdef _WIN32
#include <conio.h>    // _getch() for arrow keys
#endif
#include "Auth.h"      // Login / Register  (must come BEFORE Functions.h)
#include "Functions.h"
#include "Question.h"
#include "Test.h"
using namespace std;

// ── Color macros (kept here too so Main.cpp compiles stand-alone) ──
#define RESET    "\033[0m"
#define BRED     "\033[91m"
#define BGREEN   "\033[92m"
#define BYELLOW  "\033[93m"
#define BBLUE    "\033[94m"
#define BMAGENTA "\033[95m"
#define BCYAN    "\033[96m"
#define BWHITE   "\033[97m"
#define MAGENTA  "\033[35m"

// ── Hide / show cursor ──────────────────────────────────────────────
void hideCursor() { cout << "\033[?25l" << flush; }
void showCursor() { cout << "\033[?25h" << flush; }

// ── Draw the main menu with an arrow cursor ─────────────────────────
void drawMainMenu(int selected, const string& loggedUser)
{
    system("cls");

    // ASCII banner
    cout << BBLUE << "=============================================================\n";
    cout << "|||       ||||||||  |||        |||  ||||||||  |||   ||| |||||\n";
    cout << "|||       |||        |||      |||  |||        |||  |||   |||\n";
    cout << "|||       |||         |||    |||   |||        ||| |||    |||\n";
    cout << "|||       |||||||     |||    |||   |||||||||  ||||       |||\n";
    cout << "|||       |||           ||| |||          |||  ||| |||    |||\n";
    cout << "|||       |||           ||| |||          |||  |||  |||   |||\n";
    cout << "||||||||  ||||||||        |||      ||||||||   |||   ||| |||||\n";
    cout << "=============================================================\n" << RESET;
    cout << BGREEN << "                  ELECTRONIC SCHOOL SYSTEM\n" << RESET;
    cout << BBLUE << "=============================================================\n" << RESET;
    cout << BCYAN << "  Logged in as: " << BWHITE << loggedUser << "\n" << RESET;
    cout << BBLUE << "=============================================================\n\n" << RESET;

    // Menu items
    const char* items[] = {
        "Study Materials",
        "Exercises",
        "Take Test",
        "Statistics",
        "Homework",
        "Classwork",
        "Exit"
    };
    int count = 7;

    for (int i = 0; i < count; i++)
    {
        if (i == selected)
            // Selected row: arrow + highlight
            cout << BGREEN << "  --> " << BYELLOW << items[i] << RESET << "\n";
        else
            cout << BWHITE << "      " << items[i] << RESET << "\n";
    }

    cout << "\n" << BBLUE << "  [UP/DOWN arrows to move | ENTER to select]\n" << RESET;
}

// ── Read a key and return a simple code ─────────────────────────────
//   Returns: 'U' = up, 'D' = down, 'E' = enter, 'X' = other
char readKey()
{
#ifdef _WIN32
    int ch = _getch();
    if (ch == 224 || ch == 0)   // special key prefix on Windows
    {
        int ch2 = _getch();
        if (ch2 == 72) return 'U';  // Up arrow
        if (ch2 == 80) return 'D';  // Down arrow
    }
    if (ch == 13) return 'E';   // Enter
    return 'X';
#else
    // Linux / Mac — read ESC sequences
    int ch = getchar();
    if (ch == '\n' || ch == '\r') return 'E';
    if (ch == 27)   // ESC
    {
        int ch2 = getchar();
        if (ch2 == '[')
        {
            int ch3 = getchar();
            if (ch3 == 'A') return 'U';
            if (ch3 == 'B') return 'D';
        }
    }
    return 'X';
#endif
}

// ── Main ─────────────────────────────────────────────────────────────
int main()
{
    // ── 1. Login / Register before anything else ──
    string loggedUser = showLoginPage();
    if (loggedUser.empty())
    {
        // User chose Exit from the login screen
        system("cls");
        cout << BMAGENTA << "\n  Goodbye!\n\n" << RESET;
        return 0;
    }

    // ── 2. Main menu with arrow navigation ──
    int selected = 0;
    const int MENU_COUNT = 7;

    hideCursor();

    while (true)
    {
        drawMainMenu(selected, loggedUser);

        char key = readKey();

        if (key == 'U')
        {
            selected = (selected - 1 + MENU_COUNT) % MENU_COUNT;
        }
        else if (key == 'D')
        {
            selected = (selected + 1) % MENU_COUNT;
        }
        else if (key == 'E')
        {
            showCursor();   // restore cursor inside sub-menus
            switch (selected)
            {
            case 0: showStudyMaterials(); break;
            case 1: showExercises();      break;
            case 2: startTest();          break;
            case 3: showStatistics();     break;
            case 4: showHomework();       break;
            case 5: showClasswork();      break;
            case 6:
                showCursor();
                system("cls");
                cout << BMAGENTA << "\n  Goodbye, " << loggedUser << "!\n\n" << RESET;
                return 0;
            }
            hideCursor();   // hide again after returning from sub-menu
        }
    }

    showCursor();
    return 0;
}