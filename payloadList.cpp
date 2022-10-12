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

payload* payloadList::GetContent() { return ptr; }
void payloadList::SetContents(payload* p) { ptr = p; }

payloadList* payloadList::GetNext() { return next; }
void payloadList::SetNext(payloadList* n) { next = n; }

payloadList* payloadList::GetHead() { return head; }

void payloadList::push(payload* p) {
    if (ptr == NULL && next == NULL) { ptr = p; return; }
    newElement = new payloadList();
    newElement->SetContents(p);
    newElement->SetNext(head);
    head = newElement;
}

void payloadList::del(int id) {
    if (head->GetContent()->GetID() == id) {
        payloadList* nxt = head->GetNext();
        head = nullptr;
        head = nxt;
    }
    else {
        payloadList* prevPtr = head;
        for (payloadList* Pptr = head; Pptr != NULL; Pptr = Pptr->GetNext()) {
            if (Pptr->GetContent()->GetID() == id){
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
        //cout << "\nPointer Loop: " << Pptr->GetContent()->GetName() << endl;

        //If able to swap, swap and reset loop
        payloadList* nextElem = Pptr->GetNext();
        /*
        cout << "Swap Test: " << Pptr->GetContent()->GetID() << "<"
             << (Pptr->hasNext() ? nextElem->GetContent()->GetID() : -1) << endl;
        */

        if (Pptr->hasNext() && Pptr->GetContent()->GetID() < nextElem->GetContent()->GetID()){
            //cout << "Elements swapping: " << Pptr->GetContent()->GetName() << ":" << nextElem->GetContent()->GetName() << endl;
            
            //Swap two elements
            if (Pptr == head) head = nextElem;
            else prevPtr->SetNext(nextElem);
            Pptr->SetNext(nextElem->GetNext());
            nextElem->SetNext(Pptr);

            /*
            cout << "Current: " << Pptr->GetContent()->GetName() << "->"
                 << ((Pptr->GetNext() == NULL) ? "NULL" : Pptr->GetNext()->GetContent()->GetName()) << endl;
            cout << "Next: " << nextElem->GetContent()->GetName() << "->"
                 << ((nextElem->GetNext() == NULL) ? "NULL" : nextElem->GetNext()->GetContent()->GetName()) << endl;
            //nextElem->SetNext(Pptr);*/

            Pptr = head;
            prevPtr = head;
            
            /*
            cout << "Head: " << head->GetContent()->GetName() << "\nPointer: " << Pptr->GetContent()->GetName() << endl;
            //return;
            */
        }
        //else, move forward by one
        else{
            //cout << "No Swap" << endl;
            if (Pptr != prevPtr) prevPtr = prevPtr->GetNext();
            Pptr = Pptr->GetNext();
        }
    }
}

bool payloadList::hasNext() { return (next != NULL); }

payload* payloadList::search(int id) {
    for (payloadList* ptr = head; ptr != NULL; ptr = ptr->GetNext()) {
        if (ptr->GetContent()->GetID() == id) return ptr->GetContent();
    }
    return new payload("", -1);
}