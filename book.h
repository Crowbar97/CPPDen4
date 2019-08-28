#include <iostream>
#include <string>

#ifndef CPPDEN4_BOOK_H
#define CPPDEN4_BOOK_H

namespace bookstore {

// Книга
class Book {
public:
    // идентификатор
    size_t isbn;
    std::string category;
    std::string topic;
    std::string name;
    size_t year;
    size_t page_count;
    std::string publisher;
    std::string authors;

    size_t price;

    Book(size_t isbn) {
        this->isbn = isbn;
    }
    Book(size_t isbn, const std::string& name, const std::string& publisher) {
        this->isbn = isbn;
        this->name = name;
        this->publisher = publisher;
    }

//    bool operator==(const Book& book) {
//        return isbn == book.isbn;
//    }

    bool operator<(const Book& book) const {
        return isbn < book.isbn;
    }
};

}

#endif
