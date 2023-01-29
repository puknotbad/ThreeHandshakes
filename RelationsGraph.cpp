#include "RelationsGraph.h"

//#include "RelationsGraph.h"
#include <memory>
#include <iostream>

RelationsGraph::Person::Person() : id(-1) {
}
RelationsGraph::Person::Person(const Name _name, int _id) : id(_id) {
    strcpy_s(name, _name);
}
RelationsGraph::Person&RelationsGraph::Person::operator=(const Person& other) {
    strcpy_s(name, other.name);
    id = other.id;
    return *this;
}
RelationsGraph::Person::Person(const Person& other)
{
    strcpy_s(name, other.name);
    id = other.id;
}
bool RelationsGraph::Person::operator==(const Person& other) {
    return other.id == this->id;
}
RelationsGraph::RelationsGraph() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            friend_matrix[i][j] = 0;
    for (int i = 0; i < SIZE; i++) {
        busyids.add(false);
    }
}
void RelationsGraph::addnewMan(const Name name) {
    Person man = findManByName(name);
    if (man.id >= 0)
        return;
    int i = 0;
    for (; i < SIZE; i++)
        if (!busyids[i])
            break;
    busyids[i] = true;
    people.add(Person(name, i));
}

void RelationsGraph::delMan(const Name name) {
    Person man = findManByName(name);
    if (man.id < 0)
        return;
    busyids[man.id] = false;
    int index = people.find(man);
    for (int i = 0; i < people.size(); i++) {
        friend_matrix[i][man.id] = 0;
        friend_matrix[man.id][i] = 0;
    }
    people.del(index);
}

void RelationsGraph::addFriendship(const Name name_1, const Name name_2) {
    Person m1 = findManByName(name_1);
    Person m2 = findManByName(name_2);
    if (m1.id < 0 || m2.id < 0)
        return;
    friend_matrix[m1.id][m2.id] = 1;
    friend_matrix[m2.id][m1.id] = 1;
}

void RelationsGraph::showThreeHandshakes() {
    int wavesLevels[SIZE];
    for (int i = 0; i < SIZE; i++) {
        wavesLevels[i] = -1;
    }
    wavesLevels[0] = 0;

    StaticArray<int> queue;
    queue.add(0);

    while (queue.size()) {
        int currentManIndex = queue[0];
        queue.del(0);
        for (int i = 0; i < people.size(); i++)
            if (are_friends(people[currentManIndex], people[i]) &&
                wavesLevels[i] == -1)
            {
                wavesLevels[i] = wavesLevels[currentManIndex] + 1;
                queue.add(i);
            }
    }

    for (int i = 0; i < people.size(); i++) {
        for (int j = i + 1; j < people.size(); j++) {
            if (abs(wavesLevels[i] - wavesLevels[j]) <= 3) {
                std::cout << people[i].name << " " << people[j].name << std::endl;
            }
        }
    }
}


bool RelationsGraph::are_friends(const Person& m1, const Person& m2) {
    return friend_matrix[m1.id][m2.id] == 1;
}

bool RelationsGraph::man_exists_with_id(int man_id) {
    for (int i = 0; i < people.size(); i++)
        if (people[i].id == man_id)
            return true;
    return false;
}


RelationsGraph::Person RelationsGraph::findManByName(const Name name) {
    for (int i = 0; i < people.size(); i++)
        if (!strcmp(name, people[i].name))
            return people[i];
    return Person();
}