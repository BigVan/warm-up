#include "common.h"

class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {

		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {

		TrieNode *p = root, *last = nullptr;
		for (auto ch : word) {
			int idx = ch - 'a';
			if (p->subNode[idx] == nullptr) {
				TrieNode *q = new TrieNode();
				p->subNode[idx] = q;				
			}
			p = p->subNode[idx];
			last = p;
		}
		last->endTag = true;

	}

	/** Returns if the word is in the trie. */
	bool search(string word) {

		TrieNode *p = root, *last = nullptr;
		for (auto ch : word) {
			int idx = ch - 'a';
			if (p->subNode[idx] == nullptr) {
				return false;
			}			
			p = p->subNode[idx];
			last = p;
		}
		return last->endTag;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {

		TrieNode *p = root, *last = nullptr;
		for (auto ch : prefix) {
			int idx = ch - 'a';
			if (p->subNode[idx] == nullptr) {
				return false;
			}
			p = p->subNode[idx];
		}
		return true;
	}

private:
	struct TrieNode {
		bool endTag;
		TrieNode *subNode[26]{};
	} *root;
};

int main() {

	Trie obj;
	obj.insert("abc");
	obj.search
}