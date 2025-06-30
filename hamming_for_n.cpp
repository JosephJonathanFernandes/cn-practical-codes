#include <iostream>
#include <cmath>
using namespace std;

bool isPoweroftwo(int x){
    return x && (!(x&x-1));
}


void generateHammingCode(int data[], int m, int code[], int &r){ //r by reference
r=0;

while(pow(2,r)<(m+r+1))
r++;

 int totalbits=m+r;
 int j=0;

 for(int i=1;i<=totalbits;i++){ //start from 1
    if(isPoweroftwo(i)) //ispower func
    code[i]=0;
else
 code[i]=data[j++];
 }

 for(int i=0;i<r;i++){
    int parity=0;
    int pos=pow(2,i);
    for(int j=1;j<=totalbits;j++){ //start from 1
        if(pos&j)
        parity^=code[j];
    }
    code[pos]=parity;
 }

}

void detectAndCorrect(int code[], int totalbits, int r) {
    int error=0;

    for(int i=0;i<r;i++){
    int parity=0;
    int pos=pow(2,i);
    for(int j=1;j<=totalbits;j++){ //starts from1 
        if(pos&j)
        parity^=code[j];
    }
    if(parity)
    error+=pos;
    }

    if (error == 0) {
        cout << "\nNo error detected in received code.\n";
    } else {
        cout << "\nError detected at position: " << error << "\n";
        code[error] ^= 1; // Correct the bit
        cout << "Corrected Hamming code:\n";
        for (int i = totalbits; i >= 1; i--)
            cout << code[i] << " ";
        cout << "\n";
    }

}


int main() {
    int m;
    cout << "Enter number of data bits: ";
    cin >> m;

    int data[50];
    cout << "Enter the data bits (LSB to MSB):\n";
    for (int i = m - 1; i >= 0; i--) {
        cout << "Bit " << i + 1 << ": ";
        cin >> data[i];
    }

    int code[100] ={0};
    int r = 0;
    generateHammingCode(data, m, code, r);

    int totalBits = m + r;

    cout << "\nGenerated Hamming Code (from MSB to LSB):\n";
    for (int i = totalBits; i >= 1; i--)
        cout << code[i] << " ";
    cout << "\n";

    // Simulate receiver
    cout << "\nEnter the received code bits (position 1 to " << totalBits << "):\n";
    for (int i = totalBits; i >= 1; i--) {
        cout << "Bit " << i << ": ";
        cin >> code[i];
    }

    detectAndCorrect(code, totalBits, r);

    return 0;
}