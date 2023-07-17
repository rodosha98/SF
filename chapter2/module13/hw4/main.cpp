#include"SocialNetwork.hpp"
#include<iostream>

int main(char* ar[], int count)
{
    SocialNetwork sn;

    sn.addPerson("Oleg");
    sn.addPerson("Kostya");
    sn.addPerson("Misha");
    sn.addPerson("Vika");
    sn.addPerson("Lesha");

    sn.delPerson("Vika");
    sn.addPerson("Anya");

    sn.addFriend("Oleg", "Kostya");
    sn.addFriend("Kostya", "Misha");
    sn.addFriend("Misha", "Anya");
    sn.addFriend("Anya", "Lesha");

    sn.showThreeHandshakes();

    return 0;
}