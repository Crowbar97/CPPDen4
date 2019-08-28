#include <iostream>
#include "bookstore.h"
#include "book.h"
#include "client.h"

using namespace std;
using namespace bookstore;
using namespace client;

// Задание 3.3 - Система контроля ассортимента книжного магазина
int main() {
    // создаем книжный магазин
    BookStore bs;
    // создаем клиента
    Client client("Ivanov", "223-322", "Ivanov@gmail.com");
    // создаем его заказ
    map<Book, size_t> book_order = { { Book(1), 5 }, { Book(2), 78 } };
    // заказываем
    bs.sell(book_order, client);
}