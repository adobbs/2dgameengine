#include "Logger.h"
#include <iostream>
#include <iomanip>
#include <ctime>

#define ESC "\033["
#define GREEN_TEXT "32m"
#define RED_TEXT "31m"
#define RESET "\033[m"

auto t = std::time(nullptr);
auto tm = *std::localtime(&t);

void Logger::Log(const std::string& message) {
    std::cout << ESC << GREEN_TEXT << "LOG | " << std::put_time(&tm, "%d-%b-%Y %H:%M:%S") << " - " << message << RESET << std::endl;
}

void Logger::Err(const std::string& message) {
    std::cout << ESC << RED_TEXT << "ERR | " << std::put_time(&tm, "%d-%b-%Y %H:%M:%S") << " - " << message << RESET << std::endl;
}