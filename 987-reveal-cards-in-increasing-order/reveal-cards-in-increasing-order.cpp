class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
       int n= deck.size();
       sort(deck.rbegin(), deck.rend());
    //    vector<int>temp(n/2, -1);
    //    int j=0;
    //    int i=n%2==0? n/2: n/2+1;
    //    for (i; i<n; i++) {
    //     temp[j]= deck[i];
    //     j+=1;
    //    }
    //    j=n-1;
    //    i=n%2==0? n/2-1: n/2;
    //    for (i; i>=0; i-=1){
    //         deck[j]=deck[i]; 
    //         j-=2;
    //    } 
    //    if (temp.size()%2==1) {
    //     temp.push_back(temp[0]);
    //    }
    //    j=temp.size()-1;
    //    for (int i=1; i< n; i+=2){
    //     deck[i]=temp[j];
    //     j-=1;
    //    }
    //    return deck;
    deque<int> d;
    d.push_back(deck[0]);
    for (int i=1; i<deck.size(); i++){
        d.push_front(d.back());
        d.pop_back();
        d.push_front(deck[i]);
    }
    vector<int> res(d.begin(), d.end());
    return res;
    }
};