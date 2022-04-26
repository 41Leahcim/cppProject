#include <string>

#include "Client.hpp"


uint32_t generateID(){
    srand(time(0) * (clock() + 1));
    return rand();
}

void communicateWithServer(Client& client, std::string& message){
    client.startConnection();
    client.sendString(message.c_str());
    client.receiveString();

    puts(client.getBuffer());
    client.endConnection();
}

int main(int argc, char const* argv[]){
    uint8_t messageStart;
    std::string message, line, id;
    Client client(9001);
    uint64_t test = 0;

    id = std::to_string(generateID()) + ": ";

    while(1){
//        printf("Enter the message: ");
//        std::getline(std::cin, line);
        line = std::to_string(test++);
        message = id + line;

        communicateWithServer(client, message);
    }
	return 0;
}
