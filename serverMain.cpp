#include <iostream>
#include "Server/Server.h"
using namespace std;

int main() {
    Server server("server.txt");
    int selective_repeat = 0;
    int stopAndWait = 1;
    int GBN = 2;
    server.start_server(stopAndWait);
    return 0;
}