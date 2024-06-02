class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0,j=s.size()-1;
        while(i<j){
            swap(s[i++],s[j--]); 
        }
    }
};
/*
h e l l o 

rev -> o l l e h

0 1 2 3 4

h e l l o 

o

*/