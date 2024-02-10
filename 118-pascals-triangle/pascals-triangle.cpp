class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rows;
        vector<int> next_row;
        vector<int> row;
        
        for(int i = 1; i <= numRows; i++){
            if(i == 1){
                row = vector<int>(1);
                row[0] = 1;
            }
            if(i == 2){
                row = vector<int>(2);
                row[0] = 1;
                row[1] = 1;
            }
            else{
                next_row = vector<int>(i);
                next_row[0] = 1;
                next_row[i - 1] = 1;
                for(int j = 1; j < i - 1; j++){
                    next_row[j] = row[j - 1] + row[j];
                }
                row = next_row;
                
            }
            rows.push_back(row);
            
        }
        
        return rows;
    }
};