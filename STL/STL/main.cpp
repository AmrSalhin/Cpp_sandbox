#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <map>
#include <set>
#include <functional>

void array()
{
    std::cout << "==================== Array ====================" << std::endl;
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    arr[1] = 49; /*accessing the array using []*/
    auto it = arr.begin();
    while (it != arr.end()) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

void vector()
{
    std::cout << "==================== Vector ====================" << std::endl;
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6);
    std::cout << "Size of vector: " << vec.size() << std::endl;
    vec.pop_back();
    std::cout << "Size of vector after pop_back: " << vec.size() << std::endl;
    vec.pop_back();
    std::cout << "Size of vector after another pop_back: " << vec.size() << std::endl;
    vec.insert(vec.begin() + 1, 10);
    std::cout << "Size of vector after insert: " << vec.size() << std::endl;
    vec[1] = 49; /*accessing the vector using []*/
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void list()
{
    std::cout << "==================== List ====================" << std::endl;
    std::list<int> lst = {1, 2, 3, 4, 5};
    lst.push_back(6);
    std::cout << "Size of list: " << lst.size() << std::endl;
    lst.push_front(0);
    std::cout << "Size of list after push_front: " << lst.size() << std::endl;
    lst.pop_back();
    std::cout << "Size of list after pop_back: " << lst.size() << std::endl;
    lst.pop_back();
    std::cout << "Size of list after another pop_back: " << lst.size() << std::endl;
    lst.insert(std::next(lst.begin(), 1), 10);
    std::cout << "Size of list after insert: " << lst.size() << std::endl;
    // lst[1] = 49; Lists is Linked list cannot be random accesed []
    *std::next(lst.begin(), 1) = 10; // next take the iterator and the shift value and return iterator at this position
    for (const auto& val : lst) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    std::list<int>::iterator iter = lst.begin();
    int order = 0;
    while (iter != lst.end()) 
    {   
        /*print the element at index 2 because the list cannot be indexed directly*/
        if(order == 2)
        {
            std::cout<< "the value in inex 2: " << *iter << std::endl;
            break;
        }
        else
        {
        }
        order++;
        ++iter;
    }
    /*another way to print the element at index 2*/
    std::cout<< "the value in inex 2: "  << *(std::next(lst.begin(), 2)) << std::endl;
}

void forwardList()
{
    std::cout << "==================== Forward_list ====================" << std::endl;
    std::forward_list<int> fwd_lst = {1, 2, 3, 4, 5};
    fwd_lst.push_front(0);
    std::cout << "Size of forward_list: " << std::distance(fwd_lst.begin(), fwd_lst.end()) << std::endl;
    fwd_lst.pop_front();
    std::cout << "Size of forward_list after pop_front: " << std::distance(fwd_lst.begin(), fwd_lst.end()) << std::endl;
    fwd_lst.insert_after(std::next(fwd_lst.begin(),2), 10);
    for (const auto& val : fwd_lst) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void deque()
{
    std::cout << "==================== Deque(double edged queue) ====================" << std::endl;
    std::deque<int> deq = {0, 1, 2};
    deq.push_front(100);
    std::cout << "deque size: " << deq.size() << std::endl;
    deq.push_back(99);
    std::cout << "deque size: " << deq.size() << std::endl;
    deq.insert(deq.begin() + 2, 43);
    std::cout << "deque size: " << deq.size() << std::endl;
    deq.erase(deq.end()-2);
    std::cout << "deque size: " << deq.size() << std::endl;
    for (const auto& value : deq)
    {
        std::cout << value << " ";
    }
    std::cout<<std::endl;
}

void set()
{
    std::cout << "=========================== Sets ===========================" << std::endl;
    std::set<int, std::greater<int>/*optional to add comparator*/> mySet {9, 8, 9, 5, 7}; //sets delete duplications
    mySet.erase(8);
    mySet.insert(45);// insert the value direct and it will be sorted
    auto ite = mySet.begin();
    // *it = 10; cannot modify values using iterator
    for (const auto& val : mySet)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void multiSet()
{
    std::cout << "======================== Multi Sets ========================" << std::endl;
    std::multiset<int> mySet {9, 8, 9, 5, 8, 7}; // allow duplications
     mySet.erase(8); // delete all occurance of 8
    mySet.insert(45);// insert the value direct and it will be sorted
    auto ite = mySet.begin();
    // *it = 10; cannot modify values using iterator
    std::cout << *mySet.find(9) <<std::endl; // return the first occurence only
    auto found = mySet.equal_range(9); // find all occurence of 9
    std::cout << "All Occurence of 9: ";
    while(found.first != found.second)
    {
        std::cout << *found.first << " ";
        found.first++;
    }
    std::cout<<std::endl;
    for (const auto& val : mySet)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

}

void map()
{
    std::cout << "=========================== Maps ===========================" << std::endl;
    std::map<int/*key*/, std::string/*value*/> myMap{
        {99, "Super Man"},
        {2, "Spider Man"},
        {3, "Bat Man"}
    };
    
    myMap[0] = "Captin America"; // if the key is not exist it will add it
    myMap[3] = "Wonder Woman"; // id the key is exit it will overwrite the existing value

    auto iterator = myMap.begin();
    iterator++;
    std::cout << iterator->first << iterator->second << std::endl;

    std::cout<<std::endl;
    for (const auto& val : myMap)
    {
        std::cout << val.first<< ": " << val.second << std::endl;
    }
}

void MultiMap()
{
    std::cout << "=========================== Multi Maps ===========================" << std::endl;
    std::multimap<int/*key*/, std::string/*value*/> myMap{
        {99, "Super Man"},
        {99, "Captin America"},
        {2, "Spider Man"},
        {3, "Bat Man"}
    }; /*can save multiple values for the same key*/
    
    // myMap[0] = "Captin America"; multi map cannot accessed using []

    auto iterator = myMap.begin();
    iterator++;
    std::cout << iterator->first << iterator->second << std::endl;
    iterator->second = "Messi"; // this will overwite the value
    std::cout << myMap.find(99)->second << std::endl; //return first value
    auto found = myMap.equal_range(99); // find all occurence of key 99
    std::cout << "All Occurence of Key 99: ";
    while(found.first != found.second)
    {
        std::cout << found.first->second << " ";
        found.first++;
    }

    std::cout<<std::endl;
    for (const auto& val : myMap)
    {
        std::cout << val.first<< ": " << val.second << std::endl;
    }
}

int main() {
    /*****************************  Sequence Containers *************************************/

    // array();

    // vector();
    
    // list();
    
    // forwardList();

    // deque();


    /*****************************  Associative Containers *************************************/

    set();

    multiSet();

    map();

    MultiMap();

    /*****************************  Unordered Containers *************************************/


    return 0;
}