#include <iostream>
#include <exception>
using namespace std;

// Base class with concrete what()
class DatabaseException : public exception {
public:
    const char* what() const noexcept override {
        return "A database error occurred.";
    }
};

// Derived exception classes without custom what()
class ConnectionFailedException : public DatabaseException { };
class QueryTimeoutException : public DatabaseException { };

// Template class simulating database connection
template <typename T>
class DatabaseConnector {
public:
    void connect(T dbName) {
        if (dbName == "invalid_db") {
            throw ConnectionFailedException();
        } else if (dbName == "slow_db") {
            throw QueryTimeoutException();
        } else {
            cout << "Connected to " << dbName << " successfully." << endl;
        }
    }
};

int main() {
    DatabaseConnector<string> db;

    try {
        cout << "Attempting to connect to invalid_db..." << endl;
        db.connect("invalid_db"); // throws ConnectionFailedException
    } catch (const ConnectionFailedException& e) {
        cout << "Caught ConnectionFailedException - what(): " << e.what() << endl;
    }

    try {
        cout << "\nAttempting to connect to slow_db..." << endl;
        db.connect("slow_db"); // throws QueryTimeoutException
    } catch (const DatabaseException& e) {
        cout << "Caught a general DatabaseException - what(): " << e.what() << endl;
    }

    return 0;
}
