#include <iostream>
#include "Types.h"
int main() {
    Database* db = Database::getInstance();
    std::cout<<"DB returned: "<<db->query("Hello world")<<"\n";
    delete db;
    return 0;
}
