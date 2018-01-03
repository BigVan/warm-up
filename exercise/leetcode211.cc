#include "common.h"

class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary() {

		Node root;
		root.end = false;
		root.depth = -1;
		trie.push_back(root);
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {

		int depth = 0;
		int preKey = 0;
		for (auto ch : word) {
			auto key = ch - 'a';
			if (trie[preKey].subNodes.find(key) == trie[preKey].subNodes.end()) {
				Node node;
				//	node.ch = ch;
				node.end = false;
				node.depth = trie[preKey].depth + 1;
				trie[preKey].subNodes[key] = int(trie.size());
				trie.push_back(node);
				
			}
			preKey = trie[preKey].subNodes[key];
		}
		trie[preKey].end = true;
	
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {

		int depth = 0;
		int p = 0;
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			auto hIdx = q.front();
			auto head = trie[hIdx];
			q.pop();
			auto depth = head.depth+ 1;
			if (head.depth == word.length() - 1) {
				if (head.end) {
					return true;
				}				
			}
			if (depth > int(word.length()) - 1) {
				continue;
			}
			
			if (word[depth] != '.') {
				auto tag = word[depth] - 'a';
				if (head.subNodes.find(tag) == head.subNodes.end()) {
					continue;
				}
				auto next = head.subNodes[tag];
				q.push(next);

			}
			else {
				for (auto item : head.subNodes) {
					
					
				//	cout << depth << " push " << node.key << " " << graph[key].end << endl;
					q.push(item.second);
				}
			}
		}
		return false;
	}

private:
	int total{ 0 };
	struct Node {
		unordered_map<int, int> subNodes{};
		//char ch;
		int depth;
		bool end;
	};
	vector<Node> trie;
	
//	map<int, set<int>> tag;
	
};
//
//int main() {
//
//	WordDictionary obj;
//	obj.addWord("ran");
//	obj.addWord("rune");
//	obj.addWord("runner");
//	obj.addWord("runs");
//	obj.addWord("add");
//	obj.addWord("adds");
//	obj.addWord("adder");
//	obj.addWord("addee");
//	cout << obj.search("r.n") << endl;
//	cout << obj.search("ru.n.e") << endl;
//	cout << obj.search("add") << endl;
//	cout << obj.search("add.") << endl;
//	cout << obj.search("adde.") << endl;
//	cout << obj.search(".an.") << endl;
//	cout << obj.search("...s") << endl;
//	cout << obj.search("....e.") << endl;
//	cout << obj.search(".......") << endl;
//	cout << obj.search("..n.r") << endl;
//	cout << obj.search(".at") << endl;
//	obj.addWord("bat");
//	cout << obj.search(".at") << endl;
//	cout << obj.search("an.") << endl;
//	cout << obj.search("a.d.") << endl;
//	cout << obj.search("b.") << endl;
//	cout << obj.search("a.d") << endl;
//	cout << obj.search(".") << endl;
//	
//	system("pause");
//	return 0;
//}

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary obj = new WordDictionary();
* obj.addWord(word);
* bool param_2 = obj.search(word);
*/