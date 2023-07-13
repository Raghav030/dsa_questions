#include<bits/stdc++.h>
using namespace std;
bool my_compare (pair <int, int> a, pair <int, int> b){
    if (a.first!=b.first) return a.first<b.first;
    return a.second>b.second;
    
};
int main()
 {
	//code
	int t;
	cin>>t;
	for (int i=0; i<t; i++){
	    int n;
	    cin>>n;
	    vector <int> arr(n);
	    for (int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    unordered_map <int, int> mpp;
	    priority_queue <pair<int, int>, vector <pair<int, int>>, decltype(&my_compare)> pq(&my_compare);
	    for (int i=0; i<n; i++){
	        mpp[arr[i]]+=1;
	    }
	    for (auto t: mpp){
	        pq.push({t.second, t.first});
	    }
	    while (!pq.empty()){
	        auto t= pq.top();
	        for (int i=0; i<t.first; i++){
	            cout<<t.second<<" ";
	        }
	        pq.pop();
	    }
	    cout<< endl;
	}
	
	return 0;
};