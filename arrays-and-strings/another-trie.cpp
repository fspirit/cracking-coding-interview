#include <memory>
#include <iostream>
#include <array>

const int EnAlphabetSize = 26;

struct TrieNode {
    bool endsWord;
    std::array<std::shared_ptr<TrieNode>, EnAlphabetSize> children;
};

class Trie {
    std::shared_ptr<TrieNode> head = nullptr;
public:
    /** Initialize your data structure here. */
    
    std::shared_ptr<TrieNode> put(std::shared_ptr<TrieNode> node, std::string& key, int depth) {
        auto n = node;
        if (n == nullptr) {
            std::cout << "New node!" << std::endl; 
            n = std::make_shared<TrieNode>(); 
            n->endsWord = false;
        }

        if (depth == key.size()) {
            std::cout << "Setting endsWord to true" << std::endl; 
            n->endsWord = true;
            return n;
        } 
            
        auto index = int(key[depth]) - int('a');
        std::cout << "index = " << index << std::endl; 
        n->children[index] = put(n->children[index], key, depth + 1);        
        return n;        
    }
    
    std::shared_ptr<TrieNode> get(std::shared_ptr<TrieNode> node, std::string& key, int depth) {
        if (node == nullptr) return node;
        std::cout << "Current node = " << node->endsWord << std::endl; 
        if (depth == key.size()) return node;
        std::cout << "Next  = " << key[depth] << std::endl; 
        auto index = int(key[depth]) - int('a');
        return get(node->children[index], key, depth + 1);
    }
    
    /** Inserts a word into the trie. */
    void insert(std::string word) {
        if (word.size() == 0) return;
        head = put(head, word, 0);
    }
    
    /** Returns if the word is in the trie. */
    bool search(std::string word) {
        auto node = get(head, word, 0);
        return node != nullptr && node->endsWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix) {
        auto node = get(head, prefix, 0);
        return node != nullptr;
    }

};

int main(int argc, char const *argv[])
{
    Trie tr;

    tr.insert("app");
    tr.insert("apple");

    std::cout << tr.search("app") << std::endl;
    return 0;
}