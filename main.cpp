#include <iostream>
#include <memory>
#include "Store.h"
#include "Electronic.h"
#include "Accesory.h"
#include "CardPayment.h"
#include "CashPayment.h"

using namespace std;

int main()
{
    Store store("TechStore");

    std::unique_ptr<Order> actualOrder;

    int option;

    do
    {
        cout << "\n===== STORE =====\n";
        cout << "1. Add Product to Inventory\n";
        cout << "2. Show Inventory\n";
        cout << "3. Search product\n";
        cout << "4. Insert new Costumer\n";
        cout << "5. Create Order\n";
        cout << "6. Add Product to Order\n";
        cout << "7. Calculate order total\n";
        cout << "8. Show order\n";
        cout << "9. Pay order\n";
        cout << "10. Sell product\n";
        cout << "11. Compare products\n";
        cout << "12. Exit\n";
        cout << "Option: ";
        cin >> option;

        try
        {
            switch(option)
            {
                case 1:
                {
                    cout << "\n====Select product type=====\n";
                    int type;

                    cout << "\n1. Electronic device\n";
                    cout << "2. Accesory\n";
                    cout << "Type: ";
                    cin >> type;

                    int id;
                    string name;
                    float price;
                    int stock;

                    cout << "ID: ";
                    cin >> id;

                    cin.ignore();

                    cout << "Name: ";
                    getline(cin,name);

                    cout << "Price: ";
                    cin >> price;

                    cout << "Stock: ";
                    cin >> stock;

                    if(type == 1)
                    {
                        int garantia;

                        cout << "Guarantee (Months): ";
                        cin >> garantia;

                        store.getInventory().addProduct(make_unique<Electronic>(
                                    id,
                                    name,
                                    price,
                                    stock,
                                    garantia
                                ));
                    }
                    else
                    {
                        string material;

                        cin.ignore();

                        cout << "Material: ";
                        getline(cin,material);

                        store.getInventory().addProduct(make_unique<Accesory>(
                                    id,
                                    name,
                                    price,
                                    stock,
                                    material
                                ));
                    }

                    break;
                }
                case 2:
                {
                    cout << "\n======Inventory======\n";
                    store.showInventory();
                    break;
                }
                case 3:
                {
                    cout << "\n=====Search product=====\n";
                    int id;
                    cout << "ID product: ";
                    cin >> id;

                    Product* product =store.getInventory().searchProduct(id);

                    if(product)
                    {
                        product->showProduct();
                    }
                    else
                    {
                        cout << "Not found\n";
                    }
                    break;
                }

                case 4:
                {
                    cout << "\n====New costumer====\n";
                    int id;
                    string nombre;
                    string correo;

                    cout << "ID cliente: ";
                    cin >> id;

                    cin.ignore();

                    cout << "Nombre: ";
                    getline(cin,nombre);

                    cout << "Correo: ";
                    getline(cin,correo);

                    Customer customer(
                        id,
                        nombre,
                        correo
                    );
                    store.registerClient(customer);
                    cout << "Cliente registrado\n";
                    break;
                }
                
                case 5:
                {
                    cout << "\n====Creating order====\n";
                    int idOrder;
                    cout << "ID order: ";
                    cin >> idOrder;
                    Customer customer(
                        1,
                        "Cliente General",
                        "correo@test.com"
                    );
                    actualOrder = std::make_unique<Order>(idOrder, customer);
                    cout << "Order created\n";
                    break;
                }

                case 6:
                {
                    cout << "\n====Adding product to order====\n";
                    if(actualOrder == nullptr)
                    {
                        cout << "Must create an order first\n";
                        break;
                    }
                    int idProducto;

                    cout << "ID Product: ";
                    cin >> idProducto;
                    Product* product =
                        store.getInventory().searchProduct(idProducto);
                    if(product != nullptr)
                    {
                        actualOrder->addProduct(product);
                        cout<< "Product added\n";
                    }
                    else
                    {
                        cout<< "Product not found\n";
                    }

                    break;
                }

                case 7:
                {
                    cout << "\n===Order total price $====\n";
                    if(actualOrder == nullptr)
                    {
                        cout << "Order does not exist\n";
                        break;
                    }
                    cout<< "Total: $"<< actualOrder->calculateTotal()<< endl;

                    break;
                }
                case 8:
                {
                    if(actualOrder != nullptr){
                        cout << "\n====Order====\n";
                        actualOrder->showOrder();
                    }
                    else{
                        cout << "\nOrden inexistente\n";
                    }
                    break;
                    
                }
                
                case 9:
                {
                    cout << "\n====Payment process=====\n";
                    if(actualOrder == nullptr)
                    {
                        cout << "No existe pedido\n";
                        break;
                    }

                    int tipoPago;

                    cout << "\n1. Tarjeta\n";
                    cout << "2. Efectivo\n";
                    cout << "Metodo: ";
                    cin >> tipoPago;

                    float total =actualOrder->calculateTotal();

                    if(tipoPago == 1)
                    {
                        string tarjeta;

                        cout << "Numero tarjeta: ";
                        cin >> tarjeta;

                        actualOrder->asignPayment(make_unique<CardPayment>(total,tarjeta));
                    }
                    else
                    {
                        float efectivo;

                        cout << "Efectivo recibido: ";
                        cin >> efectivo;

                        actualOrder->asignPayment(make_unique<CashPayment>(total,efectivo));
                    }

                    actualOrder->processPayment();

                    cout<< "Pago realizado\n";

                    break;
                }

                case 10:
                {
                    cout << "\n===Venta===\n";
                    int id;
                    int amount;

                    cout << "ID product: ";
                    cin >> id;

                    cout << "Amount: ";
                    cin >> amount;
                    Product* product =store.getInventory().searchProduct(id);

                    if(product)
                    {
                        product->sell(amount);

                        cout<< "Venta realizada\n";
                    }
                    break;
                }
                case 11:
                {
                    cout << "\n====Comparando productos====\n";
                    int id1;
                    int id2;

                    cout << "ID product 1: ";
                    cin >> id1;

                    cout << "ID product 2: ";
                    cin >> id2;

                    Product* p1 =store.getInventory().searchProduct(id1);

                    Product* p2 =store.getInventory().searchProduct(id2);

                    if(p1 && p2)
                    {
                        if(*p1 == *p2)
                        {
                            cout << "Son iguales\n";
                        }
                        else
                        {
                            cout << "Son diferentes\n";
                        }
                    }
                    break;
                }
                case 12:
                {
                    cout << "Process terminated...\n";
                    break;
                }

                default:
                {
                    cout << "Opcion invalida\n";
                }
            }
        }
        catch(const exception& e)
        {
            cout<< "Error: "<< e.what()<< endl;
        }

    } while(option != 8);

    

    return 0;
}