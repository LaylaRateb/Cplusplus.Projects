//Integration

#include <iostream>
#include <cmath> 
using namespace std;

typedef double (*FUNC)(double);  //declares a pointer 'Func' that points to a function that takes a double and returns a double. 

double integrate(FUNC f, double a, double b) {  //the integration function  (uses midpoint riemann sum)
   double sum = 0; 
   for(double i = a; i < b; i += 0.0001){
       sum += f(i) * 0.0001;
   }
   return sum;  // returns the integral back to the main function. 
}

double line(double x){      //this represents f(x) = x
   return x;
}

double square(double x){    //this represents f(x) = x^2
   return x*x;
}

double cube(double x){      //this represents f(x) = x^3
   return x*x*x;
}

double root(double x){     // this represents f(x) = sqrt(x)
   return sqrt(x);
}

int main() {
   cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;     // 12
   cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl; // 41.3333
   cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;   // 156
   cout << "The integral of f(x)= sqrt(x) between 1 and 5 is: " << integrate(root, 1, 5) << endl; //6.78689
   return 0;
}
