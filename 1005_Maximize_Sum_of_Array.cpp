// Hmlog ko sum aise karna hai ,ki k=3 , mtlb number ke sign ko jitne k times bola hai to us array mw se sign ko us k times badle ki maximum sum aaye.

// In brute foprce i will try to create all possibilities of the given number such that once the 
// number can be negated or not.

// The best decision i will take by observation i will take decision relavent  it and that decision is 
// called greedy algorithms.

// Greedy Algoriyhms- Smart Choice

// Total time Complexity=>O(klogn+n)
class Solution{
    public:
      int laggestSumAfterKNegations(vector<int>&nums,int k){
        priority_queue<int,vector<int>,greater<int> pq(nums.begin(),nums.end());// O(n)
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        while(k--){ //O(klogn)
            int el=pq.top(); //min element
            if(el==0){
                break;
            }
            pq.pop(); //Remove the smallest
            sum-=el;
            pq.push(-1*el); //add the negated number
            sum+=(-el);
        }
        return sum;
      }
};