#include <map>
#include <string>
#include "book.h"
#include "client.h"

#ifndef CPPDEN4_BOOKSTORE_H
#define CPPDEN4_BOOKSTORE_H

namespace bookstore {

// Книжный магазин
class BookStore {
private:
    // количества книг
    std::map<Book, size_t> counts;
    // рейтинги книг
    std::map<size_t, size_t> ratings;

public:
    BookStore() {
        // добавим несколько книг
        counts[Book(1, "Fairy Tales", "ChildBook")] = 25;
        counts[Book(2, "Moby Dick", "AmericanClassic")] = 34;
        counts[Book(3, "Java", "ProgLang")] = 48;
        counts[Book(4, "How to build a plane", "DIYBooks")] = 38;
        counts[Book(5, "Car repairing", "DIYBooks")] = 23;
    }

private:
    void buy(const Book& book, size_t count);
    void update_rating(size_t isbn, size_t count);
    void reset_ratings();

public:
    size_t min_count(const Book &book);
    void check_count(const Book& book);
    void sell(const std::map<Book, size_t>& book_order, const client::Client& client);
};

//-Реализация----------------------------------------------------------------------

// обновление рейтинга указанной книги
void BookStore::update_rating(size_t isbn, size_t count) {
    ratings[isbn] += count;
}

// сброс рейтингов
void BookStore::reset_ratings() {
        ratings.clear();
    }

// закупка магазином указанной книги в указанном количестве
void BookStore::buy(const Book& book, size_t count) {
    counts[book] += count;
}

// расчет минимального наличного количества экземпляров указанной книги на складе
size_t BookStore::min_count(const Book &book) {
    return (size_t) (ratings[book.isbn] * 0.1);
}

// проверка остатка указанной книги на складе
void BookStore::check_count(const Book& book) {
    size_t req_count = min_count(book);
    size_t act_count = counts[book];

    if (act_count < req_count)
        buy(book, req_count - act_count);
}

// продажа указанного набора книг клиенту
void BookStore::sell(const std::map<Book, size_t>& book_order, const client::Client& client) {
    // проходим по каждой записи (книга, количество) заказа
    for (auto entry : book_order) {
        // заносим значения записи в переменные
        Book book = entry.first;
        size_t des_count = entry.second;

        // если требуемое количество книги больше, чем есть на складе
        if (des_count > counts[book])
            // то закупаем требуемое количество книг у издателя
            buy(book, des_count - counts[book]);

        // продаем книги
        counts[book] -= des_count;

        // обновляем рейтинг книги
        update_rating(book.isbn, des_count);
        // проверяем остаток на складе
        check_count(book);
    }
}

}

#endif
