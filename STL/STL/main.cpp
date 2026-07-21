#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <map>
#include <set>
#include <functional>
#include <unordered_set>
#include <unordered_map>

/*creating a custom type to create hash and equality functions*/
class NewType
{
    int value;
    std::string name;
    public:
    NewType(int v, std::string n): value(v), name(n) {}
    int getValue() const { return value; }
    std::string getName() const { return name; }
    /*implementing comparison operators to enable use in ordered containers*/
    bool operator==(const NewType& other) const
    {
        return (value == other.value && name == other.name);
    }

    bool operator!=(const NewType& other) const
    {
        return !(*this == other);
    }

    bool operator<(const NewType& other) const
    {
        return (value < other.value || (value == other.value && name < other.name));
    }

    bool operator>(const NewType& other) const
    {
        return (value > other.value || (value == other.value && name > other.name));
    }
};

struct NewTypeHash
{
    std::size_t operator()(const NewType& obj) const
    {
        return (std::hash<int>()(obj.getValue()) ^ std::hash<std::string>()(obj.getName()));
    }
};

struct NewTypeEqual
{
    bool operator()(const NewType& lhs, const NewType& rhs) const
    {
        return (lhs.getValue() == rhs.getValue() && lhs.getName() == rhs.getName());
    }
};

void unorderSet()
{
    std::cout << "============== Unordered Set ==============" << std::endl;
    std::unordered_set<NewType, NewTypeHash, NewTypeEqual> mySet{
        NewType(1, "one"), NewType(2, "two"), NewType(3, "three"), NewType(4, "four"), NewType(5, "five"), NewType(50, "fifty")
    };
    std::cout << "number Of Buckets: " << mySet.bucket_count() << std::endl;
    std::cout << "Number Of Elements: " << mySet.size() << std::endl;
    std::cout << "Load Factor: " << mySet.load_factor() << std::endl;
    /*remove duplicates */
    mySet.insert(NewType(4, "four"));
    std::cout << "inserted four again" << std::endl;
    std::cout << "number Of Buckets: " << mySet.bucket_count() << std::endl;
    std::cout << "Number Of Elements: " << mySet.size() << std::endl;
    std::cout << "Load Factor: " << mySet.load_factor() << std::endl;
    std::cout << "All occurrences of four: " << std::endl;
    auto found = mySet.equal_range(NewType(4, "four"));
    while(found.first != found.second)
    {
        std::cout << "four found in bucket: " << mySet.bucket(*found.first) << std::endl;
        ++found.first;
    }
    std::cout << "All elements in the unordered set: " << std::endl;
    for(const auto& val: mySet)
    {
        std::cout << "Value: " << val.getValue() << " Name: " << val.getName() << " Bucket: " << mySet.bucket(val) <<std::endl;
    }
    std::cout <<std::endl;
}

void unorderedMultiSet()
{
    std::cout << "============== Unordered MultiSet ==============" << std::endl;
    std::unordered_multiset<NewType, NewTypeHash, NewTypeEqual> mySet{
        NewType(1, "one"), NewType(2, "two"), NewType(3, "three"), NewType(4, "four"), NewType(5, "five"), NewType(50, "fifty")
    };
    std::cout << "number Of Buckets: " << mySet.bucket_count() << std::endl;
    std::cout << "Number Of Elements: " << mySet.size() << std::endl;
    std::cout << "Load Factor: " << mySet.load_factor() << std::endl;
    /*allow duplicates */
    mySet.insert(NewType(4, "four"));
    std::cout << "inserted four again" << std::endl;
    std::cout << "number Of Buckets: " << mySet.bucket_count() << std::endl;
    std::cout << "Number Of Elements: " << mySet.size() << std::endl;
    std::cout << "Load Factor: " << mySet.load_factor() << std::endl;
    /*return the first occurrence of "four" */
    auto ite = mySet.find(NewType(4, "four"));
    if(ite != mySet.end())
    {
        std::cout << "four found in bucket: " << mySet.bucket(*ite) << std::endl;
    }
    std::cout << "All occurrences of four: " << std::endl;
    auto found = mySet.equal_range(NewType(4, "four"));
    while(found.first != found.second)
    {
        std::cout << "four found in bucket: " << mySet.bucket(*found.first) << std::endl;
        ++found.first;
    }
    std::cout << "All elements in the unordered MultiSet: " << std::endl;
    for(const auto& val: mySet)
    {
        std::cout << "Value: " << val.getValue() << " Name: " << val.getName() << " Bucket: " << mySet.bucket(val) <<std::endl;
    }
    std::cout <<std::endl;
}

