// Jonathan Carbonneau
// I pledge my honor that I have abided by the Stevens Honor System
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include <iomanip>
using namespace std;


bool isdouble( string s ) {
    istringstream stringstream(s);
    float nflot;
    return(stringstream >> noskipws >> nflot).eof();
}

double sqrt(double num, double epsilon = 0.0000001)
{

    double last_guess = num;
    double next_guess = (last_guess + num / last_guess) / 2;

    if (num < 0)
    {
        return numeric_limits<double>::quiet_NaN();
    }
    else if (num == 1 || num == 0)
    {
        return num;
    }
    while (!(abs(last_guess - next_guess) <= epsilon))
    {
    	last_guess = next_guess;
        next_guess = (last_guess + num / last_guess) / 2;
    }
    return next_guess;
}

int main(int argc, char *argv[])
{

	 if (argc == 2){
		 if (!(isdouble(argv[1]))){
			 cerr << "Error: Value argument must be a double.";
			 return 0;
		 }
    	cout << fixed << setprecision(8) << sqrt(atof(argv[1]));
    }else if (argc == 3){
    
    	 if (!(isdouble(argv[1]))){
			 cerr << "Error: Value argument must be a double.";
			 return 0;
	 }else if (!(isdouble(argv[2])) || atof(argv[2]) <= 0 ){
			 cerr << "Error: Epsilon argument must be a positive double.";
			 return 0;
		 }
		 
    	cout << fixed << setprecision(8) << sqrt(atof(argv[1]), atof(argv[2]));
    }else{
        cerr << "Usage: ./sqrt <value> [epsilon]";
        return 1;
    }

    return 0;
}

