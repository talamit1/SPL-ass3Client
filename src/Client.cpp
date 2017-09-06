

#include "../include/connectionHandler.h"


/**
* This code assumes that the server replies the exact text the client sent it (as opposed to the practical session example)
*/
int main (int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " host port" << std::endl << std::endl;
        return -1;
    }
    std::string host = argv[1];
    short port = atoi(argv[2]);
    
    ConnectionHandler connectionHandler(host, port);
    if (!connectionHandler.connect()) {
        std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
        return 1;
    }
    std::cout<< "Successfully connected to "<<host<<std::endl;
	

    boost::thread th1(&ConnectionHandler::UserInHandlerlerrun, &connectionHandler);
    boost::thread th2(&ConnectionHandler::SocketHandlerrun, &connectionHandler);
    th1.join();
    th2.join();

    return 1;
}

