#include <iostream>
#include <string>

using namespace std;

struct Book {
    int idBook;
    string nameBook;
    string author;
    float price;

    void inputInfo() {
        cout << "Nhap ma sach: ";
        cin >> idBook;

        cout << "Nhap ten sach: ";
        cin >> nameBook;

        cout << "Nhap ten tac gia: ";
        cin >> author;

        cout << "Nhap gia sach: ";
        cin >> price;
    }

    void outputInfo() {
        cout << "Ma sach: " << idBook << endl;
        cout << "Ten sach: " << nameBook << endl;
        cout << "Tac gia: " << author << endl;
        cout << "Gia sach: " << price << endl;
    }
};

struct Library {
    int idLibrary;
    string nameLibrary;
    int numBooks;
    Book books[100];

    void inputLibrary() {
        cout << "Nhap ma thu vien: ";
        cin >> idLibrary;

        cout << "Nhap ten thu vien: ";
        cin >> nameLibrary;

        cout << "Nhap so luong sach: ";
        cin >> numBooks;

        for (int i = 0; i < numBooks; i++) {
            cout << "\nNhap thong tin sach thu " << i + 1 << " ---\n";
            books[i].inputInfo();
        }
    }

    void outputLibrary() {
        cout << "\nTHONG TIN THU VIEN\n";

        cout << "Ma thu vien: " << idLibrary << endl;
        cout << "Ten thu vien: " << nameLibrary << endl;
        cout << "So luong sach: " << numBooks << endl;

        for (int i = 0; i < numBooks; i++) {
            cout << "\nSach thu " << i + 1 << " \n";
            books[i].outputInfo();
        }
    }

    void addBook(Book a) {
        books[numBooks] = a;
        numBooks++;
    }

    Book getBookInfo(int idBook) {
        for (int i = 0; i < numBooks; i++) {
            if (books[i].idBook == idBook) {
                return books[i];
            }
        }

        return Book();
    }

    Book* getBooks() {
        return books;
    }
};

int main() {
    Library library;

    library.inputLibrary();
    library.outputLibrary();

    return 0;
}