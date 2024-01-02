#include <iostream>
using namespace std;

//2D Array 8 Queens Problem with Backtracking 

int main() {

    int b[8][8] = {0};
    int row = 0;
    int col = 0; 
    int solutionNum = 1; 
    b[0][0] = 1; // or we can do b[row][col] = 1; 

Nc:
    col++; //increment to next column 
    if (col == 8) goto print; //position check to see if the col == 8 - means we have a solution so we print
    row = -1; 

Nr:
    row++; //incrment to next row 
    if (row == 8) goto backtrack; //position check 

    //Row test
    for (int i = 0; i < col; i++)
        if (b[row][i] == 1) goto Nr;

    // Up diagonal test
    for (int i = 1; (row - i) >= 0 && (col - i) >= 0; i++) 
        if (b[row - i][col - i] == 1) goto Nr;

    // Down diagonal test
    for (int i = 1; (row + i) < 8 && (col - i) >= 0; i++) 
        if (b[row + i][col - i] == 1) goto Nr;

    b[row][col] = 1;
    goto Nc;

backtrack:
    col--; //decrement column  - allows us to go back 
    if (col == -1) return 0; //position check 
    row = 0; 
    while (b[row][col] != 1){ //keeps iterating to the next row until the queen is found 
    row++;
    
    }
      b[row][col] = 0;
        goto Nr;  

print:
    cout << "Solution #:" << solutionNum++ << endl; //print out the solution # 
    for (int a = 0; a < 8; a++) { //nested for loop to print out the chess board 
        for (int d = 0; d < 8; d++) { 
            cout << b[a][d] << " ";
        }
        cout << endl;
    }
    goto backtrack; //finds the next solution 

    return 0; 
}
