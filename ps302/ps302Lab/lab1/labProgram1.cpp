#include <iostream>
#include<string>
#include <math.h>
#include <fstream>
using namespace std;

bool checkNumber(string str) {
    for(int i=0; i<str.length(); i++) {
        if(isdigit(str[i]) == false) {
            return false;
        }
    }
    return true;
}

int main()
{
    int numOfSamplePoints = 0;
    string radius = "";
    int radint;
    cout << "Enter the radius:";
    cin >> radius;
    if(checkNumber(radius) == false) {
        cout << "Please enter a 3 digit positive radius";
        exit(0);
    }
    else {
        radius.erase(0, radius.find_first_not_of('0'));
        if(radius.length() > 3) {
            cout << "Radius has to be a 3 digit positive integer";
            exit(0);
        } else {
            radint = stoi(radius);
            cout << radint << endl;
        }
    }
    ofstream outputFile;
    outputFile.open("output.txt", ios::app);
    outputFile << "\nradius is " << radius;
    for(int i=1; i<=radint; i++) {
        for(int j=1; j<=i && j*j<= radint*radint - i*i; j++ ) {
            outputFile << '(' << i << ',' << j << ')' << " ";
            cout << '(' << i << ',' << j << ')' << " ";
            if(i!=j) {
                 cout << '(' << j << ',' << i << ')' << " ";
                 outputFile << '(' << j << ',' << i << ')' << " ";
                 numOfSamplePoints += 1;
            }

            numOfSamplePoints += 1;
        } 
        outputFile << "\n";
        cout << endl;
    }
    outputFile << "Number of sample points = " << numOfSamplePoints << "\n";
    cout << "Number of Sample points = " << numOfSamplePoints << endl;
}