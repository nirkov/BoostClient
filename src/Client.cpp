//
// Created by nir on 10/01/18.
//

#include <stdlib.h>
#include "../include/connectionHandler.h"
using namespace std;

int main (int argc, char *argv[]) {

    //TODO : string host = argv[1];
    //TODO : short port = atoi(argv[2]);

    string host = "127.0.0.1";
    short port = 7777;

    ConnectionHandler connectionHandler(host, port);


}