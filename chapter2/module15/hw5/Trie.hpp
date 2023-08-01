#pragma once 

#include <string>
#include <vector>


#define ALPHABET_SIZE 26

struct TrieNode 
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

TrieNode *getNewNode(void);
bool search(struct TrieNode *root, std::string key);
bool isEmpty(TrieNode* root);
TrieNode* remove(TrieNode* root, std::string key, int depth = 0);

TrieNode* createTreeFromFile(std::string& path);
std::vector<std::string>  autocomplete(TrieNode* root, std::string& str);
void go_deep(TrieNode* node, std::string& str, std::vector<std::string>& v);