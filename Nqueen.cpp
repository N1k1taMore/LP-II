#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class NQueen {
public:
    int N;
    vector<vector<int>> board; // Using vector of vectors for dynamic 2D array
    bool *cols;   //branch and bound
    bool *ndiag;
    bool *rdiag;
    bool flag=false;

    // Constructor to initialize the board size
    NQueen(int n) {
        N = n;
        board = vector<vector<int>>(n, vector<int>(n, 0));
        cols=new bool[n];
        ndiag=new bool[2*n-1];
        rdiag=new bool[2*n-1];
        for (int i = 0; i < n; ++i)
                cols[i] = false;
        for (int i = 0; i < 2 * n - 1; ++i)
                ndiag[i] = rdiag[i] = false;
    }

    void printSolution() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << (board[i][j] == 1 ? "Q " : ". ");
            cout << endl;
        }
        cout<<endl;
    }

    bool isSafe(int x, int y) {

        // Check if the column is empty
        for (int row = 0; row < x; row++){
            if (board[row][y] == 1)
                return false;
        }

        // Check upper diagonal on left side
        int row,col;
        for (row=x, col=y; row >= 0 && col >= 0; row--, col--){
            if (board[row][col] == 1)
                return false;
        }

        // Check upper diagonal on right side
        for (row=x,col=y; row >= 0 && col< N; row--, col++){
            if (board[row][col] == 1)
                return false;
        }

        return true;
    }

    bool solveNQUtil(int row) {

        // Base case: If all queens are placed, return true
        if (row >= N){
            return true;
        }

        for(int col=0;col<N;col++){
            if(isSafe(row,col)){
                board[row][col] = 1;
                cout<<"Queen placed"<<endl;
                printSolution();

                if(solveNQUtil(row+1)){
                    return true;
                }
                board[row][col] = 0; // BACKTRACK
                cout<<"Cannot place the queen so back track"<<endl;
                printSolution();
            }
        }

        // If the queen cannot be placed in any row in this column col, then return false
        return false;
    }

    // Main function to solve N-Queen problem
    bool solveNQ() {
        if (!solveNQUtil(0)) {
            cout << "Solution does not exist" << endl;
            return false;
        }

        // Print the solution
        cout << "Solution Exists:" << endl;
        printSolution();
        return true;
    }

    void branch$bound(int row){
        if(row==N){
            flag=true;
            printSolution();
            return;
        }

        for(int i=0;i<N;i++){
            if(cols[i]==false && ndiag[i+row]==false && rdiag[row-i+N-1]==false){
                board[row][i]=1;
                cols[i]=true;
                ndiag[i+row]=true;
                rdiag[row-i+N-1]=true;
                branch$bound(row+1);
                board[row][i]=0;  //no solution backtrack
                cols[i]=false;
                ndiag[i+row]=false;
                rdiag[row-i+N-1]=false;
            }
        }
    }
    
};  

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;

    NQueen q(n);
    int c=0;
    do{
        cout<<"----Menu-----"<<endl;
        cout<<"1.Branch and Bound"<<endl;
        cout<<"2.Backtracking"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"\nEnter choice:";
        cin>>c;
        
        if(c==1){
            q.branch$bound(0);
            if(q.flag==false){
                cout<<"Solution does not exist"<<endl;
            }
        }
        else if(c==2){
            q.solveNQ();
        }
        else{
            cout<<"Exit"<<endl;
        }
    }
    while(c<3);

    return 0;
}
