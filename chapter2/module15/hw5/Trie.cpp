#include "Trie.hpp"

#include <fstream>
#include <iostream>

TrieNode *getNewNode(void)
{
   // Выделяем память под новый узел
   struct TrieNode *pNode =  new TrieNode;

   // устанавливаем флаг конца слова в false
   pNode->isEndOfWord = false;

   // инициализируем детей нулевым указателем
   for (int i = 0; i < ALPHABET_SIZE; i++)
       pNode->children[i] = nullptr;

   return pNode;
}

void insert(TrieNode* root, std::string key) 
{
    TrieNode *current =  root;
    for (int i = 0; i < key.size(); i++)
    {     
        char c = key[i];
        int index = c - 'a';
        if ( current->children[index] != nullptr)
        {
            current = current->children[index];
        }
        else 
        {
            TrieNode *pNode =  getNewNode();
            current->children[index] = pNode;
            current = current->children[index];
        }
        if ( i == key.size() - 1)
        {
            current->isEndOfWord = true;
        }
    }
}

// Возвращает true если ключ есть в дереве, иначе false
bool search(struct TrieNode *root, std::string key)
{
   TrieNode *node = root;
   for (int i = 0; i < key.length(); i++)
   {
       int index = key[i] - 'a';
       if (!node->children[index])
           return false;

       node = node->children[index];
   }

   return (node != nullptr && node->isEndOfWord);
}

bool isEmpty(TrieNode* root)
{
   for (int i = 0; i < ALPHABET_SIZE; i++)
       if (root->children[i])
           return false;
   return true;
}

// Рекурсивная функция удаления ключа из дерева
TrieNode* remove(TrieNode* root, std::string key, int depth)
{
   if (!root)
       return nullptr;
   if (depth == key.size()) {
    
       if (root->isEndOfWord)
           root->isEndOfWord = false;
       if (isEmpty(root)) {
           delete (root);
           root = nullptr;
       }

       return root;
   }
   int index = key[depth] - 'a';
   root->children[index] = remove(root->children[index], key, depth + 1);

   if (isEmpty(root) && root->isEndOfWord == false) {
       delete (root);
       root = nullptr;
   }
   return root;
}

TrieNode* createTreeFromFile(std::string& path)
{
    TrieNode *root =  getNewNode();
    std::ifstream input( path );
    for( std::string line; getline( input, line ); )
    {
        line.pop_back(); //delete \n
        insert(root, line);
    }

    return root;
    
}

void go_deep(TrieNode* node, std::string& str, std::vector<std::string>& v)
{
    if (node->isEndOfWord == true)
    {
        v.push_back(str);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if(node->children[i])
        {
            std::string str2 = str;
            str2.push_back(i + 'a');
            go_deep(node->children[i], str2, v);
        }
    }

    return;

    
}
std::vector<std::string> autocomplete(TrieNode* root, std::string& prefix)
{
    TrieNode *node = root;
    std::vector<std::string> v;
    for (int i = 0; i < prefix.size(); i++)
    {
        int index = prefix[i] - 'a';
        if (!node->children[index])
        {
            return v;
        }

        node = node->children[index];
    }

    go_deep(node, prefix, v);
    return v;
}