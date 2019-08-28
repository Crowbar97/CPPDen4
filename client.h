#include <string>

#ifndef CPPDEN4_CLIENT_H
#define CPPDEN4_CLIENT_H

namespace client {

// Клиент книжного магазина
class Client {
public:
    std::string surname;
    std::string phone_number;
    std::string email;

    Client(const std::string& surname, const std::string& phone_number, const std::string& email) {
        this->surname = surname;
        this->phone_number = phone_number;
        this->email = email;
    }
};

}

#endif
