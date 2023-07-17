#include "SocialNetwork.hpp"
#include <iostream>
SocialNetwork::Human::Human(): id_(-1) {
}

SocialNetwork::Human::Human(const std::string& name, int id) : name_(name), id_(id) {
}

SocialNetwork::Human& SocialNetwork::Human::operator=(const Human& other) {
    this->id_ = other.id_;
    this->name_ = other.name_;
    return *this;
}

SocialNetwork::Human::Human(const Human& other)
{
    this->id_ = other.id_;
    this->name_ = other.name_;
}

bool SocialNetwork::Human::operator==(const Human& other) {
    return other.id_ == this->id_;
}

SocialNetwork::SocialNetwork()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            friend_matrix[i][j] = 0;

    for (int i = 0; i < SIZE; i++) {
        busyids[i] = 0;
    }
}

SocialNetwork::Human SocialNetwork::findPersonByName(const std::string& name)
{
    for(auto& person : people )
    {
        if (!person.name_.compare(name))
        {
            return person;
        }
    }
    return Human();
}

void SocialNetwork::addPerson(const std::string& name)
{
    Human person = findPersonByName(name);
    if(person.id_ >= 0)
    {
        return;
    }
    int i = 0;
    for (; i < SIZE; i++)
        if(!busyids[i])
            break;
    busyids[i] = true;
    people.push_back(Human(name, i));
}

void SocialNetwork::delPerson(const std::string& name)
{
    Human person = findPersonByName(name);
    if (person.id_ < 0)
        return;

    busyids[person.id_] = false;
    

    for (int i = 0; i < people.size(); i++) {
        friend_matrix[i][person.id_] = 0;
        friend_matrix[person.id_][i] = 0;
    }

    //delete person from people 
    people.erase(std::remove(people.begin(), people.end(), person), people.end());

}

void SocialNetwork::addFriend(const std::string& name1, const std::string& name2)
{
    auto p1 = findPersonByName(name1);
    auto p2 = findPersonByName(name2);

    if (p1.id_ < 0 || p2.id_ < 0)
    {
        return;
    }

    friend_matrix[p1.id_][p2.id_] = 1;
    friend_matrix[p2.id_][p1.id_] = 1;
}

bool SocialNetwork::areFriends(const Human& p1, const Human& p2)
{
    return friend_matrix[p1.id_][p2.id_];
}

bool SocialNetwork::isPersonExists(int id)
{
    for (auto& p : people)
    {
        if (p.id_ == id)
        {
            return true;
        }
    }
    return false;
}

void SocialNetwork::showThreeHandshakes()
{
    int waves[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        waves[i] = -1;
    }
    waves[0] = 0;
    std::queue<int> queue;
    queue.push(0);

    while(queue.size())
    {
        int currentMaxIndex = queue.front();
        queue.pop();
        for (int i = 0; i < people.size(); i++)
        {
            if (areFriends(people[currentMaxIndex], people[i]) && waves[i] == -1)
            {
                waves[i] = waves[currentMaxIndex] + 1;
                queue.push(i);
            }
        }
    }

    for (int i = 0; i < people.size(); i++) {
        for (int j = i + 1; j < people.size(); j++) {
            if (abs(waves[i] - waves[j]) <= 3) {
                std::cout << people[i].name_ << " " << people[j].name_ << std::endl;
            }
        }
    }

}