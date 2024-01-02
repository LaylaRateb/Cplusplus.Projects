//Layla Rateb
//Project 8 - Fancy Queens 
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

bool ok(int q[], int c){
	for(int i=0;i<c;i++){
		//Check if queens are in the same row or diagonally aligned
		if((q[c]==q[i])||((c-i)==(abs(q[c]-q[i])))){
		return false;
		}
	}
		return true;
}

//Create a function to backtrack and move to the previous column
void backtrack(int &c){
	c--; //decrement the column index
	if(c==-1)exit(1);//If c becomes -1, exit the program
}
void print(int q[]){
	static int count=0; //crete static variable to keep track of the number of solutions
 	count++; // increment the solution count
	cout<<"solution# "<<count<<":"<<endl; // display the solution number to the screen
	//8 queens solution
	for(int i=0;i<8;i++){
		cout<<q[i]<<" ";
	}
	cout<<endl<<endl;
	//fancy chessboard code
	typedef char box[5][7]; //a 5x7 2D array of characers 
	box bb,wb,wq,bq,*board[8][8];
	//fills in the wb & bb arrays
	for(int r=0;r<5;r++){
		for(int c=0;c<7;c++){
			wb[r][c]=' ';
			bb[r][c]=char(219);
		}
	}
	//fil in array for wq
	for(int r=0;r<5;r++){
		for(int c=0;c<7;c++){
			wq[r][c]=' ';
			
		}
	}
	// Set specific positions in the array to char(219) to create the shape of the white queen.
	// char(219) represents a filled block or character in the extended ASCII character set.

	wq[1][1] = char(219); // Filled block in row 1, column 1
	wq[2][1] = char(219); // Filled block in row 2, column 1
	wq[3][1] = char(219); // Filled block in row 3, column 1
	wq[3][2] = char(219); // Filled block in row 3, column 2
	wq[1][3] = char(219); // Filled block in row 1, column 3
	wq[2][3] = char(219); // Filled block in row 2, column 3
	wq[3][3] = char(219); // Filled block in row 3, column 3
	wq[3][4] = char(219); // Filled block in row 3, column 4
	wq[1][5] = char(219); // Filled block in row 1, column 5
	wq[2][5] = char(219); // Filled block in row 2, column 5
	wq[3][5] = char(219); // Filled block in row 3, column 5

// Fill in array for black queen (bq)
for (int r = 0; r < 5; r++) {
    for (int c = 0; c < 7; c++) {
        bq[r][c] = char(219); // Set all positions in the array to char(219) to create the shape of the black queen.
    }
}
	// Initialize the black queen (bq) array to represent the shape of a black queen.
	// The ' ' (space) character is used for empty spaces.

	bq[1][1] = ' '; // Empty space in row 1, column 1
	bq[2][1] = ' '; // Empty space in row 2, column 1
	bq[3][1] = ' '; // Empty space in row 3, column 1
	bq[3][2] = ' '; // Empty space in row 3, column 2
	bq[1][3] = ' '; // Empty space in row 1, column 3
	bq[2][3] = ' '; // Empty space in row 2, column 3
	bq[3][3] = ' '; // Empty space in row 3, column 3
	bq[3][4] = ' '; // Empty space in row 3, column 4
	bq[1][5] = ' '; // Empty space in row 1, column 5
	bq[2][5] = ' '; // Empty space in row 2, column 5
	bq[3][5] = ' '; // Empty space in row 3, column 5
	
	//fill board with alternating wb/wq and bb/bq arrays
	
	for (int r = 0; r < 8; r++) { // Loop through each row
    for (int c = 0; c < 8; c++) { // Loop through each column
        if ((r + c) % 2 == 0) { // Check if the sum of row and column indices is even - white square
            if (q[c] == r) { // If there is a queen in this column at the current row
                board[r][c] = &wq; // Place a white queen on the white square
            } else {
                board[r][c] = &wb; 
            }
        } else { // If the sum of row and column indices is odd (black square)
            if (q[c] == r) { //checks if there is a queen in this column at the current row
                board[r][c] = &bq; // Place a black queen on the black square
            } else {
                board[r][c] = &bb; // Otherwise, place a black square
            }
        }
    }
}
// Print the upper border of the chessboard.
cout << " ";
for (int i = 0; i < 7 * 8; i++) {
    cout << '_';
}
cout << endl;

// Print the chessboard.
for (int r = 0; r < 8; r++) {
    // Loop through each row of the individual boxes (5 rows).
    for (int i = 0; i < 5; i++) {
        // Print the left border of the chessboard.
        cout << " " << char(179);

        // Loop through each column of the chessboard 8 columns.
        for (int c = 0; c < 8; c++) {
            // Loop through each character in the specific box of the chessboard.
            for (int j = 0; j < 7; j++) {
                // Print the character at position (i, j) in the box located at position (r, c) on the chessboard.
                cout << (*board[r][c])[i][j];
            }
        }

        // Print the right border of the chessboard and move to the next line.
        cout << char(179) << endl;
    }
}
	//lower boarder
	cout << " ";
	for(int i=0;i<7*8;i++){
		cout<<char(196);
	}
	cout<<endl; 
	
}

int main() { 
 
    int q[8]; //initalize array to store the positions of queens in each column
    q[0] = 0; //initialize the first queen's position in the first column
    int c = 1; 
    bool from_backtrack = false; 

    while (1) { 
        while (c < 8) { // Loop through each column
            if (!from_backtrack)
                q[c] = -1; // Initialize the queen's position in the current column if not backtracking
            from_backtrack = false; // Reset the backtracking flag

            while (q[c] < 8) { // Loop through possible positions for the queen in the current column
                q[c]++; // Move to the next possible position
                while (q[c] == 8) { // If the queen has reached the end of the column
                    backtrack(c); // Backtrack to the previous column
                    q[c]++; // Move to the next position in the current column
                }
                if (ok(q, c)) { // If the current position is valid (no conflicts with existing queens)
                    break; // Exit the loop and move to the next column
                }
            }
            c++; // Move to the next column
        }

        print(q); // Print the current solution
        backtrack(c); // Backtrack to explore more solutions
        from_backtrack = true; // Set the backtracking flag
    }

    return 0; 
}