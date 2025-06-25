#include <iostream>
#include <string>
using namespace std;

string xor1(const string &a,const string &b){
    string result;
     for (int i = 1; i < b.length(); i++)
        result += (a[i] == b[i]) ? '0' : '1';
    return result;
}


string mod2div(string dividend, const string& divisor) {

    int pick=divisor.length();
    string tmp=dividend.substr(0,pick);
    while(pick< dividend.length()){
        tmp=(tmp[0]=='1')? xor1(divisor,tmp): xor1(string(tmp.length(),'0'),tmp);
        tmp+=dividend[pick++];
    }
    tmp=(tmp[0]=='1')? xor1(divisor,tmp): xor1(string(tmp.length(),'0'),tmp);
    return tmp;
}

void transmitter() {
    string data, key;
    cout << "Enter data: "; cin >> data;
    cout << "Enter key: ";  cin >> key;

    string appended= data + string(key.length()-1,'0');
    string rem=mod2div(appended,key);
    cout << "Transmitted: " << data + rem << "\n";
}


void receiver() {
    string recv, key;
    cout << "Received: "; cin >> recv;
    cout << "Key: ";      cin >> key;

    string rem=mod2div(recv,key);
    if (rem.find('1') == string::npos) {
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