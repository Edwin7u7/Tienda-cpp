#include <string>
#ifndef STORE_H
#define STORE_H
#include "Customer.h"
#include <vector>
class Store {
private:
    std::string name;

    Inventario inventario;

    vector<Customer> customers;

    vector<Order> orders;

public:
    Store(std::string nombre);

    void registrarCliente(
        const Customer& customer);

    void crearPedido();

    void mostrarInventario();
};

#endif