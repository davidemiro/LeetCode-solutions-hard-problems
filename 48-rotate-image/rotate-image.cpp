class Solution {
public:
    
    void rotate(vector<vector<int>>& matrix) {
    int N = matrix.size() -1;
    int tmp,tmp1,new_r,new_c,old_r,old_c;

    for(int r = 0; r < N; r++){
        for(int c = r; c < N - r; c++){
            old_r = r;
            old_c = c;
            for(int i = 0; i < 4; i++){
                new_r = old_c;
                new_c = N - old_r;
                if(i != 0){
                    tmp1 = matrix[new_r][new_c];
                    matrix[new_r][new_c] = tmp;
                    tmp = tmp1;
                }
                else{

                    tmp = matrix[new_r][new_c];
                    matrix[new_r][new_c] = matrix[old_r][old_c];

                }
                old_r = new_r;
                old_c = new_c;

            }
        }

    }

}
};


