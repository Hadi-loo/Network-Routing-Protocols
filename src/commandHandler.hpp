#ifndef __COMMANDHANDLER_HPP__
#define __COMMANDHANDLER_HPP__

#include "consts.hpp"
#include "network.hpp"
#include <string>

using namespace std;

class CommandHandler {
private:
    Network* network;

public:
    CommandHandler(Network* network);
    ~CommandHandler();
    void start();  
    void handleTopology(string args);
    void handleShow();
    void handleModify(string args);
    void handleRemove(string args);
    void handleLsrp(int src);
    void handleDvrp(int src);

};


#endif // __COMMANDHANDLER_HPP__