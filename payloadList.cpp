#include "payloadList.h"

payloadList::payloadList() {
    head = this;
    ptr = nullptr;
    next = nullptr;
}
payloadList::~payloadList() {
    ptr = nullptr;
    newElement = nullptr;
    next = nullptr;
    head = nullptr;
    /*
    delete ptr;
    delete newElement;
    delete next;
    delete head;
    */
}

client* payloadList::GetContent() { return ptr; }
void payloadList::SetContents(client* p) { ptr = p; }

payloadList* payloadList::GetNext() { return next; }
void payloadList::SetNext(payloadList* n) { next = n; }

payloadList* payloadList::GetHead() { return head; }

void payloadList::push(client* p) {
    if (ptr == NULL && next == NULL) { ptr = p; return; }
    newElement = new payloadList();
    newElement->SetContents(p);
    newElement->SetNext(head);
    head = newElement;
}

void payloadList::del(int id) {
    if (head->GetContent()->getID() == id) {
        payloadList* nxt = head->GetNext();
        head = nullptr;
        head = nxt;
    }
    else {
        payloadList* prevPtr = head;
        for (payloadList* Pptr = head; Pptr != NULL; Pptr = Pptr->GetNext()) {
            if (Pptr->GetContent()->getID() == id){
                if (Pptr->GetNext() == NULL) prevPtr->SetNext(nullptr);
                else prevPtr->SetNext(Pptr->GetNext());
                Pptr = nullptr;
                break;
            }

            //Move previous pointer object after current pointer has moved
            if (Pptr != prevPtr) prevPtr = prevPtr->GetNext();
        }
    }
}

void payloadList::sort() {
    if (head == NULL || head->GetNext() == NULL) return;

    payloadList* prevPtr = head;
    for (payloadList* Pptr = head; Pptr != NULL;) {
        
        //If able to swap, swap and reset loop
        payloadList* nextElem = Pptr->GetNext();

        if (Pptr->hasNext() && Pptr->GetContent()->getID() < nextElem->GetContent()->getID()){            
            //Swap two elements
            if (Pptr == head) head = nextElem;
            else prevPtr->SetNext(nextElem);
            Pptr->SetNext(nextElem->GetNext());
            nextElem->SetNext(Pptr);

            Pptr = head;
            prevPtr = head;
        }
        //else, move forward by one
        else{
            if (Pptr != prevPtr) prevPtr = prevPtr->GetNext();
            Pptr = Pptr->GetNext();
        }
    }
}

bool payloadList::hasNext() { return (next != NULL); }

client* payloadList::search(int id) {
    for (payloadList* ptr = head; ptr != NULL; ptr = ptr->GetNext()) {
        if (ptr->GetContent()->getID() == id) return ptr->GetContent();
    }
    client* c = new client();
    c->Initialize("", "", 0, -1);
    return c;
}