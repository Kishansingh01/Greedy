
//  2182 .  Construct String with Repeat limit.

// I have given the words where we have to go the word with highest 
// ascii value  will come first and if it has asked for k times then till two 
// times i will take  its after i will take the second highest ascii values value.
//    Example->          Question->   aaabbbbbb.
//                        Answer-->   bbbabbbaa   k=3 times.



 class Solution{
    public: 
       string repeatLimitedString(string s,int repeatlimit){
        unordered_map<char,int>mp;
        for(int i=0;i< s.size();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<char,int>> pq;
        for(auto p:mp){
            pq.push(p);
        }
        string result = "";
        while(!pq.empty()){
            auto largest=pq.top();
            pq.pop();
            int len=min(repeatlimit,largest.second);
            for(int i=0;i<len;i++){
                result+=largest.first;
            }
            pair<char,int> secondLargest;
            if(largest.second - len>0){
                if(!pq.empty()){
                    secondLargest=pq.top();
                    pq.pop();
                    result+=secondLargest.first;
                }
                else{
                    return result;
                }
                if(secondLargest.second -1 >0) pq.push({secondLargest.first,secondLargest.scond -1});
                pq.push({largest.first,largest.second-len});
            }

        }
        return result;
       }
 };