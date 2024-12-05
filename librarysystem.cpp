// LibrarySystem.cpp

#include "LibrarySystem.h"
#include <sstream>
#include <iostream>

void LibrarySystem::pushReturnedBook(const std::string& book) {
    returnedBooks.push(book);
    std::cout << "Book \"" << book << "\" added to returned books.\n";
}

void LibrarySystem::popReturnedBook() {
    if (!returnedBooks.empty()) {
        std::cout << "Book \"" << returnedBooks.top() << "\" removed from returned books.\n";
        returnedBooks.pop();
    } else {
        std::cout << "No books in returned stack.\n";
    }
}

// Update peekReturnedBook to return a string
std::string LibrarySystem::peekReturnedBook() {
    if (!returnedBooks.empty()) {
        return returnedBooks.top();  // Return the top book as a string
    }
    return "";  // Return an empty string if the stack is empty
}

void LibrarySystem::enqueueReservation(const std::string& reservation) {
    reservations.push(reservation);
    std::cout << "Reservation \"" << reservation << "\" added to queue.\n";
}

void LibrarySystem::dequeueReservation() {
    if (!reservations.empty()) {
        std::cout << "Reservation \"" << reservations.front() << "\" processed and removed from queue.\n";
        reservations.pop();
    } else {
        std::cout << "No reservations in queue.\n";
    }
}

void LibrarySystem::peekReservation() {
    if (!reservations.empty()) {
        std::cout << "Next reservation in queue: " << reservations.front() << std::endl;
    } else {
        std::cout << "No reservations in queue.\n";
    }
}

std::string LibrarySystem::getNextReservation() {
    if (!reservations.empty()) {
        return reservations.front();
    }
    return "";
}

std::string LibrarySystem::getState() {
    std::stringstream state;
    state << "Returned Books:\n";
    std::stack<std::string> tempStack = returnedBooks;
    while (!tempStack.empty()) {
        state << "- " << tempStack.top() << "\n";
        tempStack.pop();
    }

    state << "\nReservations:\n";
    std::queue<std::string> tempQueue = reservations;
    while (!tempQueue.empty()) {
        state << "- " << tempQueue.front() << "\n";
        tempQueue.pop();
    }

    return state.str();
}
