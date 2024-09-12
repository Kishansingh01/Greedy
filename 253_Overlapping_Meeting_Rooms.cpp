// 253.  I have given that arr [[0,30],[5,10],[15,20]] 0,5,15 is the starting 
// of the meeting and 30,10,20 is the ending timing of the meeting 
// so i will start from 0 and ending is 30 so room need is 1 ,then 5 
// but


class Solution{
    public:
    int minMeetingRooms(vector<vector<int>>&intervals){
        vector<int> start,ending;
        for(auto el:intervals){
            start.push_back(el[0]);
            ending.push_back(el[1]);
        }
    sort(start.begin(),start.end());
    sort(ending.begin(),ending.end());
    int ans=0;
    int rooms=0;
    int i=0;j=0
    while(i<start.size() and j<ending.size()){
        if(start[i] < ending[j]){
            // a meeting is starting 
            rooms++;
            ans=max(ans,rooms);
            i++;
        }
        else if(start[i]>ending[j]){
            // a meeting is ending
            rooms--;
            j++;
        }
        else{
            i++;
            j++;
        }
    }
         return ans;
    }
};