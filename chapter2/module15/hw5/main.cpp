#include <iostream>
#include "chat.hpp"

int main(void)
{
    Chat chat;

    chat.reg((char*)"user1", (char*)"Qwerty", 6);
    chat.reg((char*)"user2", (char*)"12345", 5);

    std::cout << chat.login((char*)"user1", (char*)"Qwerty", 6) << std::endl;
    std::cout << chat.login((char*)"user1", (char*)"12345", 5) << std::endl;
    std::cout << chat.login((char*)"user2", (char*)"Qwerty", 6) << std::endl;
    std::cout << chat.login((char*)"user2", (char*)"12345", 5) << std::endl;
}