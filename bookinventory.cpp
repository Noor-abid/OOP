#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string bookId;
    string title;
    string author;
    int quantity;

public:
    Book() : bookId(""), title(""), author(""), quantity(0) {}

    Book(const string& id, const string& t, const string& a, int q)
        : bookId(id), title(t), author(a), quantity(q) {}

    // Overloaded stream insertion operator (<<)
    friend ostream& operator<<(ostream& os, const Book& book) {
        os << "Book ID: " << book.bookId << endl;
        os << "Title: " << book.title << endl;
        os << "Author: " << book.author << endl;
        os << "Quantity: " << book.quantity << endl;
        return os;
    }

    // Overloaded stream extraction operator (>>)
    friend istream& operator>>(istream& is, Book& book) {
        cout << "Enter Book ID: ";
        getline(is, book.bookId);
        cout << "Enter Title: ";
        getline(is, book.title);
        cout << "Enter Author: ";
        getline(is, book.author);
        cout << "Enter Quantity: ";
        is >> book.quantity;
        is.ignore(); // Ignore newline character
        return is;
    }

    string getBookId() const { return bookId; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getQuantity() const { return quantity; }
};

class BookInventory {
private:
    Book* books;
    int size;
    int capacity;

public:
    BookInventory() : books(nullptr), size(0), capacity(0) {}

    // Overloaded subscript operator ([])
    Book& operator[](int index) {
        if (index < 0 || index >= size) {
            cerr << "Index out of bounds." << endl;
            exit(1);
        }
        return books[index];
    }

    // Overloaded addition operator (+)
    BookInventory operator+(const BookInventory& other) const {
        BookInventory result;
        result.capacity = size + other.size;
        result.books = new Book[result.capacity];

        for (int i = 0; i < size; ++i) {
            result.books[i] = books[i];
        }

        for (int i = 0; i < other.size; ++i) {
            result.books[size + i] = other.books[i];
        }

        result.size = size + other.size;
        return result;
    }

    void addBook(const Book& book) {
        if (size == capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            Book* temp = new Book[capacity];
            for (int i = 0; i < size; ++i) {
                temp[i] = books[i];
            }
            delete[] books;
            books = temp;
        }
        books[size++] = book;
    }

    void displayInventory() const {
        for (int i = 0; i < size; ++i) {
            cout << "Book " << i + 1 << ":" << endl;
            cout << books[i] << endl;
        }
    }

    Book* searchByTitle(const string& title) const {
        for (int i = 0; i < size; ++i) {
            if (books[i].getTitle() == title) {
                return &books[i];
            }
        }
        return nullptr;
    }

    ~BookInventory() {
        delete[] books;
    }
};

int main() {
    BookInventory library1, library2;

    // Add books to library1
    library1.addBook(Book("B001", "The Lord of the Rings", "J.R.R. Tolkien", 5));
    library1.addBook(Book("B002", "1984", "George Orwell", 3));

    // Add books to library2
    library2.addBook(Book("B003", "Pride and Prejudice", "Jane Austen", 2));
    library2.addBook(Book("B001", "The Lord of the Rings", "J.R.R. Tolkien", 2)); // Duplicate book

    // Combine libraries
    BookInventory combinedLibrary = library1 + library2;

    // Display combined inventory
    cout << "Combined Library Inventory:" << endl;
    combinedLibrary.displayInventory();

    // Search for a book
    string searchTitle;
    cout << "Enter book title to search: ";
    getline(cin, searchTitle);

    Book* foundBook = combinedLibrary.searchByTitle(searchTitle);
    if (foundBook) {
        cout << "Book Found:" << endl;
        cout << *foundBook << endl;
    } else {
        cout << "Book not found." << endl;
    }

    return 0;
}