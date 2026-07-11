#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <utility>
#include <string>

template <typename T>
T Add(T x, T y)
{
	return x + y;
}

template <typename T, int size>
T ArraySum(const T (&pArr)[size])
{
	T sum = T();
	for (int i = 0; i < size; ++i)
	{
		sum += pArr[i];
	}
	return sum;
}

template <typename T, int size>
T Max(const T (&pArr)[size])
{
	T max = pArr[0];
	for (int i = 1; i < size; ++i)
	{
		if (pArr[i] > max)
		{
			max = pArr[i];
		}
	}
	return max;
}

template<typename T, int size>
std::pair<T, T> MinMax(const T (&pArr)[size])
{
	std::pair<T, T> minMaxResult{ pArr[0], pArr[0] };
	for (int i = 1; i < size; ++i)
	{
		if (pArr[i] < minMaxResult.first)
		{
			minMaxResult.first = pArr[i];
		}
		if (pArr[i] > minMaxResult.second)
		{
			minMaxResult.second = pArr[i];
		}
	}
	return minMaxResult;
}

template<>
const char* Add<const char*>(const char* x, const char* y);

template <>
const char* ArraySum(const char* const (&pArr)[4]);

template<>
std::string Max(const std::string (&pArr)[4]);

#endif // FUNCTIONS_H