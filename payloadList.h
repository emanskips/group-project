#ifndef payloadList_h
#define payloadList_h

#include "client.h"

class payloadList{
    public:
    payloadList();
    ~payloadList();

    client* GetContent();
    void SetContents(client* p);

    payloadList* GetNext();
    void SetNext(payloadList* n);

    payloadList* GetHead();

    void push(client* p);
    void del(int id);
    void sort();

    bool hasNext();
    client* search(int id);

    private:
    client* ptr;
    payloadList* newElement;
    payloadList* next;
    payloadList* head;
};

#endif