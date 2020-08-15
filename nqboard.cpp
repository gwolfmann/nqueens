#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;

int boardSize;

struct Wheel {
	int v {0};
	int pos;
	void next() { v++; if (v>boardSize) v=0;};
	bool isFinished() {return v==0;};
	int val() {return v;};
};

typedef std::vector<Wheel> Board;

struct Solution {
	Board t ;
	std::vector<Board> sol {}; 
	int index {0};
	Solution(int j) {t = Board(j);}; 
	void printBoard(Board t){ std::for_each(t.begin(),t.end(),[](Wheel m){  std::cout << m.val() << " ";});
        	      std::cout << std::endl;
    	}
	void init() {int n=0;
		std::for_each(t.begin(),t.end(),[&n](Wheel &x){x.pos=n++;});
		next(); // must begin with 1
	};
	bool validCol(Wheel m) { 
		if (m.isFinished()) return true;
		for (int j=1; (j+m.pos) < boardSize; j++) {
		    Wheel mm = t[m.pos+j];
		    if (mm.isFinished()) return true;
                    if ((m.val()==mm.val())   || 
			(m.val()==mm.val()+j) || 
			(m.val()==mm.val()-j) ) 
			    return false;
		}
		return true;};
	bool isValid()    {return std::all_of(t.begin(),t.end(),[this](Wheel m){return this->validCol(m);} );};
	bool isFinished() {return t[0].isFinished();} ;
	//bool isFinished() {return std::all_of(t.begin(),t.end(),[](Wheel m){return m.isFinished();} );};
	bool isSolution() {return std::none_of(t.begin(),t.end(),[](Wheel m){return m.isFinished();} );};
	void next() {t[index].next();nextStep();};
	void nextStep() { if (t[index].isFinished()){
			     index--;
		          } else {
			     if (isValid()) {
				 if (index==boardSize-1){
				     if (isSolution()){
	     		  		 sol.push_back(std::vector<Wheel> (t));
				     }
				 } else {
				    index++;
				 }
			 }
                    }
                 }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "usage: nqb n : n = board size " << endl;return 0;
    }
    boardSize = std::stoi(argv[1]);

    Solution ta (boardSize);
    ta.init();

    auto start = std::chrono::steady_clock::now();
    do {
        ta.next();
    } while (!ta.isFinished()); // for all solutions
    //} while (ta.sol.size()<1);  // for only one solution
    auto end = std::chrono::steady_clock::now();
    
    for(auto t :ta.sol) ta.printBoard(t);

    std::chrono::duration<double> elapsed_seconds = end-start;
    cout << "problem resolved in elapsed time: " << elapsed_seconds.count() << " with " << ta.sol.size() << " solutions" << endl;
}
