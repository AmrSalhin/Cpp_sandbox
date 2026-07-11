#include <iostream>
#include <vector>
#include <type_traits>
#include "functions.h"
#include "Integer.h"
#include "Stack.h"
#include "Comparable.h"

template <typename T>
using newType = std::vector<std::vector<T>>;


template <typename T>
T Divide(T a, T b) 
{
	
	static_assert(std::is_floating_point<T>::value, "non-floating-point type.");
	
	return a / b;
}

#pragma region Perfect Forwarding
template <typename T>
T TestRvalue(T&& obj)
{
	std::cout << "TestRvalue(const T&& obj)" << std::endl;
	T localObj {std::forward<T>(obj)};
	return localObj;
}
#pragma endregion

#pragma region Variadic Templates
template <typename T, typename ...params>
T CreateObject(params&&... args)
{
	return T(std::forward<params>(args)...);
}
#pragma endregion

#pragma region Template Functions
// Explicit template instantiation for Add function
template int Add(int, int);
#pragma endregion

#pragma region Template Classes
template<typename T>
class PrettyPrinter {
	T *m_pData;
public:
	PrettyPrinter(T *data) :m_pData(data) {
	}
	void Print() {
		std::cout << "{" << *m_pData << "}" << std::endl;
	}

	T * GetData() {
		return m_pData;
	}
};

//Explicit specialization of a member function should appear outside the class
template<>
void PrettyPrinter<std::vector<int>>::Print() {
	std::cout << "{";
	for (const auto &x : *m_pData) {
		std::cout << x;
	}
	std::cout << "}" << std::endl;
}
template<>
class PrettyPrinter<char*> {
	char *m_pData;
public:
	PrettyPrinter(char *data) :m_pData(data) {

	}
	void Print() {
		std::cout << "{" << m_pData << "}" << std::endl;
	}
	char * GetData() {
		return m_pData;
	}
};

template<>
void PrettyPrinter<std::vector<std::vector<int>>>::Print() {
		std::cout << "{";
		for(const auto &row : *m_pData) {
			std::cout << "{";
			for (const auto &x : row) {
				std::cout << x;
			}
			std::cout << "}";
		}
		std::cout << "}" << std::endl;
	}

#pragma endregion

int main()
{
#pragma region Template Functions
	// float arr[] = { 1.0f, 2.0f, 7.0f, 4.0f, 5.0f };
	// const char* str1 = "Hello, ";
	// const char* str2 = "World!";
	// const char* strArr[] = { "This ", "is ", "a ", "test." };
	// std::cout << "ArraySum: " << ArraySum(arr) << std::endl;
	// std::cout << "Max: " << Max(arr) << std::endl;
	// std::cout << "Add: " << Add(10.0, 5.5) << std::endl;
	// std::cout << "MinMax: " << MinMax(arr).first << ", " << MinMax(arr).second << std::endl;
	// std::cout << "Add strings: " << Add(str1, str2) << std::endl;
	// std::cout << "ArraySum strings: " << ArraySum(strArr) << std::endl;
	// std::string strArr2[] = { "apple", "banana", "cherry", "date" };
	// std::cout << "Max strings: " << Max(strArr2) << std::endl;
#pragma endregion

#pragma region Perfect Forwarding
	// Integer intObj(10);
	// TestRvalue(Integer(42));
	// TestRvalue(intObj);
#pragma endregion

#pragma region Variadic Templates
	// Integer obj1 = CreateObject<Integer>(10);
	// std::string obj2 = CreateObject<std::string>();
#pragma endregion

#pragma region Template Classes
	// Stack<Integer, 5> intStack = Stack<Integer, 5>::Create();
	// intStack.Push(Integer(10));
	// intStack.Push(Integer(20));
	// std::cout << "Top element: " << intStack.Top().getValue() << std::endl;

	/*explicit specialization*/
	// std::vector<std::vector<int>> vec2D = { {1, 2, 3}, {4, 5, 6} };
	// PrettyPrinter<std::vector<std::vector<int>>> printer(&vec2D);
	// printer.Print();
	// printer.GetData();

#pragma endregion

#pragma region Template Class Partial Specialization
// int arr[] = { 1, 2, 3, 4, 5 };
// Comparable<int, 5> comp(arr);

// std::cout << "Max value: " << comp.Max() << std::endl;

// /*Template class partial specialization*/
// const char* strArr[] = { "apple", "banana", "cherry", "ant" };
// Comparable<const char*, 4> compStr(strArr);
// std::cout << "Max string: " << compStr.Max() << std::endl;

#pragma endregion


#pragma region Type Traits and static_assert
	// std::cout << "Divide(10.0, 2.0): " << Divide<float>(10, 3) << std::endl;
#pragma endregion

#pragma region Type Aliases
	newType<int> vec2D = { {1, 2, 3}, {4, 5, 6} };
	for (const auto& row : vec2D) {
		for (const auto& elem : row) {
			std::cout << elem << " ";
		}
		std::cout << std::endl;
	}
#pragma endregion

return 0;
}
