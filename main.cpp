#include<iostream>
#include "List.h"
#include <fstream>
#include "Abonent.h" 


using namespace std;


int main()
{
    
    ifstream file("in.txt");
    DoublyLinkedList<Abonent> dll(file);
    dll.display();
    cout<<endl;
    dll.delete_not_unique();
    cout << endl;
    dll.display();
    dll.reverse();
    cout << endl;
    dll.display();
    file.close();

    return 0;
}
