#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

// Клас, що описує сутність "Книга"
class Book {
private:
    string title;
    string author;
    int year;

public:
    // Конструктор для створення об'єкта
    Book(string t, string a, int y) : title(t), author(a), year(y) {}

    // Метод для виведення інформації про книгу
    void printInfo() const {
        cout << "Книга: \"" << title << "\", Автор: " << author << ", Рік: " << year << endl;
    }

    // Метод для зміни року видання
    void setYear(int newYear) {
        if (newYear > 0) {
            year = newYear;
        }
    }

    string getTitle() const {
        return title;
    }
};

// Додатковий клас для демонстрації зв'язку
class Library {
private:
    string name;
    vector<Book> books; // Бібліотека містить список книг

public:
    Library(string n) : name(n) {}

    // Метод для додавання книги в бібліотеку
    void addBook(const Book& b) {
        books.push_back(b);
    }

    // Виведення всіх книг бібліотеки
    void showAllBooks() const {
        cout << "\nБібліотека: " << name << "" << endl;
        for (const auto& book : books) {
            book.printInfo();
        }
    }
};

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    // Створення об'єктів класу Book
    Book book1("1984", "Джордж Оруелл", 1949);
    Book book2("Кобзар", "Тарас Шевченко", 1840);

    // Демонстрація методів класу Book
    cout << "Початкові дані:" << endl;
    book1.printInfo();

    cout << "\nЗмінення року видання для першої книги" << endl;
    book1.setYear(1950);
    book1.printInfo();

    // Демонстрація взаємодії з класом Library
    Library myLibrary("Студентська бібліотека");
    myLibrary.addBook(book1);
    myLibrary.addBook(book2);

    // Вивід інформації про всі книги в бібліотеці
    myLibrary.showAllBooks();

    return 0;
}