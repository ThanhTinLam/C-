# include "functions.h"
// add any includes

using std::cout, std::cin, std::endl, std::string;

void deobfuscate() {

    std::string t, t1, t2;
    std::string len;

    std::cout << "Please enter obfuscated sentence: ";
    std::cin >> t;

    std::cout << "Please enter deobfuscation details: ";
    std::cin >> len;

    int count = 0;

    int d = len.length();

    //for (char c: len) {
    for(int i = 0; i< d; i++){
        char c = len[i];
        count += static_cast<int>(c - '0');
        t1 = t.substr(0, count);
        t2 = t.substr(count);
        t = t1 + " " + t2;
        count++;
    }

    std::cout << "Deobfuscated sentence: " << t << std::endl;
}


void wordFilter() {
    string text;
    string hash;
    cout << "Please enter the sentence: ";
    getline(cin, text);

    cout << "Please enter the filter word: ";
    cin >> hash;
    size_t a = text.find(hash);
    while (a != string::npos) {
        size_t b = hash.length();
        text.replace(a, hash.length(), b,'#');
        a = text.find(hash, a + b);
    }
    cout << "Filtered sentence: " << text << endl;
}

void passwordConverter() {

//    string pass;
//    char a = 'a', e = 'e', i ='i', o = 'o', u = 'u';
//    char at = '@', three = '3', exclamation = '!', zero = '0', hat = '^';
//
//    cout << "Please enter the pastword: ";
//    getline(cin,pass);
//
//    size_t pos1 = pass.find(a);
//    size_t pos2 = pass.find(e);
//    size_t pos3 = pass.find(i);
//    size_t pos4 = pass.find(o);
//    size_t pos5 = pass.find(u);
//
//    while(pos1 != string::npos ){
//        pass.replace(pos1,1,1,at);
//        pos1 = pass.find(a, pos1+1);
//    }
//    while(pos2 != string::npos ){
//        pass.replace(pos2,1,1,three);
//        pos2 = pass.find(e, pos2+1);
//    }
//    while(pos3 != string::npos ){
//        pass.replace(pos3,1,1,exclamation);
//        pos3 = pass.find(i, pos3+1);
//    }
//    while(pos4 != string::npos ){
//        pass.replace(pos4,1,1,zero);
//        pos4 = pass.find(o, pos4+1);
//    }
//    while(pos5 != string::npos ){
//        pass.replace(pos5,1,1,hat);
//        pos5 = pass.find(u, pos5+1);
//    }
//    string new_pass;
//    int len = pass.length();
//    for(int i = len -1; i>=0; i--){
//        new_pass += pass[i];
//    }
//    cout << pass << " "<< new_pass<< endl;
//}

string input;

cout << "Please enter your text input: input: ";
getline(cin, input);

const int size = 5;
char values_to_replace[size] = {'a', 'e', 'i', 'o', 'u'};
char values_replace_with[size] = {'@', '3', '!', '0', '^'};

for (int i = 0; i < static_cast<int>(input.length()); i++) {
for (int j = 0; j < size; j++) {
if (input[i] == values_to_replace[j]) {
input[i] = values_replace_with[j];
}
}
}

string reversed_string = input;
for (int i = 0; i < static_cast<int>(input.length()); i++) {
reversed_string[i] = input[input.length() - i - 1];
}
cout << "\noutput: " << input + reversed_string << endl;
}


void wordCalculator() {
    string word;
    cout << "Please enter the password: ";
    getline(cin,word);

    string num_literal[9]  = {"one", "two",  "three",  "four",  "five",  "six",  "seven", "eight", "night"};
    string num_sign[4] = {"time","plus", "minus","divide"};
    char sign[4] = {'*', '+', '-', '/'};
    char number[9] = {'1','2','3','4','5','6','7','8','9'};

    int len = word.length();

    for(int i=0; i<len;i++){
        for(int j=0; j<9;j++){
            size_t pos1 =
        }
    }
}

void palindromeCounter() {
    string  s;

    cout << "Enter a string: ";
    getline(cin,s);

    string p = s;

    reverse(p.begin(),p.end());
    if(s==p){
        cout << "yes";
    }else{
        cout<< "no";
    }
}