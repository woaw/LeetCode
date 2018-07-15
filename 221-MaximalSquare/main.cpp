//
//  main.cpp
//  TestC++
//
//  Created by Woaw on 2018/4/15.
//  Copyright © 2018年 Woaw. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
#define MIN(a, b) ((a) > (b) ? (b):(a))
#define MAX(a, b) ((a) > (b) ? (a):(b))

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0){
            return 0;
        }
        
        const long m = matrix.size();
        const long n = matrix[0].size();
        int length = 0;
        int result[m][n];
        for(long i=0;i<m;i++){
            result[i][0] = matrix[i][0]-'0';
            length = MAX(length, result[i][0]);
        }
        for(long j=0;j<n;j++){
            result[0][j] = matrix[0][j]-'0';
            length = MAX(length, result[0][j]);
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                //cout<<result[i-1][j]<<result[i][j-1]<<result[i-1][j-1]<<endl;
                if(matrix[i][j]=='1'){
                    result[i][j] = MIN(result[i-1][j-1], MIN(result[i][j-1], result[i-1][j]))+1;
                }
                else{
                    result[i][j] = 0;
                }
                //cout<<result[i][j]<<endl;
                length = MAX(length, result[i][j]);
            }
        }
        return length*length;
    }
};

int main(int argc, const char * argv[]) {
   
    vector<vector<char>> matrix = {{'0','0','0','1'},{'1','1','0','1'},{'1','1','1','1'},{'0','1','1','1'},{'0','1','1','1'}};
    Solution solution;
    int result = solution.maximalSquare(matrix);
    cout<<result<<endl;
    return 0;
};
