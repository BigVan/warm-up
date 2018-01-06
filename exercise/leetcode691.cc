#include "common.h"

class Solution {
public:
	int minStickers(vector<string>& stickers, string target) {

		int m = target.size();
		int n = stickers.size();
	//	vector<vector<int> > f(m, vector<int>(26,0));
		vector<vector<int>> count(n, vector<int>(26, 0));
		for (auto i = 0; i < n; i++) {
			for (auto c : stickers[i])
				count[i][c - 'a']++;
		}
		queue<Node> q;
		Node init(0);
		for (auto c : target) {
			init.count[c - 'a']++;
		}
		for (int i = 0; i < m; i++) {
			if (init.count[target[i]-'a'] == 0) init.state |= 1 << i;
		}
		q.push(init);
	//	hash[init.state] = true;
		while (!q.empty()) {
			auto head = q.front();
	//		cout << head.state << endl;
			if (head.state == (1 << m) - 1) return head.step;
			q.pop();
			for (int i = 0; i < n; i++) {
				int state = head.state;
				int tmp[26]{};
				memcpy(tmp, head.count, sizeof(head.count));
				bool change = false;
				for (int j = 0; j < m; j++) {
					if (count[i][target[j]-'a'] && tmp[target[j]-'a']){
						tmp[target[j] - 'a'] = head.count[target[j]-'a'] - count[i][target[j] - 'a'];
						if (tmp[target[j] - 'a'] <= 0)
							state |= 1 << j;
		//				break;
						change = true;
					}
				}
				if (change) {
					Node obj(state);
					obj.step = head.step + 1;
				//	if (hash.find(obj.state) == hash.end()) {					
						memcpy(obj.count, tmp, sizeof(tmp));
						//hash[obj.state] = true;
						q.push(obj);
						cout << obj.state << ' ' << stickers[i] << endl;
				//	}
				}
			}
		}
		return -1;
	}	
private:
	struct Node {
		int state;
		int step{ 0 };
		int count[26]{  };
		Node(int state) :state(state) {};
	};
	//unordered_map<int, bool> hash;
};

int main() {
	//vector<string> s{ "final","figure","danger","fish","some","product","son","seed","crease","rail","even","death","end","sit","live","behind","start","enough","much","between","test","is","happy","we","north","complete","month","reach","excite","stay","job","fell","letter","noun","seat","exact","than","ago","protect","kept","this","plain","flow","face","bird","sand","rock","roll","root","fact" };
	vector<string> s{ "with", "example", "science" };
	//"thehat"
	cout << Solution().minStickers(s, "thehat") << endl;
	system("pause");
	return 0;
}