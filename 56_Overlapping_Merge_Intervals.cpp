// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// // Comparator to sort by start times
// bool cmp(vector<int>& a, vector<int>& b) {
//     return a[0] < b[0];
// }

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         // Sort intervals by start time
//         sort(intervals.begin(), intervals.end(), cmp);

//         vector<vector<int>> result;
//         int n = intervals.size();

//         // Start by adding the first interval
//         result.push_back(intervals[0]);

//         for (int i = 1; i < n; i++) {
//             vector<int> curr = intervals[i];

//             // Check if current interval overlaps with the last one in result
//             if (curr[0] <= result.back()[1]) {
//                 // Merge intervals by adjusting the end time
//                 result.back()[1] = max(result.back()[1], curr[1]);
//             } else {
//                 // No overlap, add the current interval to the result
//                 result.push_back(curr);
//             }
//         }

//         return result;
//     }
// };

// int main() {
//     Solution sol;
//     vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    
//     vector<vector<int>> merged = sol.merge(intervals);

//     for (const auto& interval : merged) {
//         cout << "[" << interval[0] << ", " << interval[1] << "] ";
//     }
//     cout << endl;

//     return 0;
// }

         // Another Methods


    #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp); // Sort by start times

        vector<vector<int>> result;
        int n = intervals.size();
        result.push_back(intervals[0]); // Add the first interval

        for (int i = 1; i < n; i++) {
            vector<int>& curr = intervals[i];

            // Check if current interval overlaps with the last one in result
            if (curr[0] <= result.back()[1]) {
                // Merge intervals by adjusting the start and end times
                result.back()[0] = min(result.back()[0], curr[0]);
                result.back()[1] = max(result.back()[1], curr[1]);
            } else {
                // No overlap, add the current interval to the result
                result.push_back(curr);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    
    vector<vector<int>> merged = sol.merge(intervals);

    for (const auto& interval : merged) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
