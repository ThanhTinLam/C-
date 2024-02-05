#include <iostream>
#include <iomanip>
#include <cstring>
#include "parallel_tracks.h"

using std::cin, std::cout, std::endl;

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an array of doubles is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
    //TODO
    for (unsigned int i = 0; i < SIZE; ++i) {
        ary[i] = 0.0;
    }
}

//-------------------------------------------------------
// Name: prep_unsigned_int_array
// PreCondition:  an array of unsigned ints is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
    //TODO
    for (unsigned int i = 0; i < SIZE; ++i) {
        ary[i] = 0;
    }
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  an array of strings is passed in
// PostCondition: each element in the array is set to "N/A"
//---------------------------------------------------------
void prep_string_array(char ary[][STRING_SIZE])
// making sure all values within the array are set to "N/A";
{
    //TODO
    for (unsigned int i = 0; i < SIZE; i++) {
        std::strcpy(ary[i], "N/A");
    }
}

//-------------------------------------------------------
// Name: trim
// PreCondition:  the cstring
// PostCondition: whitespace has been removed from beginning and end of string
//---------------------------------------------------------
void trim(char str[STRING_SIZE]) {
    // TODO
    std::string strStr = str;
    size_t first = strStr.find_first_not_of(" \t\n");
    size_t last = strStr.find_last_not_of(" \t\n");

    if (first == std::string::npos) {
        str[0] = '\0';
    } else {
        strStr = strStr.substr(first, (last - first + 1));
        std::strcpy(str, strStr.c_str());
    }
}

bool is_valid_number(const std::string &str) {
    int count = 0;
    int val = str.size();

    if (val > 2) {
        return false;
    }
    if (str == "") {
        count += 1;
    }
    for (int j = 0; j < val; ++j) {
        if (isdigit(str.at(j))) {
        } else {
            count += 1;
        }
    }
    if (count != 0) {
        return false;
    } else {
        return true;
    }
}


bool is_valid_time(const std::string &str) {
    int count = 0;
    int count1 = 0;
    int val = str.size();

    for (int j = 0; j < val; ++j) {
        if (isdigit(str.at(j))) {
        } else if (str.at(j) == '.') {
            count1 += 1;
        } else {
            count += 1;
        }
    }

    if (count != 0 || count1 > 1) {
        return false;
    }

    if (str == ".") {
        return false;
    } else {
        return true;
    }
}

bool is_valid_country(const std::string &str) {
    int countNonUppercase = 0;
    int val = str.size();

    if (str.size() != 3) {
        countNonUppercase += 1;
    }
    for (int j = 0; j < val; ++j) {
        if (isupper(str.at(j))) {

        } else {
            countNonUppercase += 1;
        }
    }
    if (countNonUppercase != 0) {
        return false;
    } else {
        return true;
    }
}

bool is_valid_name(const std::string &str) {
    if (str.empty()) {
        return false;
    }

    char strCharArray[STRING_SIZE];
    strcpy(strCharArray, str.c_str());

    trim(strCharArray);
    int c = sizeof(strCharArray);
    int j = 0;
    for (j = 0; j < c; ++j) {
        if (strCharArray[j] == '\0') {
            break;
        }
        if (!(isalpha(strCharArray[j]) || strCharArray[j] == ' ')) {
            return false;
        }
    }
    if ( j < 2) {
        return false;
    }
    return true;
}

//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays
// PostCondition: all arrays contain data from standard in
//---------------------------------------------------------
bool get_runner_data(double timeArray[], char countryArray[][STRING_SIZE],
                     unsigned int numberArray[], char lastnameArray[][STRING_SIZE]) {

    //TODO

    for (unsigned int i = 0; i < SIZE; i++) {
        // Read time, country, number, and lastname data
        cin >> timeArray[i];
        cin.ignore();
        if (!is_valid_time(std::to_string(timeArray[i]))) {
            return false;
        }
        cin >> countryArray[i];
        cin.ignore();
        if (!is_valid_country(countryArray[i])) {
            return false;
        }

        cin >> numberArray[i];
        cin.ignore();
        if (!is_valid_number(std::to_string(numberArray[i]))) {
            return false;
        }

        cin >> lastnameArray[i];
        cin.ignore();
        if (!is_valid_name(lastnameArray[i])) {
            return false;
        }
    }
    return true; // set so it will compile
}

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[]) {
    //TODO
    double timeCopy[9];
    for (int i = 0; i < 9; ++i) {
        timeCopy[i] = timeArray[i];
    }
    double minValue = 99999;
    int minIndex;
    for (int i = 1; i < 10; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (timeCopy[j] < minValue) {
                minValue = timeCopy[j];
                minIndex = j;
            } else {
                minValue = minValue;
            }
        }
        timeCopy[minIndex] = 99999;
        minValue = 99999;
        rankArray[minIndex] = i;
    }

}


//-------------------------------------------------------
// Name: print_results
// PreCondition:  all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays them along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const char countryArray[][STRING_SIZE],
                   const char lastnameArray[][STRING_SIZE], const unsigned int rankArray[]) {

    std::cout << "Final results!!";
    std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
    double best_time = 0.0;

    // print the results, based on rank, but measure the time difference_type
    for (unsigned int j = 1; j <= SIZE; j++) {

        // go thru each array, find who places in "i" spot
        for (unsigned int i = 0; i < SIZE; i++) {
            if (rankArray[i] == 1) // has to be a better way, but need the starting time
            {
                best_time = timeArray[i];
            }


            if (rankArray[i] == j) // then display this person's data
            {
                // this needs precision display
                std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i]
                          << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl;
            }

        }
    }
}