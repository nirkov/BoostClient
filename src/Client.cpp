//
// Created by nir on 10/01/18.
//


#include "../include/connectionHandler.h"
#include <boost/thread.hpp>
using namespace std;


class GetFromKeyboard {
private:
    ConnectionHandler* CONNECTION_HANDLER = nullptr;

public:
    GetFromKeyboard(ConnectionHandler* newConHan) : CONNECTION_HANDLER(newConHan){}

    void operator()(){
        while (1) {
            const short bufsize = 1024;
            char buf[bufsize];
            std::cin.getline(buf, bufsize);
            std::string line(buf);
            int len = line.length();
            if (!(*CONNECTION_HANDLER).sendLine(line)) {
                std::cout << "Disconnected. Exiting...\n" << std::endl;
                break;
            }
        }
    };
};


class GetFromServer {
private:
    ConnectionHandler* CONNECTION_HANDLER_SERVER = nullptr;

public:
    GetFromServer(ConnectionHandler* newConHan) : CONNECTION_HANDLER_SERVER(newConHan){}

    void operator()(){
        while (1) {
            std::string answer;
            if (!CONNECTION_HANDLER_SERVER->getLine(answer)) {
                std::cout << "Disconnected. Exiting...\n" << std::endl;
                break;
            }
        }
    };
};

int main (int argc, char *argv[]) {

    //TODO : string host = argv[1];
    //TODO : short port = atoi(argv[2]);

    string host = "127.0.0.1";
    short port = 7777;

    ConnectionHandler connectionHandler(host, port);
    if (!connectionHandler.connect()) {
        std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
        return 1;
    }

    GetFromKeyboard fromKeyboard(&connectionHandler);
    GetFromServer fromServer(&connectionHandler);


    boost::thread getFromKeyBoard_Theard(fromKeyboard);
    boost::thread getFromServer_Theard(fromServer);

    getFromKeyBoard_Theard.join();
    getFromServer_Theard.join();

}

