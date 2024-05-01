class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n= word.size();
        for (int i=0; i<n; i++){
            if (word[i]==ch){
                
                for (int j=0; j<=i/2; j++){
                    swap(word[i-j], word[j]);
                }
                return word;
            }
        }
        return word;
    }
};