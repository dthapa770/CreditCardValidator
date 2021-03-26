// CardValidator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include<string>;
using namespace std;

bool isvalidcc(const string&);
bool cardValidator(const string&);
int sumOfDoubleEvenDigits(const string&);
int sumOfOddDigits(const string&);

bool isvalidcc(const string& cardNumbers) {
    if (cardValidator(cardNumbers)) {
        return ((sumOfDoubleEvenDigits(cardNumbers) + sumOfOddDigits(cardNumbers)) % 10 == 0);
    }
    else {
        return false;
    }

}

bool cardValidator(const string& cardNumbers) {

    if ((cardNumbers[0] == '4' || cardNumbers[0] == '3' && cardNumbers[1] == '7' || cardNumbers[0] == '5' || cardNumbers[0] == '6')
        && (cardNumbers.size() >= 13 && cardNumbers.size() <= 17))
        return true;
    else {
        return false;
    }
}

int sumOfDoubleEvenDigits(const string& cardNumbers) {

    int lengthOfCardNumber = cardNumbers.size();
    int sum = 0;

    for (int i = lengthOfCardNumber - 2; i >= 0; i = i - 2) {
        int number = stoi(cardNumbers.substr(i, 1)) * 2;

        if (number > 9) {
            number = number % 10 + number / 10;
        }
        sum += number;
    }
    return sum;
}

int sumOfOddDigits(const string& cardNumbers) {
    int lengthOfCardNumber = cardNumbers.size();
    int sum = 0;

    for (int i = lengthOfCardNumber - 1; i >= 0; i = i - 2) {
        int number = stoi(cardNumbers.substr(i, 1));
        sum += number;
    }
    return sum;
}

int main()
{
    //
    // PLEASE DO NOT CHANGE function main
    //
    vector<string> cardnumbers = {
            "371449635398431", "4444444444444448", "4444424444444440", "4110144110144115",
            "4114360123456785", "4061724061724061", "5500005555555559", "5115915115915118",
            "5555555555555557", "6011016011016011", "372449635398431", "4444544444444448",
            "4444434444444440", "4110145110144115", "4124360123456785", "4062724061724061",
            "5501005555555559", "5125915115915118", "5556555555555557", "6011116011016011",
            "372449635397431", "4444544444444448", "4444434444544440", "4110145110184115",
            "4124360123457785", "4062724061724061", "5541005555555559", "5125115115915118",
            "5556551555555557", "6011316011016011"
    };

    int i;
    vector<string>::iterator itr;

    for (i = 1, itr = cardnumbers.begin(); itr != cardnumbers.end(); ++itr, i++) {
        cout << setw(2) << i << " "
            << setw(17) << *itr
            << ((isvalidcc(*itr)) ? " is valid" : " is not valid") << endl;
    }

    return 0;
}
