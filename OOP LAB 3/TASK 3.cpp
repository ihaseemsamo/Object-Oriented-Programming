#include<iostream>
using namespace std;

class Library {
    private:
        string bookList[100];
        string borrowedBooks[100];
        string students[100];
        int availableBooks[100];
        int books;
        int borrowedBooksCount;

    public:
        Library() {
            books = 0;
            borrowedBooksCount = 0;
        }

        void addBook(string bookName) {
            if(books < 100) {
                bookList[books] = bookName;
                availableBooks[books] = 1;
                books++;
                cout << "Book added!" << endl;
            } else {
                cout << endl << "Unable to add!" << endl;
            }
        }

        void lendBook(string bookName, string studentName) {
            for(int i = 0; i < books; i++) {
                if(bookList[i] == bookName && availableBooks[i] == 1 && borrowedBooksCount < 100) {
                    cout << "Book issued to " << studentName << endl;
                    availableBooks[i] = 0;
                    students[borrowedBooksCount] = studentName;
                    borrowedBooks[borrowedBooksCount] = bookName;
                    borrowedBooksCount++;
                    break;
                }
            }
        }

        void returnBook(string bookName, string studentName) {
            int found = 0;
            for(int i = 0; i < borrowedBooksCount; i++) {
                if(borrowedBooks[i] == bookName) {
                    found = 1;
                    for(int j = i; j < borrowedBooksCount - 1; j++) {
                        borrowedBooks[j] = borrowedBooks[j + 1];
                        students[j] = students[j + 1];
                    }
                    borrowedBooksCount--;
                    break;
                }
            }

            if(found == 0) {
                return;
            }

            for(int i = 0; i < books; i++) {
                if(bookList[i] == bookName) {
                    availableBooks[i] = 1;
                    break;
                }
            }

            cout << "Book returned by " << studentName << endl;
        }

        void AvailableBooks() {
            int k = 0;
            cout << "Available books:";
            for(int i = 0; i < books; i++) {
                if(availableBooks[i] == 1) {
                    cout << endl << ++k << ". " << bookList[i];
                }
            }

            if(k == 0) {
                cout << " No book available";
            }
            cout << endl;
        }
};

int main() {
    
    Library Peshawar;
    
    Peshawar.addBook("Silent Patient");
    
    Peshawar.AvailableBooks();

    Peshawar.addBook("Horrid Henry");
    
    Peshawar.AvailableBooks();
    
    Peshawar.lendBook("Silent Patient", "Hamza");
    
    Peshawar.AvailableBooks();
    
    Peshawar.returnBook("Silent Patient", "Hamza");
    
    Peshawar.AvailableBooks();

    return 0;
}

