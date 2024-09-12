// Error is also coming in leetecode after the CHATGPT using it is not coming.

class Solution {
public:
    priority_queue<int> maxheap; // max-heap for the lower half
    priority_queue<int, vector<int>, greater<int>> minheap; // min-heap for the upper half
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result(nums.size() - k + 1, 0);
        
        for(int i = 0; i < nums.size(); i++) {
            // Insert into the max heap first
            maxheap.push(nums[i]);
            
            // Ensure all elements in maxheap are <= elements in minheap
            if(!maxheap.empty() && !minheap.empty() && maxheap.top() > minheap.top()) {
                minheap.push(maxheap.top());
                maxheap.pop();
            }
            
            // Balance the heaps
            balance();
            
            // When we've hit the window size
            if(i - k + 1 >= 0) {
                // Add the median to the result
                if(maxheap.size() == minheap.size()) {
                    result[i - k + 1] = (maxheap.top() + minheap.top()) / 2.0;
                } else {
                    result[i - k + 1] = maxheap.size() > minheap.size() ? maxheap.top() : minheap.top();
                }
                
                // Remove the element that's sliding out of the window
                int element_to_remove = nums[i - k + 1];
                erase(element_to_remove);
                balance();
            }
        }
        
        return result;
    }
    
    void balance() {
        if(maxheap.size() > minheap.size() + 1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        } else if(minheap.size() > maxheap.size()) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    void erase(int element) {
        if(!maxheap.empty() && element <= maxheap.top()) {
            // Lazy removal in maxheap
            maxheap.pop();
        } else if(!minheap.empty() && element >= minheap.top()) {
            // Lazy removal in minheap
            minheap.pop();
        }
    }
};
