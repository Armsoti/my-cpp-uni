#include <iostream>

class User;

class Library 
{
private:

	int total_books;

public:
	Library(int start_books)
	{
		total_books = start_books;
	}

	friend void checkBooks(Library& lib, User& user);

};

class User
{
private:
	int requested_books;

public:
	User(int books)
	{
		requested_books = books;
	}

	friend void checkBooks(Library& lib, User& user);

};

void checkBooks(Library& lib, User& user)
{
	if (lib.total_books >= user.requested_books)
	{
		std::cout << "Books are available for checkout.\n";
	}
	else
	{
		std::cout << "Not enough books available for checkout.\n";
	}
}

int main()
{
	Library lib1(100); // Library with 100 books
	User user1(30); // User requests 30 books

	checkBooks(lib1, user1); // Check if the library can fulfill the user's request

	Library lib2(10); // Library with 100 books
	User user2(30); // User requests 30 books

	checkBooks(lib2, user2);
}