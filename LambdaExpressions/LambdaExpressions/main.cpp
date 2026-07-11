#include<iostream>
using namespace std;

template<typename T, int size, typename compare>
void sort(T(&arr)[size], compare comparator)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (comparator(arr[j], arr[j + 1]))
			{
				T temp = move(arr[j]);
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

template <typename T>
struct Max
{
    T operator()(T a, T b) const
    {
        return (a > b) ? a : b;
    }
};

template<typename T>
struct Greater
{
    bool operator()(T a, T b) const
    {
        return a > b;
    }
};

template<typename T>
struct Less
{
    bool operator()(T a, T b) const
    {
        return a < b;
    }
};

template <typename T>
struct MinMax
{
    std::pair<T, T> operator()(T* begin, T* end) const
    {
        std::pair<T, T> result;
        result.first = *begin;
        result.second = *begin;
        while (begin != end)
        {
            if (*begin < result.first)
            {
                result.first = *begin;
            }
            if (*begin > result.second)
            {
                result.second = *begin;
            }
            ++begin;
        }
        return result;
    }
};

int main()
{
    int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5 };
    int a = 10, b = 20;

	cout << [](auto param1, auto param2)
		{
			if (param1 > param2)
				return param1;
			return param2;
		}(5, 3) << endl;

	cout << [](auto param1, auto param2)
		{
			return param1 > param2;
		}(5, 5) << endl;

	cout << [](auto param1, auto param2)
		{
			return param1 < param2;
		}(5, 6) << endl;

    auto lambdaresult = [](auto begin, auto end) {
        std::pair<std::decay_t<decltype(*begin)>, std::decay_t<decltype(*begin)>> result2(*begin, *begin);
        while (begin != end)
        {
            if (*begin < result2.first)
            {
                result2.first = *begin;
            }
            if (*begin > result2.second)
            {
                result2.second = *begin;
            }
            ++begin;
        }
        return result2;
        }(arr, arr + sizeof(arr) / sizeof(arr[0]));

    std::cout << "Max of " << a << " and " << b << " is: " << Max<int>()(a, b) << std::endl;

    double x = 5.5, y = 3.3;
    std::cout << "Max of " << x << " and " << y << " is: " << Max<double>()(x, y) << std::endl;

    std::cout << "Is " << a << " greater than " << b << "? " << Greater<int>()(a, b) << std::endl;

    std::cout << "Is " << a << " less than " << b << "? " << Less<int>()(a, b) << std::endl;

    auto result = MinMax<int>()(arr, arr + sizeof(arr) / sizeof(arr[0]));
    std::cout << "Min: " << result.first << ", Max: " << result.second << std::endl;


    std::cout << "Lambda Min: " << lambdaresult.first << ", Lambda Max: " << lambdaresult.second << std::endl;



}