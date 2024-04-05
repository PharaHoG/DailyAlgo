class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> nums_map;
        int size = nums.size();

        for(int i = 0; i < size; i++) {
            nums_map[nums[i]]++;
        }

        // 注意lambda的使用
        auto lamb = [] pair<int, int>& t1, pair<int, int>& t2) -> bool { return t1.second > t2.second; };
        // 优先队列的定义
        priority_queue<p(air<int, int>, vector<pair<int, int>>, decltype(lamb)> pq;

        // 堆的实现
        for(auto p : nums_map) {
            pq.push(p);
            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> result;

        for(int i = 0; i < k; i++) {
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};