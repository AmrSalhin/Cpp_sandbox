#pragma once

template <typename T, int size>
class Stack
{
    T arr[size];
    int m_top{-1};

    public:
    Stack();
    Stack(const Stack<T, size>& obj);
    void Push(const T& obj);
    void Pop();
    const T& Top() const;
    static Stack Create();
    bool IsEmpty() const { return m_top == -1; }

};

template <typename T, int size>
Stack<T, size>::Stack() = default;

template <typename T, int size>
Stack<T, size>::Stack(const Stack<T, size>& obj)
{
    m_top = obj.m_top;
    for (int i = 0; i <= m_top; ++i)
    {
        arr[i] = obj.arr[i];
    }
}

template <typename T, int size>
void Stack<T, size>::Push(const T& obj)
{
    m_top++;
    arr[m_top] = obj;
}

template <typename T, int size>
void Stack<T, size>::Pop()
{
    if (m_top >= 0)
    {
        m_top--;
    }
}

template <typename T, int size>
const T& Stack<T, size>::Top() const
{
    return arr[m_top];
}

template <typename T, int size>
Stack<T, size> Stack<T, size>::Create()
{
    return Stack<T, size>();
}

