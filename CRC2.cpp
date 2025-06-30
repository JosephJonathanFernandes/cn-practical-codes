#include <iostream>
#include <string>
using namespace std;

string xor1(const string &a,const string &b ){
    string result;
    for(int i=1;i<b.length();i++){ //dont forget it starts from here
       result+=(a[i]==b[i])?'0':'1';
    }
    return result;
}

string mod2div(string dividend, const string& divisor) {

int pick=divisor.length();
string tmp=dividend.substr(0,pick);
while(pick<dividend.length()){
     tmp=(tmp[0]=='1')?xor1(divisor,tmp):xor1(string(tmp.length(),'0'),tmp);
     tmp+=dividend[pick++];
}
tmp=(tmp[0]=='1')?xor1(divisor,tmp):xor1(string(tmp.length(),'0'),tmp);
return tmp;

}

string getKey() {
    int keyChoice;
    cout << "Select CRC Polynomial:\n";
    cout << "1. CRC-12 (1100000001111)\n";
    cout << "2. CRC-16 (11000000000000101)\n";
    cout << "3. Custom\n";
    cout << "Choice: ";
    cin >> keyChoice;

    if (keyChoice==1) 
    return "1100000001111";
    else if (keyChoice==2) 
    return "11000000000000101";
else {
        string custom;
        cout << "Enter custom key: ";
        cin >> custom;
        return custom;
    }

}



void transmitter(){
    string data,key;
     cout << "Enter data: "; cin >> data;
    key=getKey();

    string appended=data + string(key.length()-1,'0');
    string rem=mod2div(appended,key);
    cout << "Transmitted: " << data + rem << "\n";

}


void receiver() {
    string recv, key;
    cout << "Received: "; cin >> recv;
    key=getKey();

    string rem=mod2div(recv,key);
    if (rem.find('1')==string::npos) {
        cout << " No Error\n";
    } else {
        cout << " Error Detected\n";
    }
}


int main() {
    int ch;
    while (true) {
        cout << "\nCRC Menu\n1. Transmitter\n2. Receiver\n3. Exit\nChoice: ";
        cin >> ch;
        if (ch == 1) transmitter();
        else if (ch == 2) receiver();
        else break;
    }
    return 0;
}