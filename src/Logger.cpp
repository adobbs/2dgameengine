#include "Logger.h"
#include <iostream>

#define ESC "\033["
#define GREEN_TEXT "32m"
#define RED_TEXT "31m"
#define RESET "\033[m"

void Logger::Log(const std::string& message) {
    std::cout << ESC << GREEN_TEXT << "LOG: " << message << RESET << std::endl;
}

void Logger::Err(const std::string& message) {
    std::cout << ESC << RED_TEXT << "ERROR: " << message << RESET << std::endl;
}