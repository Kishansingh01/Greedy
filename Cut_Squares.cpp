//  If we have divided the grid in rectangle and a cut later will be done on multiple 
//  rectangle ,then cost of the cut should be considered an each rectangle.

// Vertical cuts increase the horizontal blocks, horizontal cut increase the 
// vertical blocks.

// This C++ code calculates the minimum cost to break a grid
// into unit squares, given the cost of making horizontal and vertical
// cuts. The grid is n x m in size, and the costs for making each vertical
//and horizontal cut are provided

#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;

bool cmp(int x,int y){ //Descendingorder cmp=comparator  fpr sorting
    return x > y;
}

ll minCostToBreakGrid(int n,int m,vector<ll>&vertical,vector<ll>&horizontal){
   // n: the number of rows(height of the grid), m=no of columns(width of the grid)
   // vertical: the cost of making each vertical cut
   // horizontal: the cost of making each horizontal cut
    sort(vertical.begin(), vertical.end(), cmp);
    sort(horizontal.begin(), horizontal.end(), cmp);

    int hz = 1;  // Number of horizontal cuts
    int vr = 1;  // Number of vertical cuts
    int h = 0, v = 0; //h= keep track horizontal and vertical piece initialising to 0.
    ll ans = 0; // ans will store the total cost

    // Process both horizontal and vertical cuts
    while(h < horizontal.size() && v < vertical.size()){
        if(vertical[v] > horizontal[h]){
            ans += vertical[v] * vr;
            hz++;
            v++;
        }
        else{
            ans += horizontal[h] * hz;
            vr++;
            h++;
        }
    }

    // Add remaining horizontal cuts
    while(h < horizontal.size()){
        ans += horizontal[h] * hz;
        vr++;
        h++;
    }

    // Add remaining vertical cuts
    while(v < vertical.size()){
        ans += vertical[v] * vr;
        hz++;
        v++;
    }

    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> horizontal, vertical;

    // Input for horizontal cuts
    for(int i = 0; i < m-1; i++){
        int x;
        cin >> x;
        vertical.push_back(x);
    }

    // Input for vertical cuts
    for(int i = 0; i < n-1; i++){
        int x;
        cin >> x;
        horizontal.push_back(x);
    }

    cout << minCostToBreakGrid(n, m, vertical, horizontal) << endl;

    return 0;
}

// 6 4 Input
// 2 Start vertical cut
// 1
// 3
// 1 
// 4 till vertical cut

// 4 start horizontal cut
// 1
// 2 Till horizontal cut
// 41 Answer ,Here answer is coming 42 but i am getting 41 i do not know.
