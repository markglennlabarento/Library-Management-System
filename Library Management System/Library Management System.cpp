#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Book
{
public:
    int bookID;
    string title;
    string author;
    bool isBorrowed = false;
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
                borrowBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                deleteBook();
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

		// New books are available by default
		books[bookCount].isBorrowed = false;

		bookCount++;

		// Save after adding
		saveToFile();

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
			cout << "Status : " << (books[i].isBorrowed ? "Borrowed" : "Available") << endl;
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

	void borrowBook()
	{
		int bookID;

		cout << "\n[Borrow Book Selected]\n";
		cout << "Enter Book ID to Borrow: ";
		cin >> bookID;

		bool found = false;
		for (int i = 0; i < bookCount; i++)
		{
			if (books[i].bookID == bookID)
			{
				found = true;
				if (!books[i].isBorrowed)
				{
					books[i].isBorrowed = true;
					cout << "\nBook borrowed successfully!\n";
					// Save state
					saveToFile();
				}
				else
				{
					cout << "\nBook is already borrowed!\n";
				}
				break;
			}
		}

		if (!found)
		{
			cout << "\nBook not available for borrowing!\n";
		}
	}

	void returnBook()
	{
		int bookID;
		cout << "\n[Return Book Selected]\n";
		cout << "Enter Book ID to Return: ";
		cin >> bookID;
		bool found = false;
		for (int i = 0; i < bookCount; i++)
		{
			if (books[i].bookID == bookID)
			{
				found = true;
				if (books[i].isBorrowed)
				{
					books[i].isBorrowed = false;
					cout << "\nBook returned successfully!\n";
					// Save state
					saveToFile();
				}
				else
				{
					cout << "\nBook was not borrowed!\n";
				}
				break;
			}
		}
		if (!found)
		{
			cout << "\nBook not found in the system!\n";
		}
	}

	void deleteBook()
	{
		int bookID;
		cout << "\n[Delete Book Selected]\n";
		cout << "Enter Book ID to Delete: ";
		cin >> bookID;
		bool found = false;
		for (int i = 0; i < bookCount; i++)
		{
			if (books[i].bookID == bookID)
			{
				found = true;
				for (int j = i; j < bookCount - 1; j++)
				{
					books[j] = books[j + 1];
				}
				bookCount--;
				cout << "\nBook deleted successfully!\n";
				// Save state
				saveToFile();
				break;
			}
		}
		if (!found)
		{
			cout << "\nBook not found in the system!\n";
		}
	}

	void saveToFile()
	{
		ofstream ofs("books.txt");
		if (!ofs)
		{
			cout << "\nFailed to open file for saving.\n";
			return;
		}

		ofs << bookCount << '\n';
		for (int i = 0; i < bookCount; i++)
		{
			ofs << books[i].bookID << '\n';
			ofs << books[i].title << '\n';
			ofs << books[i].author << '\n';
			ofs << (books[i].isBorrowed ? 1 : 0) << '\n';
		}
		ofs.close();
	}

	void loadFromFile()
	{
		ifstream ifs("books.txt");
		if (!ifs)
			return;

		string line;
		if (!getline(ifs, line))
			return;
		try
		{
			int count = stoi(line);
			bookCount = 0;
			for (int i = 0; i < count && i < 100; i++)
			{
				if (!getline(ifs, line)) break;
				books[i].bookID = stoi(line);
				getline(ifs, books[i].title);
				getline(ifs, books[i].author);
				if (getline(ifs, line))
					books[i].isBorrowed = (line == "1");
				else
					books[i].isBorrowed = false;
				bookCount++;
			}
		}
		catch (...)
		{
			bookCount = 0;
		}
	}
};

int main()
{
	LibrarySystem library;
	library.loadFromFile();
	library.run();

	return 0;
}
