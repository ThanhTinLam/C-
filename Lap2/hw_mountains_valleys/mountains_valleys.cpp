#include <iostream>
#include "functions.h"

using std::cout, std::cin, std::endl;

int main() {
	// TODO(student): print prompt for input
	int a;
    int b;
    cout << "Enter numbers 10 <= a <= b < 10000: ";
    cin >> a >> b ;

	// TODO(student): read the numbers from standard input
    bool x = is_valid_range(a,b);
	// TODO(student): validate input (and reprompt on invalid input)
    while (!x){
        cout << "Invalid Input" << endl;
        cout << "Enter numbers 10 <= a <= b < 10000: ";
        cin >> a >> b;
        x = is_valid_range(a,b);
    }
	// TODO(student): compute and display solution
    if (x){
        count_valid_mv_numbers(int (a), int (b));
    }
	return 0;
}