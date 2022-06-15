class Solution {
public:

    int scheduleCourse(vector<vector<int>>& courses) {
        //O(n * c), O(1)
        sort(courses.begin(), courses.end(),[] (const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        
        int time = 0;
        int c = 0;
        
        int n = courses.size();
        
        for(int i = 0; i < n; i++)
        {
           
            
            if(time + courses[i][0] <= courses[i][1]) {//courses[i][1] = end
                
                time += courses[i][0];
                
                courses[c++] = courses[i];
                
            }
            
            else {
                int max_i = i;
                for(int j = 0; j < c; j++) {
                    
                    if(courses[j][0] > courses[max_i][0]) {
                        max_i = j;
                    }
                }
                
                if(courses[max_i][0] > courses[i][0]) {
                    time += courses[i][0] - courses[max_i][0];
                    courses[max_i] = courses[i];
                }
            }
            
            
        }
        
        return c;
    }
};