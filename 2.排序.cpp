class Solution {
public:
    long long process(vector<int> nums, long long l, long long r) {
        if(l == r)
            return 0;
        long long mid = l + ((r - l) >> 1);
        return process(nums,l,mid) + process(nums,mid + 1,r) + merge(nums,l,mid,r);
    }
    long long merge(vector<int> nums,int l, int m, int r) {
        vector<int> help(r - l + 1);
        int i = 0;
        int p1 = l;
        int p2 = m + 1;
        long long res = 0;
        while (p1 <= m && p2 <= r) {
          res += nums[p1] < nums[p2] ?(r - p2 + 1) * nums[p1] : 0;
          help[i ++] = nums[p1] < nums[p2] ? nums[p1++] : nums[p2++];
        }
        while(p1 <= m) { //此时没有结束的一定是剩下的有序元素
         help[i ++] = nums[p1++];
         }
         while(p2 <= r) {
         help[i ++] = nums[p2++];
         }
         for(i = 0; i < help.size(); i++) {
         nums[l + i] = help[i];
        }
      return res;
       }
    long long calArray(vector<int>& nums) {
      if(nums.size() == 2)
          return 0;
      long long l = 0;
      long long r = nums.size() - 1;
      return process(nums,l,r);
    }
};
