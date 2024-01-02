//Project 9 - Towers of Hanoi 
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> t[3]; // Three towers A, B, C represented as an array of 3 vectors
    int n, candidate, to, from, move = 0; // move counts the move number
    
    cout << "Please enter an ODD number of rings to move: "; //display message to the screen so the user can enter a number 
    cin >> n; 
    cout << endl;
    
    // Initialize the 3 towers
    for(int i = n + 1; i >= 1; i--)
        t[0].push_back(i); //Push each ring onto the first tower (tower A)
    
    t[1].push_back(n + 1); //Add a placeholder ring to tower B
    t[2].push_back(n + 1); //Add a placeholder ring to tower C
    
    // Initialize towers and candidate
    from = 0;
    to = 1; 
    candidate = 1;
    
    // Determine the initial "to" tower based on the parity of n
    if((n % 2) == 1)
        to = 1;
    else
        to = 2;
    
    // Continue moving rings until tower B contains all the rings
    while(t[1].size() < n + 1){ // There are still rings to transfer to tower B = t[1]
        // Output the move information
        cout << "Move number " << ++move << ": \n Transfer ring " << candidate << " from tower " << char(from + 65) << " to tower " << char(to + 65) << endl << endl;
        
        // Move the disks around
        // 1. Push the top of the “from” tower to the “to” tower
        t[to].push_back(t[from].back());
        // 2. Remove the ring from the “from” tower
        t[from].pop_back();
        
        // Get the next “from tower” 
        if((n % 2) == 1){
            if(t[(to + 1) % 3].back() < t[(to + 2) % 3].back()) 
                from = (to + 1) % 3;
            else
                from = (to + 2) % 3;
            
            // Get next “to tower”
            if(t[from].back() < t[(from + 1) % 3].back())
                to = (from + 1) % 3;
            else
                to = (from + 2) % 3;
            
            // Get next candidate
            candidate = t[from].back(); // It’s on the top of the current “from tower”
        }
        else {
            if(t[(to + 1) % 3].back() < t[(to + 2) % 3].back())
                from = (to + 1) % 3;
        
            else
                from = (to + 2) % 3;
            
            // Get next “to tower”
            if(t[from].back() < t[(from + 2) % 3].back())
                to = (from + 2) % 3;
            else
                to = (from + 1) % 3;
            
            // Get next candidate
            candidate = t[from].back(); // It’s on the top of the current “from tower”
        }
    }
  
    return 0; 
}

    
    
  




