class Solution {
public:

    int minDifference(vector<int>& v) {
         
         if(v.size()<=4)
          return 0;
        int n = v.size();
        sort(v.begin(),v.end());
        return min({v[n-4]-v[0] , v[n-1]-v[3] , v[n-3] - v[1] , v[n-2] - v[2]    });
    }
};
/*
n = 6
 0 1 2 3 4 5
 a b c d e f 
 
 1 - a b c   ->  c-a
 2 - d e f   ->  f-d
 3 - b c d   ->  d-b
 4 - c d e   ->  e-c
 
 0 1 5 10 14
 
 
*/