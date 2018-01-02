#include "common.h"

class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary() {

		graph.clear();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {

		int depth = 0;
		int preKey = 0;
		for (auto ch : word) {
			auto key = GetKey(depth, preKey, ch);		
			//tag[depth].insert(key);
			if (graph.find(key) == graph.end()) {
				Node node;
			//	node.ch = ch;
				node.end = false;
				graph[key] = node;
			}
			graph[preKey].next.insert(key);
		
			preKey = key;
			depth++;
		}
		graph[preKey].end = true;
	
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {

		int depth = 0;
		int p = 0;
		queue<SearchNode> q;
		SearchNode node;
		node.depth = -1;
		node.key = 0;
		q.push(node);
		while (!q.empty()) {
			auto head = q.front();
			q.pop();
			auto depth = head.depth + 1;
			if (head.depth == word.length() - 1) {
				if (graph[head.key].end) {
					return true;
				}				
			}
			if (depth > int(word.length()) - 1) {
				continue;
			}
			auto key = GetKey(depth, head.key, word[depth]);
			
			if (word[depth] != '.') {
				if (graph[head.key].next.find(key) != graph[head.key].next.end()) {
					SearchNode node;
					node.key = key;
					node.depth = depth;
				//	cout <<depth << " push " << key << " " << graph[key].end<< endl;
					q.push(node);
				}
			}
			else {
				for (auto item : graph[head.key].next) {
					SearchNode node;
					node.key = item;
					node.depth = depth;
				//	cout << depth << " push " << node.key << " " << graph[key].end << endl;
					q.push(node);
				}
			}
		}
		return false;
	}

private:
	struct Node {
		unordered_set<int> next;		
		//char ch;
		bool end;
	};
	unordered_map<int, Node> graph;
//	map<int, set<int>> tag;
	struct SearchNode {
		int depth;
		int key;
	};
	int GetKey(int depth, int pre, char ch) {


		return (depth * 1000 + pre % 1000)*1000+ch;
	}
};

int main() {

	WordDictionary obj;
	obj.addWord("ran");
	obj.addWord("rune");
	obj.addWord("runner");
	obj.addWord("runs");
	obj.addWord("add");
	obj.addWord("adds");
	obj.addWord("adder");
	obj.addWord("addee");
	cout << obj.search("r.n") << endl;
	/*cout << obj.search("ru.n.e") << endl;
	cout << obj.search("add") << endl;
	cout << obj.search("add.") << endl;
	cout << obj.search("adde.") << endl;
	cout << obj.search(".an.") << endl;
	cout << obj.search("...s") << endl;
	cout << obj.search("....e.") << endl;
	cout << obj.search(".......") << endl;
	cout << obj.search("..n.r") << endl;*/
	/*cout << obj.search(".at") << endl;
	obj.addWord("bat");
	cout << obj.search(".at") << endl;
	cout << obj.search("an.") << endl;
	cout << obj.search("a.d.") << endl;
	cout << obj.search("b.") << endl;
	cout << obj.search("a.d") << endl;
	cout << obj.search(".") << endl;
	*/system("pause");
	return 0;
}

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary obj = new WordDictionary();
* obj.addWord(word);
* bool param_2 = obj.search(word);
*/