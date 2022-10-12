#include "payload.h"
using namespace std;

payload::payload(string n, float b, int i){
    name = n;
    balance = b;
    accId = i;
}

payload::payload(string n, int i){
    name = n;
    balance = 0;
    accId = i;
}

string payload::GetName() { return name; }
float payload::GetBal() { return balance; }
int payload::GetID() { return accId; }

void payload::SetName(string n) { name = n; }
void payload::SetBal(float g) { balance = g; }
void payload::SetID(int i) { accId = i; }