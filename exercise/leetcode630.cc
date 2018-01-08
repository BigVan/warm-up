#include "common.h"

class Solution {
public:
	int scheduleCourse(vector<vector<int>>& courses) {

		n = courses.size();
		if (n == 0) return 0;
		sort(courses, 0, n - 1);
		priority_queue<int> heap;
		int start = 0;
		//heap.push(0);
		for (auto it : courses){
			start += *it.begin();
			heap.push((*it.begin()));
			while (start > it.back()) {
				start -= heap.top();
				heap.pop();
			}
		}

		return heap.size();
	}

private:
	vector<int> f;
	vector<int> g;
	int n, m;

	void sort(vector<vector<int>> & courses, int l, int r) {

		int i = l, j = r;
		int delta = courses[(l + r) >> 1][1];
		while (i <= j) {
			while (courses[i][1] < delta) i++;
			while (courses[j][1] > delta) j--;
			if (i <= j){
				auto swap = courses[i];
				courses[i] = courses[j];
				courses[j] = swap;
				i++; j--;
			}
		}
		if (i < r) sort(courses, i, r);
		if (l < j) sort(courses, l, j);
	}
};
//
//int main() {
//
//	vector<vector<int>> c{ {100,200},{200,1300},{1000,1250},{2000,3200} };
//	cout << Solution().scheduleCourse(c)<<endl;
//	system("pause");
//	return 0;
//}