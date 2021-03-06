//
// Created by reut on 09/01/19.
//

#include "MatrixInter.h"
#include "IndexsMat.h"
/**
 * interpater: get the vector of vector of input and return a matrix(Searchable)
 * @param input
 * @return
 */
Searchable<IndexsMat>* MatrixInter::interpretation(vector<vector<string>> input) {

    vector<vector<State<double >*>> myMatrix;
    vector<vector<State<IndexsMat>*>> matrix;

    auto * matrixSearchable=new MatrixSearchable();
    vector<string> end = input.back();
    input.pop_back();
    vector<string> start = input.back();
    input.pop_back();
    int size = input.size();
    //convert from string to state
    for(int i  = 0;i<size;++i){
        vector<State<IndexsMat >*> vec;
        for(int j  = 0;j<input[i].size();++j){
            double val = stod(input[i][j]);
            IndexsMat indexsMat;
            indexsMat.setColumn(j);
            indexsMat.setRow(i);
            auto * state = new State<IndexsMat>(indexsMat,val,0);
            vec.push_back(state);
            if((i == stoi(start[0])) && (j==stoi(start[1]))){
                matrixSearchable->setStart(state);
            }
            if((i == stoi(end[0])) && (j==stoi(end[1]))){
                matrixSearchable->setEnd(state);
            }
        }
        //add it to matrix
        matrix.push_back(vec);
    }

    matrixSearchable->setMatrix(matrix);


    jj.push_back(matrixSearchable);


    return matrixSearchable;
}
