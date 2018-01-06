#include "common.h"

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

		int n = gas.size();
		vector<int> f;

		int p = 0;
		int sum = 0;
		for (int i = 0; i < n; i++)
			f.push_back(gas[i] - cost[i]);
		int count = 0;
		int current = 0;
		while (p<n) {
			sum += f[current];			
			if (sum < 0) {
				for (int i = p; i <= current; i++)
					f.push_back(f[i]);
				p = ++current;
				sum = 0;
				count = 0;
				continue;
			}
			count++;
			++current;
			if (count >= n) return p;
		}
		return -1;
	}
};
//
//int main() {
//	vector<int> a{ 2,5 }, b{ 3,4 };
//	Solution obj;
//	cout << obj.canCompleteCircuit(a, b) << endl;
//	system("pause");
//}