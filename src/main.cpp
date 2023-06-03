#include "commandHandler.hpp"

int main() {
    Network network = Network();
    CommandHandler commandHandler = CommandHandler(&network);
    commandHandler.start();
    return 0;
}