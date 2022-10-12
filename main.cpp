#include <iostream>
#include <fstream>

#include "client.h"
#include "payloadList.cpp"

using namespace std;

void testDriver(){
    payloadList list;

    ifstream inFile;
    ofstream outFile;
    string command;

    inFile.open("test.txt");
    outFile.open("out.txt");

    inFile >> command;
    for (int count = 1; command != "Quit"; count++){
        //Commands

        //Build List
        if (command == "push") {
            int size;
            inFile >> size;
            for (int i = 0; i < size; i++) {
                //Format option
                string format;

                //Constructor data
                string fname, lname;
                float bal;
                int id;

                client* p = new client();
                inFile >> format;
                if (format == "full") {
                    inFile >> fname >> lname >> bal >> id;
                    p->Initialize(fname, lname, bal, id);
                }
                else if (format == "part") {
                    inFile >> fname >> id;
                    p->Initialize(fname, "x", 0, id);
                }

                if (list.hasNext() && (&list, id)) {
                    outFile << "Push Failed, ID \"" << id << "\" Already Exists" << endl;
                }
                else {
                    list.push(p);
                    outFile << "Pushing \"" << fname << " " << lname << ":" << id << "\" to list" << endl;
                }
            }
        }

        //Delete Element
        else if (command == "delete") {
            int id;
            inFile >> id;
            outFile << "Deleting \"" << id << "\"" << endl;
            list.del(id);
        }

        //Print list
        else if (command == "print") {
            outFile << "Built List: [";
            for (payloadList* ptr = list.GetHead(); ptr != NULL; ptr = ptr->GetNext()) {
                outFile << ptr->GetContent()->getFullName() << ":" << ptr->GetContent()->getID();
                if (ptr->hasNext()) outFile << ", ";
                //cout << "Pointer: " << ptr->GetContent()->GetName() << ":"
                //     << ((ptr->GetNext() == NULL) ? "NULL" : ptr->GetNext()->GetContent()->GetName()) << endl;
            }
            outFile << "]" << endl;
        }

        //Search for element in list
        else if (command == "search") {
            int srch;
            inFile >> srch;
            //if (srch != NULL && search(&list, srch)) outFile << "Search Succ essful, \"" << srch << "\" found" << endl;
            if (list.search(srch)) outFile << "Search Successful, \"" << srch << "\" found" << endl;
            else outFile << "Search Unsuccessful, \"" << srch << "\" not found" << endl;
        }

        else if (command == "sort") {
            list.sort();
            outFile << "List is Sorted" << endl;
        }
        
        else if (command == "") { /*Do nothing*/ }
        else outFile << "Command " << command << " does not exist" << endl;

        cout << "Test " << count << " Completed" << " : " << command  << endl;
        inFile >> command;
    }
    
    cout << "All Tests Completed" << endl;

    inFile.close();
    outFile.close();
}

void buildMenu() {   
    cout << "~Bank App~\n" 
         << "1. Add a Client\n"
         << "2. View Client by ID\n"
         << "3. Update Balance\n"
         << "4. Remove Client\n"
         << "5. View Client\n"
         << "6. Exit Program" << endl;
}

void printClient(client p) {
    cout << "Name: " << p.getFullName()
         << "   ID: " << p.getID()
         << "   Balance: " << p.getBalance() << endl << endl;
}

bool clientExists(payloadList l, int id) {
    client* p = l.search(id);
    if (p->getID() == -1) return false;
    else return true;
}

client* getClient(payloadList l) {
    int id;
    cout << "Enter Client's ID: ";
    cin >> id;
    client* p = l.search(id);
    if (p->getID() == -1) cout << "Client by ID \"" << id << "\" Does Not Exist" << endl;
    return p;
}

void printAllClients(payloadList l) {
    client* p = getClient(l);
    if (p->getID() != -1) printClient(*p);
}

void addClient(payloadList &l) {
    string fname, lname;
    float bal;
    int id;
    cout << "Enter client in first last balance id format: ";
    cin >> fname >> lname >> bal >> id;
    client* p = new client();
    p->Initialize(fname, lname, bal, id);
    l.push(p);
    cout << "Client Successfully Added\n" << endl;
}

void findClient(payloadList l) {
    client* p = getClient(l);
    if (p->getID() != -1) printClient(*p);
}

void updateBal(payloadList &l) {
    client* p = getClient(l);
    if (p->getID() != -1) {
        double newBal;
        cout << "\nEnter New Balance: ";
        cin >> newBal;

        cout << "Balance updated from $" << p->getBalance();
        p->setBalance(newBal);
        cout << "to $" << p->getBalance() << endl;
    }
}

void removeClient(payloadList& l) {
    int id;
    cout << "Enter Client's ID: ";
    cin >> id;
    if (!clientExists(l, id)) cout << "Client by ID \"" << id << "\" Does Not Exist" << endl;
    else {
        l.del(id);
        cout << "\nClient Successfully Deleted" << endl;
    }
}

int main(int argc, char const *argv[]) {
    payloadList list;
    int option;
    //testDriver();
    do
    {
        buildMenu();
        cin >> option;

        switch (option)
        {
        case 1:
            addClient(list);
            break;
        
        case 2:
            findClient(list);
            break;
        
        case 3:
            updateBal(list);
            break;
        
        case 4:
            removeClient(list);
            break;
        
        case 5:
            printAllClients(list);
            break;
        
        case 6:
            cout << "Closing Application... ";
            break;
    
        default:
            cout << "Option \"" << option << "\" Does Not Exist" << endl;
            break;
        }
    } while (option != 6);
    cout << "Application Successfully Exited.\n";

    return 0;
}
