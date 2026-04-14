//array -> contiguous
#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main()
{
    int arr[5]; //integer
    char charaArr[6];
    float floatArr[20];
    
    std::vector<int> vect{1,2,3,4,5};
    list<std::string> names {"Jett","Sage","Pheonix"};
    vect.push_back(6);
    vect.push_back(7);
    cout<<"vector size"<<vect.size();
    
    for(auto i = vect.begin();i!=vect.end();i++)
    {
        std::cout<<*i<<" ";
    }
    cout<<endl;
    
    vect.pop_back();
    vect.insert(vect.begin()+6,{8,9,10});
    //vect.erase(vect.begin(),vect.end());
    
//     insert() copies or moves an already existing object into the vector.

// emplace() constructs the object in-place directly inside the vector's memory, bypassing the need to create a temporary object
vect.emplace_back(15);
vect.emplace(vect.end(),16);
     for(auto i = vect.begin();i!=vect.end();i++)
    {
        std::cout<<*i<<" ";
    }
    cout<<endl;
    
    for (const std::string& agent: names){
        std::cout<<agent<<" ";
    }
    
    /* for cpp 
    front() – Returns the value of the first element in the list.
    back() – Returns the value of the last element in the list.
    push_front(g) – Adds a new element ‘g’ at the beginning of the list.
    push_back(g) – Adds a new element ‘g’ at the end of the list.
    pop_front() – Removes the first element of the list, and reduces the size of the list by 1.
    pop_back() – Removes the last element of the list, and reduces the size of the list by 1.
    begin() and end() – begin() function returns an iterator pointing to the first element of the list.
    empty() – Returns whether the list is empty(1) or not(0).
    insert() – Inserts new elements in the list before the element at a specified position.
    reverse() – Reverses the list.
    size() – Returns the number of elements in the list.
    sort() – Sorts the list in increasing order.
    */
    

    return 0;
}
