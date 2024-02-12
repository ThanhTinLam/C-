#include <stdexcept>
#include <iostream>

using std::cout, std::cin, std::invalid_argument, std::overflow_error;


int Largest(int a, int b, int c) {
    int d = a;
    if (a >= d) {
        d = a;
    }
    if (b >= d) {
        d = b;
    }
    if (c >= d) {
        d = c;
    }
    return d;
}

bool SumIsEven(int a, int b) {
    int sum;
    sum = a + b;
    if (sum % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

int BoxesNeeded(int apples) {

    if (apples <= 0) {
        return 0;
    }

    int box = apples / 20;

    if (apples % 20 == 0) {
        return box;
    }
    return box + 1;
}


bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {
    /*return A_correct/A_total >= B_correct/B_total*/
    double A_percent;
    double B_percent;
    double A_new = A_correct;
    double B_new = B_correct;
    double A_tot_new = A_total;
    double B_tot_new = B_total;

    if (A_new < 0 || B_new < 0 || A_tot_new < 0 || B_tot_new < 0) {
        throw invalid_argument("Invalid argument.");
    }
    if (A_new > A_tot_new || B_new > B_tot_new) {
        throw invalid_argument("Invalid argument.");
    }
    A_percent = A_new / A_tot_new;
    B_percent = B_new / B_tot_new;
    if (A_percent > B_percent) {
        return true;
    } else {
        return false;
    }
}


bool GoodDinner(int pizzas, bool is_weekend) {
    if ((pizzas >= 10 && pizzas <= 20) || (is_weekend && pizzas >= 10)) {
        return true;
    } else {
        return false;
    }
}

int SumBetween(int low, int high) {
    int max = INT32_MAX;
    int min = INT32_MIN;
    int sum = 0;

    if (low > high) {
        throw invalid_argument("Invalid argument.");
    }
    if ((low < min) || (high > max)) {
        throw overflow_error("Overflow error.");
    }
    if((low == 0 && high==max)||(low== min && high == 0)){
        throw overflow_error("Overflow error.");
    }

    if(low == min && high== max){
        return  min;
    }
    if (low == high) {
        return low;
    }
    if (low == -high){
        return 0;
    }
    int new_high = high;
    int new_low = low;

//     -4 -3 -2 -1 0 1 2 3 4

    if (low < 0 && high > 0) {
        if (-low > high) {
            new_high = -high - 1;
            if(new_high == new_low){
                return new_low;
            }
        } else {
            new_low = -low + 1;
            if(new_low > max){
                throw overflow_error("Overflow error.");
            }
            if(new_high == new_low){
                return new_high;
            }
        }
    }

    for (int i = new_low; i <= new_high; i++) {
        if ((sum > max - i && i>0) || (sum < min - i && i <0)) {
            throw overflow_error("Overflow error.");
        }
        sum = sum + i;
    }
    return sum;
}


int Product(int a, int b) {
    int max = INT32_MAX;
    int min = INT32_MIN;

    if (a > max || a < min || b > max || b < min) {
        throw overflow_error("Overflow error.");
    }

    if (a < 0 && b < 0 && (a * b) < 0) {
        throw overflow_error("Overflow error.");
    }
    if (a > 0 && b > 0 && (a * b) < 0) {
        throw overflow_error("Overflow error.");
    }
    if (a <= 0 && b > 0 && (a * b) > 0) {
        throw overflow_error("Overflow error.");
    }
    if (a > 0 && b <= 0 && (a * b) > 0) {
        throw overflow_error("Overflow error.");
    }

    if ((a <0 && b>0 && a*b== min)||(b <0 && a>0 && a*b== min)){
        return min;
    }
    if (a > 0) {
        if (b > max / a) {
            throw overflow_error("Overflow error");
        }
        if (b < min / a) { // a = 5; b =-2
            throw overflow_error("Overflow error");
        }
    }
    if (a < 0) {
        if (b > max / -a) { // b 5 (-a )= 2            a = -10 ; b = -1
            throw overflow_error("Overflow error");
        }
        if (b < min / -a) {
            throw overflow_error("Overflow error");
        }
    }
    return a * b;
}