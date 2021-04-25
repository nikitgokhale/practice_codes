#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
int main () {
	double meal_cost = 150.5;
    int tip_percent = 30;
    int tax_percent = 18;
    int finalCost = 0;
    double tip = meal_cost*tip_percent/100;
    cout << tip << endl;
    double tax = meal_cost*tax_percent/100;
    cout << tax << endl;
    finalCost = round(meal_cost + tip + tax);
    cout << finalCost;
    return 0;
}
