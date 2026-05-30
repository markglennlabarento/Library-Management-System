#include <iostream>
using namespace std;

class LibrarySystem
{
public:
    void printBanner()
    {
        cout << "=========================================================\n";
        cout << "        _     ___ ____  ____      _    ____  __   __\n";
        cout << "       | |   |_ _| __ )|  _ \\    / \\  |  _ \\ \\ \\ / /\n";
        cout << "       | |    | ||  _ \\| |_) |  / _ \\ | |_) |  \\ V / \n";
        cout << "       | |___ | || |_) |  _ <  / ___ \\|  _ <    | |  \n";
        cout << "       |_____|___|____/|_| \\_\\/_/   \\_\\_| \\_\\   |_|  \n";
        cout << "\n";
        cout << "              LIBRARY MANAGEMENT SYSTEM\n";
        cout << "=========================================================\n";
        cout << "      Manage Books | Borrow | Return | Search\n";
        cout << "=========================================================\n";
    }

    void displayMenu()
    {
        cout << "\n========== MAIN MENU ==========\n";
        cout << " [1] Add Book\n";
        cout << " [2] View Books\n";
        cout << " [3] Search Book\n";
        cout << " [4] Borrow Book\n";
        cout << " [5] Return Book\n";
        cout << " [6] Delete Book\n";
        cout << " [7] Exit\n";
        cout << "===============================\n";
        cout << "Enter Choice: ";
    }

    void run()
    {
        int choice;

        do
        {
            system("cls"); // Use "clear" on Linux/Mac
            printBanner();
            displayMenu();

            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "\n[Add Book Selected]\n";
                break;

            case 2:
                cout << "\n[View Books Selected]\n";
                break;

            case 3:
                cout << "\n[Search Book Selected]\n";
                break;

            case 4:
                cout << "\n[Borrow Book Selected]\n";
                break;

            case 5:
                cout << "\n[Return Book Selected]\n";
                break;

            case 6:
                cout << "\n[Delete Book Selected]\n";
                break;

            case 7:
                cout << "\nThank you for using Library Management System!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
            }

            if (choice != 7)
            {
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
            }

        } while (choice != 7);
    }
};

int main()
{
    LibrarySystem library;
    library.run();

    return 0;
}