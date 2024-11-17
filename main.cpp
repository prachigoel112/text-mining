#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("sample.txt", ios::in);
    ofstream foutwords("words.txt", ios::out);
    ofstream foutnumbers("numbers.txt", ios::out);
    ofstream foutmixed("mixed.txt", ios::out);
    ofstream foutspecial("special.txt", ios::out);
    ofstream foutcapital("capital.txt", ios::out);
    char ch;
    char word[50];
    int index = 0;
    int numcount = 0, lettercount = 0;
    while (fin.get(ch)) {
        if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            word[index++] = ch;
            if (ch >= '0' && ch <= '9') numcount++;
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) lettercount++;
        } else {
            if (index > 0) {
                word[index] = '\0';
                if (numcount > 0 && lettercount > 0) {
                    foutmixed << word << "\n";
                } else if (numcount > 0) {
                    foutnumbers << word << "\n";
                } else if (lettercount > 0) {
                    if (word[0] >= 'A' && word[0] <= 'Z') {
                        foutcapital << word << "\n";
                    } else {
                        foutwords << word << "\n";
                    }
                }
                index = 0;
                numcount = 0;
                lettercount = 0;
            }
            if (!isalnum(ch)) {
                foutspecial << ch << "\n";
            }
        }
    }
    fin.close();
    foutwords.close();
    foutnumbers.close();
    foutmixed.close();
    foutspecial.close();
    foutcapital.close();
}
