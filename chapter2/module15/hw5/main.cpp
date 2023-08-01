#include "Trie.hpp"
#include <iostream>

int main(void)
{
    std::string file_path = "vocabulary/words_alpha.txt";
    TrieNode* trie = createTreeFromFile(file_path);

    std::vector<std::string> lines;

    while(true)
    {
        std::cout << std::endl;
        std::cout << "Enter line" << std::endl;
        std::string str; 
        std::cin >> str; 

        std::cout << "Prefix: " << str << std::endl;

        if (str.front() == '1')
        {
            std::cout << "Exit" << std::endl;
            break;
        }
        else
        {
            lines = autocomplete(trie, str);
            if (lines.empty())
            {
                std::cout << "No words for autocomplete!" << std::endl;
            }
            else
            {
                for ( auto& l : lines)
                {
                    std::cout << l << std::endl;
                }
            }
        }

    }
    return 0;
}