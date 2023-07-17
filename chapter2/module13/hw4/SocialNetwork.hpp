#pragma once 
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

#define NAMELENGTH 30
#define SIZE 10

class SocialNetwork
{
public:
    struct Human{
        Human();
        Human(const std::string& name, int id);
        Human& operator=(const Human& other);
        Human(const Human& other);

        bool operator==(const Human& other);

        std::string name_;

        friend class SocialNetwork;
    
    private:
        int id_;
    };

    SocialNetwork();
    void addPerson(const std::string& name);
    void delPerson(const std::string& name);
    void addFriend(const std::string& name1, const std::string& name2);
    void showThreeHandshakes();
    

private:
    SocialNetwork::Human findPersonByName(const std::string& name);
    bool areFriends(const Human& p1, const Human& p2);
    bool isPersonExists(int id);

    int friend_matrix[SIZE][SIZE];
    std::vector<Human> people;
    int busyids[SIZE];
};