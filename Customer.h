#include <string>
#ifndef CUSTOMER_H
#define CUSTOMER_H
class Customer {
    private:
        int idCustomer;
        std::string nombre;
        std::string correo;
    public:
        Customer(int id, std::string n, std::string c)
        :idCustomer(id), nombre(n), correo(c)
        {}

        std::string getNombre() const;
};
#endif