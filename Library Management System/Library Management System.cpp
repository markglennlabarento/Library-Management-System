#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    int bookID;
    string title;
    string author;
};

class LibrarySystem
{
private:
    Book books[100];
    int bookCount = 0;
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
				addBook();
                break;

            case 2:
                viewBooks();
                break;

            case 3:
                searchBook();
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

    void addBook()
    {
        if (bookCount >= 100)
        {
            cout << "\nLibrary storage is full!\n";
            return;
        }

        cout << "\n===== ADD BOOK =====\n";

        cout << "Enter Book ID: ";
        cin >> books[bookCount].bookID;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, books[bookCount].title);

        cout << "Enter Author Name: ";
        getline(cin, books[bookCount].author);

        bookCount++;

        cout << "\nBook added successfully!\n";
    }

    void viewBooks()
    {
        if (bookCount == 0)
        {
            cout << "\nNo books available.\n";
            return;
        }

        cout << "\n===== BOOK LIST =====\n";

        for (int i = 0; i < bookCount; i++)
        {
            cout << "\nBook #" << i + 1 << endl;
            cout << "ID     : " << books[i].bookID << endl;
            cout << "Title  : " << books[i].title << endl;
            cout << "Author : " << books[i].author << endl;
        }
    }

	void searchBook()
	{
		int searchID;
		cout << "\nSearch Book ID: ";
		cin >> searchID;

		bool found = false;
		for (int i = 0; i < bookCount; i++)
		{
			if (books[i].bookID == searchID)
			{
				cout << "\nBook Found!\n";
				cout << "ID     : " << books[i].bookID << endl;
				cout << "Title  : " << books[i].title << endl;
				cout << "Author : " << books[i].author << endl;
				found = true;
				break;
			}
		}

		if (!found)
		{
			cout << "\nBook Not Found!\n";
		}
	}
};

int main()
{
    LibrarySystem library;
    library.run();

    return 0;
}