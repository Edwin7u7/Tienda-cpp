#ifndef STOCKINSUFICIENTEEXCEPTION_H
#define STOCKINSUFICIENTEEXCEPTION_H
#include <stdexcept>
#include <string>

class StockInsuficienteException : public std::runtime_error {
public:
    explicit StockInsuficienteException(const std::string& msg)
        : std::runtime_error(msg) {}
};
#endif