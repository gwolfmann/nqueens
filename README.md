# nqueens
A nqueens problem c++ solution using functional programming features

compile with -std=c++14 flag

A solution of an usual and well know problem using C++ functional programming features

Its intent is to show C++ code that combines a high expressivity with an indubitable high performance of the compiled code. I want to remark that it is not the best performance solution that can be found, but one that combines high-level programming with running efficiency.

This solution is based on a traditional representation of a vector of size n, where n is the size of the board. Each position on the vector represents a row in the board and in each position represents the column in the respective row where it is present a queen. The final solution is a combination of values in the vector that represents a board with queens not attacking each other.

The algorithm design is based on the car odometer spinning wheel. The board is a vector of wheels that spins from 0 to n-1 like a car odometer, left to right in this case. It uses a backtracking strategy. Beginning with all wheels in 0, it increments by one in right to left order until a combination of the n position is valid or until it reaches an invalid position, in which case it increments the actual wheel. If the actual wheel reaches the 0, it represents that no value of this combination is valid and backtracks to the previous wheel incrementing it by one and begins with 0 again. It is similar to a recursive backtracking algorithm but without of recursion.