void unorderMap()
{
    std::cout << "============== Unordered Map ==============" << std::endl;
    std::unordered_map<std::string, int> mySet{
        {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"fifty", 50}};
    std::cout << "number Of Buckets: " << mySet.bucket_count() << std::endl;
    std::cout << "Number Of Elements: " << mySet.size() << std::endl;
    std::cout << "Load Factor: " << mySet.load_factor() << std::endl;
    /*remove duplicates */
    mySet.insert({"four", 4});
    std::cout << "inserted four again" << std::endl;
    std::cout << "number Of Buckets: " << mySet.bucket_count() << std::endl;
    std::cout << "Number Of Elements: " << mySet.size() << std::endl;
    std::cout << "Load Factor: " << mySet.load_factor() << std::endl;
    std::cout << "All occurrences of four: " << std::endl;
    auto found = mySet.equal_range("four");
    while(found.first != found.second)
    {
        std::cout << "four found in bucket: " << mySet.bucket(found.first->first) << std::endl;
        ++found.first;
    }
    std::cout << "All elements in the unordered map: " << std::endl;
    for(const auto& val: mySet)
    {
        std::cout << "Value: " << val.first << ": " << val.second << " Bucket: " << mySet.bucket(val.first) <<std::endl;
    }
    std::cout <<std::endl;
}

void unorderedMultiMap()
{
    std::cout << "============== Unordered MultiMap ==============" << std::endl;
    std::unordered_multimap<std::string, int> mySet{
        {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"fifty", 50}};
    std::cout << "number Of Buckets: " << mySet.bucket_count() << std::endl;
    std::cout << "Number Of Elements: " << mySet.size() << std::endl;
    std::cout << "Load Factor: " << mySet.load_factor() << std::endl;
    /*allow duplicates */
    mySet.insert({"four", 4});
    std::cout << "inserted four again" << std::endl;
    std::cout << "number Of Buckets: " << mySet.bucket_count() << std::endl;
    std::cout << "Number Of Elements: " << mySet.size() << std::endl;
    std::cout << "Load Factor: " << mySet.load_factor() << std::endl;
    /*return the first occurrence of "four" */
    auto ite = mySet.find("four");
    if(ite != mySet.end())
    {
        std::cout << "four found in bucket: " << mySet.bucket(ite->first) << std::endl;
    }
    std::cout << "All occurrences of four: " << std::endl;
    auto found = mySet.equal_range("four");
    while(found.first != found.second)
    {
        std::cout << "four found in bucket: " << mySet.bucket(found.first->first) << std::endl;
        ++found.first;
    }
    std::cout << "All elements in the unordered MultiMap: " << std::endl;
    for(const auto& val: mySet)
    {
        std::cout << "Value: " << val.first << ": " << val.second << " Bucket: " << mySet.bucket(val.first) <<std::endl;
    }
    std::cout <<std::endl;
}

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

    array();

    vector();
    
    list();
    
    forwardList();

    deque();


    /*****************************  Associative Containers *************************************/

    set();

    multiSet();

    map();

    MultiMap();

    /*****************************  Unordered Containers *************************************/
    unorderSet();
    
    unorderMap();

    unorderedMultiSet();

    unorderedMultiMap();

    return 0;
}