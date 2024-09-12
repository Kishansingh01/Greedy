// Fractional Knapsack means backpack mtlb ek bora ka weight 10 kg hai to kitne samaan ko till 
// 10 kg tk daal sakte hai. Brute force method me bahut time leta hai.

// 0 / 1 knapsack we use dp(Dynamic programming.).

//                   weight
// N items    items->               -->Maximum profit
//                   Profit

//       Fractional  Knapsack ->maximum capacity weight is W.

//     //   Best Examples
//     Total weight i have to take is =>  50
     
//      item 1 -> Profit->60   Weight->10
//      item 2 -> Profit->100  Weight->20
//      item 3 -> Profit->120  Weight->30

//      So, maximum  should be add item 1,3 and  20 weight from items 3
//      which will cost 240.

//      I cannot go for item 2,3 only because its cost only is 220. means value by weight ratio should be more.

//  cmp->Custom comperator sort (nlogn)



// We have did by doing the value by ratio 

#include<iostream>
#include<vector>
#include<algorithm  >
using namespace std;

bool cmp(pair<int,int> &p1, pair<int,int> &p2){
  //pair<int,int> first ->value,second ->weight
  double r1=(p1.first*1.0)/(p1.second*1.0);
  double r2=(p2.first*1.0)/(p2.second*1.0);
  return r1 > r2;

}
int fractionalKnapsack(vector<int>&profit,vector<int>&weights,int n,int w){
  vector<pair<int,int>> arr;
  for(int i=0;i<n;i++){
    arr.push_back({profit[i],weights[i]});
  }
  sort(arr.begin(),arr.end(),cmp);
  double result=0;
  for(int i=0;i<n;i++){
    if(arr[i].second<=w){
      result+=arr[i].first;
      w-=arr[i].second;
    }
                    // TC: O(nlogn)
                    // Space complexity: (sorting algo)
    else{        
      result+=((arr[i].first*1.0)/(arr[i].second*1.0))*w;
      w=0;
      break;
    }
  }
  return result;

}

int main(){
  vector<int>profit={60,100,120};
  vector<int>weights={10,20,30} ;
  int w=50;
  int n=3;
  cout<<fractionalKnapsack(profit,weights,n,w)<<endl;
 return 0;
}