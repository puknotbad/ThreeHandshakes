// 13.9_HW_socialRelations.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// Skillfactory 13.9_homeWork "Three handshakes friendship". Graph-based C++ code to find friends in the society. 
// ** The shitty "author" code 

#include <iostream>
#include "RelationsGraph.h"

int main(char* ar[], int count)
{
   RelationsGraph sn;

    sn.addnewMan("Oleg");
    sn.addnewMan("Kostya");
    sn.addnewMan("Misha");
    sn.addnewMan("Vika");
    sn.addnewMan("Lesha");

    sn.delMan("Vika");
    sn.addnewMan("Anya");

    sn.addFriendship("Oleg", "Kostya");
    sn.addFriendship("Kostya", "Misha");
    sn.addFriendship("Misha", "Anya");
    sn.addFriendship("Anya", "Lesha");

    sn.showThreeHandshakes();

    return 0;
}