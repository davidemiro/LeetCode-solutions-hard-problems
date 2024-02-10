class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> solution(rowIndex + 1);
        solution[0] = 1; 
        solution[rowIndex] = 1;
        if(rowIndex == 0){
            return {1};
        }
        else if(rowIndex == 1){
            return {1,1};
        }
        else{
            solution[0] = 1;solution[1] = 1;
            for(int j = 2; j <=rowIndex ; j ++){
                solution[j] = 1;
                for(int i = j - 1; i >= 1; i--){
                    solution[i] = solution[i] + solution[i - 1];
                }
            }
        }
        return solution;
    
        
    }
};