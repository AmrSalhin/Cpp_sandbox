#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>


int main() {
    #pragma region Array
    std::cout << "==================== Array ====================" << std::endl;
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    auto it = arr.begin();
    while (it != arr.end()) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
   
    #pragma endregion

    #pragma region Vector
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
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    #pragma endregion
    
    #pragma region List
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
    for (const auto& val : lst) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    #pragma endregion

    #pragma region Forward_list
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
    #pragma endregion

    #pragma region Deque
    std::cout << "==================== Deque ====================" << std::endl;
    #pragma endregion



    return 0;
}