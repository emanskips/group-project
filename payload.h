#ifndef payload_h
#define payload_h

using namespace std;
#include <string>

class payload{
    public:
    payload(string n, float b, int i);
    payload(string n, int i);

    string GetName();
    float GetBal();
    int GetID();

    void SetName(string n);
    void SetBal(float g);
    void SetID(int i);

    private:
    string name;
    float balance;
    int accId;
};

#endif