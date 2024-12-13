#include <iostream>
#include <string>

struct Book {
    std::string title;
    std::string author;
    int year;
    int ID;
    std::string publisher;
};

int main() {
    Book book1;
    book1.title = "World";
    book1.author = "Me";
    book1.year = 1985;
    book1.ID = 12;
    book1.publisher = "Venezia";

    Book book2;
    book2.title = "Friuli";
    book2.author = "MT";
    book2.year = 1946;
    book2.ID = 22;
    book2.publisher = "Savorgnano";

    std::cout << "Book 1 Details:" << std::endl;
    std::cout << book1.title << std::endl;
    std::cout << book1.author << std::endl;
    std::cout << book1.year << std::endl;
    std::cout << book1.ID << std::endl;
    std::cout << book1.publisher << std::endl;

    std::cout << "Book 2 Details:" << std::endl;
    std::cout << book2.title << std::endl;
    std::cout << book2.author << std::endl;
    std::cout << book2.year << std::endl;
    std::cout << book2.ID << std::endl;
    std::cout << book2.publisher << std::endl;

    return 0;
}