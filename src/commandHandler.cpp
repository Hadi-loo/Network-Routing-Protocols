#include "commandHandler.hpp"
#include <iostream>
#include <sstream>

CommandHandler::CommandHandler(Network* network) {
    this->network = network;
}

CommandHandler::~CommandHandler() {

}

void CommandHandler::start() {

    cout << CYAN << "Welcome to the Network Simulator" << RESET << endl;

    while (true) {
        string line;
        cout << CYAN << ">> " << RESET;
        getline(cin, line);
        stringstream ss(line);
        string command;
        ss >> command;

        // cout << YELLOW << "Line: |" << line << "|" << RESET << endl;  
        // cout << YELLOW << "SS: |" << ss.str() << "|" << RESET << endl;
        // cout << YELLOW << "Command: |" << command << "|" << RESET << endl;
        // cout << YELLOW << "Args: |" << args << "|" << RESET << endl;

        if (command == "topology") {
            string args;
            args = line.substr(command.length() + 1, line.length() - command.length() - 1);
            handleTopology(args);
        } 
        else if (command == "show") {
            handleShow();
        }
        else if (command == "modify") {
            string args;
            args = line.substr(command.length() + 1, line.length() - command.length() - 1);
            handleModify(args);
        }
        else if (command == "remove") {
            string args;
            args = line.substr(command.length() + 1, line.length() - command.length() - 1);
            handleRemove(args);
        }
        else if (command == "lsrp") {
            int src;
            ss >> src;
            handleLsrp(src);
        }
        else if (command == "dvrp") {
            string args;
            args = line.substr(command.length());
            if (args == "") {
                handleDvrp(-1);
            }
            else {
                int src;
                ss >> src;
                handleDvrp(src);
            }
        }
        else {
            cout << RED << "Invalid Command" << RESET << endl;
        }
    }

}

void CommandHandler::handleTopology(string args) {
    stringstream ss(args);
    string segment;
    string temp;
    int si, di, ci;
    // cout << MAGENTA << "Args: |" << args << "|" << RESET << endl;
    while (getline(ss, segment, ' ')) {
        // cout << MAGENTA << "Segment: |" << segment << "|" << RESET << endl;
        stringstream sss(segment);
        getline(sss, temp, '-');
        si = stoi(temp);
        getline(sss, temp, '-');
        di = stoi(temp);
        getline(sss, temp, '-');
        ci = stoi(temp);
        // cout << MAGENTA << "si: |" << si << "|" << " di: |" << di << "|" << " ci: |" << ci << "|" << RESET << endl;
        network->addEdge(si, di, ci);
    }
}

void CommandHandler::handleShow() {
    network->showAdjacencyMatrix();
}

void CommandHandler::handleModify(string args) {
    stringstream ss(args);
    string temp;
    int s, d, c;
    getline(ss, temp, '-');
    s = stoi(temp);
    getline(ss, temp, '-');
    d = stoi(temp);
    getline(ss, temp, '-');
    c = stoi(temp);
    network->modifyEdge(s, d, c);
}

void CommandHandler::handleRemove(string args) {
    stringstream ss(args);
    string temp;
    int s, d;
    getline(ss, temp, '-');
    s = stoi(temp);
    getline(ss, temp, '-');
    d = stoi(temp);
    network->removeEdge(s, d);
}

void CommandHandler::handleLsrp(int src) {
    network->lsrp(src);
}

void CommandHandler::handleDvrp(int src) {
    network->dvrp(src);
}



