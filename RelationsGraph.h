#pragma once
//#include "Person.h"

#include "staticarray.h"

#define NAMELENGTH 30

typedef char Name[NAMELENGTH];

//classRelationsGraph { // социальна€ сеть};

class RelationsGraph
{
public:
    struct Person { // класс человека
        Person();
        Person(const Name _name, int _id);
        Person& operator=(const Person& other);
        Person(const Person& other);

        bool operator==(const Person& other);

        Name name; // им€

        friend class RelationsGraph;
        private:
            int id; // внутренний id
   };
   RelationsGraph();
    // добавление нового человека в сеть
    void addnewMan(const Name name);
    // удаление человека из сети
    void delMan(const Name name);
    // установка дружбы между двум€ людьми
    void addFriendship(const Name name_1, const Name name_2);
    // алгоритм поиска пар
    void showThreeHandshakes();

private: // функции
    // €вл€ютс€ друзь€ми?
    bool are_friends(const Person& m1, const Person& m2);
    // есть ли человек с man_id
    bool man_exists_with_id(int man_id);
    // поиск по имени
    Person findManByName(const Name name);
private: // пол€
    int friend_matrix[SIZE][SIZE]; // матрица дружбы
    StaticArray<Person> people; // список людей внутри сети
    StaticArray<bool> busyids; // зан€тые id
};


