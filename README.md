# Tienda-cpp
# Object-Oriented Programming 2026

# E-Commerce Management System

## Problem Proposal

A small business selling electronics wants to replace its manual sales process with an object-oriented software system.

Currently, employees record products, customers, and sales in spreadsheets, leading to inventory control errors, data loss, and difficulties managing different payment methods.

The business needs an application that allows it to:

* Register products available in inventory.
* Create and process orders.
* Process payments using different payment methods.
* Automatically update inventory after each sale.
* Prevent products from being sold when stock is unavailable.
* Handle inventory-related errors safely.
* Provide a maintainable and extensible architecture.

### Why OOP?

The problem involves multiple entities with different responsibilities that interact with one another. Object-Oriented Programming provides:

* Encapsulation of business rules.
* Reusable and extensible class hierarchies.
* Safe ownership management.
* Runtime polymorphism for payment processing.
* Clear modeling of real-world relationships.

---

# Class List and OOP Concepts

| Class       | Purpose                     | Concepts Demonstrated               |
| ----------- | --------------------------- | ----------------------------------- |
| Product     | Represents a store product  | Encapsulation, Operator Overloading |
| Electronic  | Specialized product         | Inheritance                         |
| Accessory   | Specialized product         | Inheritance                         |
| Customer    | Represents a customer       | Encapsulation                       |
| Inventory   | Stores and manages products | Composition, Smart Pointers         |
| Order       | Represents a customer order | Aggregation, Composition            |
| Payment     | Abstract payment interface  | Abstraction, Polymorphism           |
| CardPayment | Card payment implementation | Inheritance, Polymorphism           |
| CashPayment | Cash payment implementation | Inheritance, Polymorphism           |
| Store       | Main system controller      | Composition Relationships           |

---

# Build Instructions

Compile using:
```bash
g++ -std=c++14 -Wall main.cpp -o programa
```
Run:
```bash
./programa
```
---

# Expected Functionality

The application allows users to:

1. Add products to inventory.
2. Display inventory.
3. Search products.
4. Register customers.
5. Create orders.
6. Add products to orders.
7. Calculate order totals.
8. Process payments.
9. Validate stock availability.
10. Handle exceptions when stock is insufficient.

---

# Sample Output

```text
===== STORE MENU =====

1. Add Product to Inventory
2. Show Inventory
3. Search product
4. Insert new Costumer
5. Create Order
6. Add Product to Order
7. Calculate order total
8. Show order
9. Pay order
10. Sell product
11. Compare products
12. Exit

```
---

# OOP Requirements Mapping

## 1. Class Relationships by Ownership/Lifetime
### Composition
Inventory owns Product objects through:

```cpp
std::vector<std::unique_ptr<Product>>
```
When Inventory is destroyed, all owned Product objects are automatically destroyed.
---
Order owns Payment through:
```cpp
std::unique_ptr<Payment>
```
When Order is destroyed, its Payment is also destroyed.

### Aggregation
Order stores references to Product objects:
```cpp
std::vector<Product*>
```
Products continue existing in Inventory even if the Order is destroyed.

## 2. Encapsulation and Abstraction

All attributes are private or protected.
Example:
```cpp
private:
    int stock;
```
The stock value can only be modified through public methods.

Products cannot be sold if stock becomes negative.

The Payment class is abstract and exposes only the behavior required by derived payment types.

---

## 3. Inheritance

Hierarchy:

```text
Product
├── Electronic
└── Accessory

Payment
├── CardPayment
└── CashPayment
```

Derived classes call base constructors using constructor forwarding:

```cpp
Electronic(...)
: Product(...){}
```
---

## 4. Runtime Polymorphism

Payment is an abstract base class:
```cpp
virtual void processPayment() = 0;
```
Derived classes override:

```cpp
void processPayment() override;
```
Orders store payment objects through:

```cpp
std::unique_ptr<Payment>
```
---

## 5. Virtual Destructor

Polymorphic base:

```cpp
virtual ~Payment() = default;
```

Objects are stored through pointers:

```cpp
std::unique_ptr<Payment>
```
This prevents object slicing.

---

## 6. Operator Overloading

Product overloads:
### Equality Operator

```cpp
bool operator==(const Product&) const;
```

Used for product comparison.

---

## 7. Rule of Zero

This project intentionally follows the Rule of Zero.

No manual implementation of:

* Destructor
* Copy Constructor
* Move Constructor
* Copy Assignment
* Move Assignment

Memory management is delegated to:

* std::unique_ptr
* std::vector
* std::string

These RAII types automatically manage resources safely.

---

## 8. Smart Pointers
Ownership is represented using:

```cpp
std::unique_ptr<Product>
```
and
```cpp
std::unique_ptr<Payment>
```
The project avoids raw ownership through:

```cpp
new
delete
```
All heap-owned objects are managed automatically.

---

## 9. STL Containers and Strings

The project uses:

```cpp
std::vector
```

for collections.

```cpp
std::string
```

for text.

No raw arrays or C-style strings are used.

---

## 10. Exception Handling and RAII
Custom exception:
```cpp
class StockInsufficientException
    : public std::exception
```
Thrown when:

```cpp
amount > stock
```

Caught at:
```cpp
catch(const std::exception& e)
```

RAII guarantees all resources are released correctly even if an exception occurs.

---

# Ownership Design 

The design follows ownership:

* Inventory owns Product objects.
* Order references Product objects but does not own them.
* Order owns Payment objects.


