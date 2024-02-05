#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
    // TODO(student): validate input range
    if ((9 < a) && (a < 10000) && (9 < b) && (b < 10000) && (a <= b)) {
        return true;
    }
    return false;
}

char classify_mv_range_type(int number) {
    // TODO(student): return 'M' if number has /\/\... pattern,
    // return 'V' if number has \/\/ pattern, and return 'N' otherwise
    if ((number < 100) && (number >= 10)) {
        int d1 = number / 10;
        int d2 = number % 10;
        if (d1 < d2) {
            return 'M';
        } else if (d1 > d2) {
            return 'V';
        }
    } else if ((number < 1000) && (number >= 100)) {
        int d1 = number / 100;
        int d2 = (number % 100) / 10;
        int d3 = (number % 10);
        if ((d1 < d2) && (d2 > d3)) {
            return 'M';
        } else if ((d1 > d2) && (d2 < d3)) {
            return 'V';
        }
    } else if ((number < 10000) && (number >= 1000)) {
        int d1 = number / 1000;
        int d2 = (number % 1000) / 100;
        int d3 = (number % 100) / 10;
        int d4 = (number % 10);
        if ((d1 < d2) && (d2 > d3) && (d3 < d4)) {
            return 'M';
        } else if ((d1 > d2) && (d2 < d3) && (d3 > d4)) {
            return 'V';
        }
    } else if ((number < 100000) && (number >= 10000)) {
        int d1 = number / 10000;
        int d2 = (number % 10000) / 1000;
        int d3 = (number % 1000) / 100;
        int d4 = (number % 100) / 10;
        int d5 = (number % 10);
        if ((d1 < d2) && (d2 > d3) && (d3 < d4) && (d4 > d5)) {
            return 'M';
        } else if ((d1 > d2) && (d2 < d3) && (d3 > d4) && (d4 < d5)) {
            return 'V';
        }
    } else if ((number < 1000000) && (number >= 100000)) {
        int d1 = number / 100000;
        int d2 = (number % 100000) / 10000;
        int d3 = (number % 10000) / 1000;
        int d4 = (number % 1000) / 100;
        int d5 = (number % 100) / 10;
        int d6 = (number % 10);
        if ((d1 < d2) && (d2 > d3) && (d3 < d4) && (d4 > d5) && (d5 < d6)) {
            return 'M';
        } else if ((d1 > d2) && (d2 < d3) && (d3 > d4) && (d4 < d5) && (d5 > d6)) {
            return 'V';
        }
    } else if ((number < 10000000) && (number >= 1000000)) {
        int d1 = number / 1000000;
        int d2 = (number % 1000000) / 100000;
        int d3 = (number % 100000) / 10000;
        int d4 = (number % 10000) / 1000;
        int d5 = (number % 1000) / 100;
        int d6 = (number % 100) / 10;
        int d7 = (number % 10);

        if ((d1 < d2) && (d2 > d3) && (d3 < d4) && (d4 > d5) && (d5 < d6) && (d6 > d7)) {
            return 'M';
        } else if ((d1 > d2) && (d2 < d3) && (d3 > d4) && (d4 < d5) && (d5 > d6) && (d6 < d7)) {
            return 'V';
        }
    } else if ((number < 100000000) && (number >= 10000000)) {
        int d1 = number / 10000000;
        int d2 = (number % 10000000) / 1000000;
        int d3 = (number % 1000000) / 100000;
        int d4 = (number % 100000) / 10000;
        int d5 = (number % 10000) / 1000;
        int d6 = (number % 1000) / 100;
        int d7 = (number % 100) / 10;
        int d8 = (number % 10);

        if ((d1 < d2) && (d2 > d3) && (d3 < d4) && (d4 > d5) && (d5 < d6) && (d6 > d7) && (d7 < d8)) {
            return 'M';
        } else if ((d1 > d2) && (d2 < d3) && (d3 > d4) && (d4 < d5) && (d5 > d6) && (d6 < d7) && (d7 > d8)) {
            return 'V';
        }
    } else if ((number < 1000000000) && (number >= 100000000)) {
        int d1 = number / 100000000;
        int d2 = (number % 100000000) / 10000000;
        int d3 = (number % 10000000) / 1000000;
        int d4 = (number % 1000000) / 100000;
        int d5 = (number % 100000) / 10000;
        int d6 = (number % 10000) / 1000;
        int d7 = (number % 1000) / 100;
        int d8 = (number % 100) / 10;
        int d9 = (number % 10);

        if ((d1 < d2) && (d2 > d3) && (d3 < d4) && (d4 > d5) && (d5 < d6) && (d6 > d7) && (d7 < d8) && (d8 > d9)) {
            return 'M';
        } else if ((d1 > d2) && (d2 < d3) && (d3 > d4) && (d4 < d5) && (d5 > d6) && (d6 < d7) && (d7 > d8) &&
                   (d8 < d9)) {
            return 'V';
        }
    } else if ((number < 2147483647) && (number >= 1000000000)) {
        int d1 = number / 1000000000;
        int d2 = (number % 1000000000) / 100000000;
        int d3 = (number % 100000000) / 10000000;
        int d4 = (number % 10000000) / 1000000;
        int d5 = (number % 1000000) / 100000;
        int d6 = (number % 100000) / 10000;
        int d7 = (number % 10000) / 1000;
        int d8 = (number % 1000) / 100;
        int d9 = (number % 100) / 10;
        int d10 = (number % 10);

        if ((d1 < d2) && (d2 > d3) && (d3 < d4) && (d4 > d5) && (d5 < d6) && (d6 > d7) && (d7 < d8) && (d8 > d9) &&
            (d9 < d10)) {
            return 'M';
        } else if ((d1 > d2) && (d2 < d3) && (d3 > d4) && (d4 < d5) && (d5 > d6) && (d6 < d7) && (d7 > d8) &&
                   (d8 < d9) && (d9 > d10)) {
            return 'V';
        }
    }
    /*else if ((number < 100000000000) && (number >= 10000000000)) {
        int d1 = number / 10000000000;
        int d2 = (number % 10000000000) / 1000000000;
        int d3 = (number % 1000000000) / 100000000;
        int d4 = (number % 100000000) / 10000000;
        int d5 = (number % 10000000) / 1000000;
        int d6 = (number % 1000000) / 100000;
        int d7 = (number % 100000) / 10000;
        int d8 = (number % 10000) / 1000;
        int d9 = (number % 1000) / 100;
        int d10 = (number % 100)/ 10;
        int d11 = (number % 10);

        if ((d1 < d2) && (d2 > d3) && (d3 < d4) && (d4 > d5) && (d5 < d6) && (d6 > d7) && (d7 < d8) && (d8 > d9) &&
            (d9 < d10) && (d10>d11)) {
            return 'M';
        } else if ((d1 > d2) && (d2 < d3) && (d3 > d4) && (d4 < d5) && (d5 > d6) && (d6 < d7) && (d7 > d8) &&
                   (d8 < d9) && (d9 > d10) && (d10<d11)) {
            return 'V';
        }*/

    return 'N';
}

void count_valid_mv_numbers(int a, int b) {
    // TODO(student): count the number of valid mountain ranges and valley
    //  10 <= a <= b < 10000.

    // ranges in the range [a, b] and print out to console using the format
    // in Requirement 4 of the homework prompt
    int mountains = 0;
    int valleys = 0;
    if (a >= 0 && b >= a && b <=  2147483647) {
        for (int i = a; i <= b; i++) {
            char x = classify_mv_range_type(i);
            if (x == 'M') {
                mountains = mountains + 1;

            } else if (x == 'V') {
                valleys = valleys + 1;
            }
        }
    }
    cout << "There are " << mountains << " mountain ranges and " << valleys << " valley ranges between " << a
         << " and " << b << "." << endl;

}
