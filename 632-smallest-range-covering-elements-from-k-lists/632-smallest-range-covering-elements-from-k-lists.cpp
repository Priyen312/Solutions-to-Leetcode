class Solution {
public:
    
    struct Node
	{
		int val;
		int i;
		int j;

		Node(int _val, int _i, int _j) :val(_val), i(_i), j(_j) {}
	};
	struct cmp
	{
		bool operator()(Node n1, Node n2)
		{
			return n1.val > n2.val;
		}
	};

	
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        priority_queue<Node,vector<Node>,cmp> my_pq;
		int cur_min = INT_MAX, cur_max = INT_MIN,cur_range = INT_MAX;
		int start, end;
		for (int i = 0; i < nums.size(); i++)
		{
			Node tem_node(nums[i][0], i, 0);
			my_pq.push(tem_node);
			cur_max = max(cur_max, nums[i][0]);
		}

		while (true)
		{
			auto top = my_pq.top();
			my_pq.pop();
			cur_min = top.val;
			if (cur_max - cur_min < cur_range)
			{
				start = cur_min;
				end = cur_max;
				cur_range = end - start;
			}

			if ((top.j + 1) == nums[top.i].size())
				break;
            Node next(nums[top.i][top.j + 1], top.i, top.j + 1);
			my_pq.push(next);
			if (next.val > cur_max)
				cur_max = next.val;

		}
		vector<int> ret = { start,end };

		return ret;
        
        
    }
};