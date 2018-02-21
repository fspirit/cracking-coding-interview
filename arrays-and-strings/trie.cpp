#include <memory>
#include <array>

const int NUMBER_OF_CHARS = 26;

struct TrieNode {
	int Value;
	std::array<std::shared_ptr<TrieNode>, NUMBER_OF_CHARS> Next;
};


class Trie {
public:
	Trie() : head(new TrieNode()) {};
	void Insert(const std::string& key, int value) {
		head = Put(head, key, value, 0);
	};

	void Get(const std::string& key) {

	};

	int Size(){
		return 0;
	};
private:
	int Get(std::shared_ptr<TrieNode> node, const std::string& key, int d) {
		if (!node)
			return 0;
		if (d == key.size())
			return node->Value;
		auto c = key[d];
		return Get(node->Next[c], key, d + 1);
	};

	std::shared_ptr<TrieNode> Put(std::shared_ptr<TrieNode> node, const std::string& key, int value, int d) {		
		auto n = node;
		if (!n) {
			n = std::make_shared<TrieNode>();
		}
		if (d == key.size()) {
			n->Value = value;			
		} else {
			auto c = key[d];
			n->Next[c] = Put(n->Next[c], key, value, d + 1);
		}
		return n;
	};
	std::shared_ptr<TrieNode> head;
};

int main(int argc, char const *argv[])
{	
	Trie tr;
	return 0;
}