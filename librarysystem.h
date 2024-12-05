// LibrarySystem.h

#include <stack>
#include <queue>
#include <string>

class LibrarySystem {
private:
    std::stack<std::string> returnedBooks;
    std::queue<std::string> reservations;

public:
    void pushReturnedBook(const std::string& book);
    void popReturnedBook();

    // Change the return type of peekReturnedBook to std::string
    std::string peekReturnedBook();  // Return type is now std::string

    void enqueueReservation(const std::string& reservation);
    void dequeueReservation();
    void peekReservation();

    std::string getNextReservation();
    std::string getState();
};
