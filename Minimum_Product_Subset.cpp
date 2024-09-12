// Means i have to product the number such that their multiplication 
// should be least as a company.

// I can use subarray for them but their time complexity will 
// be O(2^n). But this is the worst time complexity method.

// Is question me kuch positive number ke saath zero hai, to zero answer hi hoga.

#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>  // or use <limits.h>

using namespace std;

int minProduct(vector<int>&arr){
    int cn=0,cz=0,cp=0; // cn=count of negative , cz= count of zero cp=count of positive.

    int prod_pos=1; //product positive
    int prod_neg=1; // product negative
    int largestNegative=INT_MIN;

    for(int i=0;i<arr.size();i++){
        if(arr[i]<0){ cn++;
        prod_neg*=arr[i];
        largestNegative = max(largestNegative,arr[i]);// Maximum for the largest negative.
        
        }

        if(arr[i]==0) cz++;

        if(arr[i]>0) {
            cp++;
            prod_pos*=arr[i];
        }
    }
    if(cn==0){
        if(cz>0) return 0;
        else{
            auto it = min_element(arr.begin(),arr.end());//This is the function to find the minimum element
            return *it;
        }
    }
    else{
        if(cn % 2==0){ //even
            return (prod_neg/largestNegative)* prod_pos;

        }else{
            //odd
            return prod_neg* prod_pos;
        }
    }
}

int main(){
    // vector<int>arr{-2,-3,1,4,-2,-5}; // -120(here -2 get removed (Line 37)bcz if it will not get removed then the positive value will come.but we need minimum value)
    //  vector<int>arr{-2,-3,1,4,-2}; // -48
      vector<int>arr{0,1,2,3}; //0 bcz for  minimum zero i have to take.
     cout<<minProduct(arr)<<endl;
}

