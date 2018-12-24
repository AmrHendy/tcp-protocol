#include <iostream>
#include "Client/Client.h"
using namespace std;

int main() {
    Client client("client.txt");
    int stopAndWait = 0;
    int selective_repeat = 1;
    int GBN = 2;
    client.connect_to_server();
    client.receive_file(selective_repeat);

    return 0;
}