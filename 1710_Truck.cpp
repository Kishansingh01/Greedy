// 1710:: Maximum Units of a truck

// [[1,3](size 0),[2,2](size 1),[3,1](size 2)]  
// 1,2,3 Number of boxes in the array  3,2,1  price numberOfUnitsPerBoxes

// [[1,3](size 0),[2,2](size 1),[3,1](size 2)] ->

bool cmp(vector<int>&a,vector<int>&b){
    return a[1] > b[1];
}

class Solution{
    public:
        int maximumUnits(vector<vector<int>>& boxTypes, int truckSize){
            // Sort the boxes by the number of units per box in descending order
            sort(boxTypes.begin(), boxTypes.end(), cmp);
            int profit = 0;
            
            for(int i = 0; i < boxTypes.size(); i++){
                if(truckSize == 0) break; // If the truck is full, stop the loop
                
                // Calculate the number of boxes to take
                int boxesToTake = min(boxTypes[i][0], truckSize);
                
                // Add the units of the boxes to the profit
                profit += boxesToTake * boxTypes[i][1];
                
                // Decrease the remaining truck capacity
                truckSize -= boxesToTake;
            }
            
            return profit;
        }
};
