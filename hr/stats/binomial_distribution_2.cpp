#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

// n!
int fact(int n) {
    return (n == 0) ? 1 : n * fact(n-1);
}

// nCx ==> choose 'x' samples from 'n' items.
// n ==> Total number of items.
// x ==> Number of samples to be choosen.
// Returns total number of possible combinations.
int comb(int n, int x) {    
    if(n > x) return 0; // error!
    if(n == x || x == 0) return 1;
    return fact(n) / (fact(x) * fact(n-x));
}

// Binomial coefficient for 'x' successes out of 'n' trials
// with 'p' probabiity of success.
// n ==> Total number of trials.
// x ==> Number of successes required.
// p ==> Probability of success on 1 trial.
// Returns probability of 'x' success in 'n' trials.
double binomial(int n, int x, double p) {
    return comb(n, x) * pow(p, x) * pow(1-p, n-x);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  

    double rejects = 0.12;
    int batch_size = 10;

    // No more than 2 rejects = b0 + b1 + b2
    // At least 2 rejects = b2 + b3 + b4 .. b10 = 1 - (b0 + b1)

    double b0 = binomial(batch_size, 0, rejects);
    double b1 = binomial(batch_size, 1, rejects);
    double b2 = binomial(batch_size, 2, rejects);

    double no_more_than_2 = (b0 + b1 + b2);
    double at_least_2 = 1 - (b0 + b1);

    cout << fixed << setprecision(3);
    cout << no_more_than_2 << endl;
    cout << at_least_2;



    return 0;
}
