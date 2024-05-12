#include <iostream>
#include <windows.h>
#include <Lmcons.h>
#include <fstream>
#include <windows.h> 
#include <string>


using namespace std;

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    wchar_t  username[UNLEN + 1];
    DWORD username_len = UNLEN + 1;
    GetUserName(username, &username_len); // Grabs window username system
    string key = "bCzeMPzIWoO3Q6mfaL2eZVM876Q7H6Rr";

    bool authverified = false;

    std::ifstream keyfilecheck("key.txt");
    if (keyfilecheck.good()) { // Check for file being on computer
        cout << "File Found\n";
        if (keyfilecheck.is_open()) {
            std::string line;
            while (std::getline(keyfilecheck, line)) {
                if (line == key) {
                    std::cout << "Key found in file.\n";
                    authverified = true;
                }
            }
            if (!authverified) {
                std::cout << "Key not found in file.\n ";
                authverified = false;
            }
        }
        else {
            std::cout << "Unable to open file.\n";
            authverified = false;
        }
    }

    if (!authverified) {
        std::ofstream keyfile("key.txt"); // creates key if computer doesnt find it
        Sleep(2000);
        system("cls");

        wprintf(L"Username: %ls\n", username);
        cout << "Key: ";
        cin >> key;

        if (key == "bCzeMPzIWoO3Q6mfaL2eZVM876Q7H6Rr") {
            cout << "Valid Key " ;
            keyfile << "bCzeMPzIWoO3Q6mfaL2eZVM876Q7H6Rr";
            authverified = true;
        }
        else {
            authverified = false;
            cout << "Invalid Key ";
        }
        keyfile.close();
       
    }

    if (authverified) {
        Sleep(2000);
        system("cls");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        cout << "Welcome to marcels dungeon " <<username;


    }
}