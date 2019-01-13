/*

#include <iostream>
#include "Test.h"
#include "BreadthFirstSearch.h"
#include "State.h"
#include "dddd.h"
#include "SolveSearch.h"
#include "DepthFirstSearch.h"
#include "InterpaterAnswerMatrix.h"
#include "ClientHandler.h"
#include "ChachManager.h"
#include "MyClientHandler.h"
#include "Solver.h"
#include "FileCacheManager.h"
#include "SocketRead.h"
#include <iostream>
#include <chrono>
#include "SocketWrite.h"
int main() {
    std::cout << "Hello, World!" << std::endl;


    auto* mySerialServer = new MySerialServer();
    auto* ooo = new SocketRead();
    ooo->SetId(5402);
    auto* bbb = new SocketWrite();
    bbb->SetSocketWrite(5400);

    vector<vector<string>> ff;
    vector<string> dd = {"1","2","3"};
    ff.push_back(dd);
    vector<string> gg = {"-1","-1","-1"};
    ff.push_back(gg);
    vector<string> ww = {"7","8","9"};
    ff.push_back(ww);
    vector<string> w = {"0","0"};
    ff.push_back(w);
    vector<string> w0 = {"2","2"};
    ff.push_back(w0);


    auto * cm = new FileCacheManager<string,string>;

    auto * interS = new InterpaterAnswerMatrix;
    MatrixInter* mat = new MatrixInter;
    auto *dfs = new DepthFirstSearch<IndexsMat>();
    auto* bfs = new BreadthFirstSearch<IndexsMat>();
    auto * solver = new SolveSearch<IndexsMat ,string> (dfs,mat,interS);
    //solveSearch.solve(ff);

    auto * myCli = new MyClientHandler(solver,cm);

    mySerialServer->open(5400,myCli);
    cm->writeToFile();


    Test t;
    t.testAll();
    int i=0;

    return 0;
}

 */
#include <iostream>
#include "Test.h"
#include "BreadthFirstSearch.h"
#include "State.h"
#include "dddd.h"
#include "SolveSearch.h"
#include "DepthFirstSearch.h"
#include "InterpaterAnswerMatrix.h"
#include "ClientHandler.h"
#include "ChachManager.h"
#include "MyClientHandler.h"
#include "Solver.h"
#include "FileCacheManager.h"
#include "SocketRead.h"
#include <iostream>
#include <chrono>
#include "SocketWrite.h"
#include "MyParallelServer.h"
#include "IndexsMat.h"
#include "SolveSearch.h"
int main() {
    //  ParamsToUpdate* params = new ParamsToUpdate();
    // auto start = std::chrono::system_clock::now();
    //Searcher<int>* solver = new BestFirstSearch<int>();
    auto* mySerialServer = new MyParallelServer();
/*
   auto* ooo = new SocketRead(5402);ParallelServer
   auto* bbb = new SocketWriter(5400);
*/

    //RowAndCol fff()
    // Searcher<> best = new BestFirstSearch
    // auto* best = new BestFirstSearch<RowAndCol>();
    auto* mm = new FileCacheManager<string,string>;
    //mm->loadFile();
    auto* nn = new BreadthFirstSearch<IndexsMat>();
    auto* interpeterProblem = new MatrixInter();
    auto* interpterSolution = new InterpaterAnswerMatrix();
    auto* serchhhhh = new SolveSearch<IndexsMat, string>(nn,interpeterProblem,interpterSolution);
    //auto* paramsToUpdate = new ParamsToUpdate();
    auto* clietS = new MyClientHandler(serchhhhh, mm);


    mySerialServer->open(5400,clietS);

    mm->writeToFile();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}

