#include <iostream>
#include <sqlite3.h>

int main() {
    std::cout << "Hello, Graph Microservice!" << std::endl;

    // SQLite example
    sqlite3* db;
    int rc = sqlite3_open(":memory:", &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    } else {
        std::cout << "Opened database successfully!" << std::endl;
    }
    sqlite3_close(db);

    return 0;
}
