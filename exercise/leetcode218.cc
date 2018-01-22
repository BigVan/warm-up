#include "common.h"

class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {

		int maxH = 0;
		vector<Segment> segs{};
		for (auto build : buildings) {
			Segment segStart(build[0], build[2], 1);
			Segment segEnd(build[1], build[2], 0);
			maxH = max(maxH, build[2]);
			segs.push_back(segStart);
			segs.push_back(segEnd);
		}
		sort(segs.begin(), segs.end());
		for (auto seg : segs) {
			printf("%d\n", seg.pos);
		}
		return {};
	}

private:
	struct Segment{
		int pos, value, tag;
		Segment(int pos, int value, int tag) :pos(pos), value(value), tag(tag) {}
		bool operator <(Segment seg) {
			return this->pos < seg.pos;
		}
	};
	struct SegTree {
		int height;
		int count;
		//SegTree * left, *right;
		SegTree(int height, int count) :height(height), count(count) {
		//	left = right = nullptr;
		}
	};
};

int main() {
	vector<vector<int>> buildings{
		{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8} };
	Solution().getSkyline(buildings);
	system("pause");
	return 0;
}