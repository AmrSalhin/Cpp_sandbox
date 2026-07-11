template<typename T, int size>
class Comparable 
{
    T m_data[size];
    public:
    Comparable() 
    {
        for (int i = 0; i < size; ++i) {
            m_data[i] = T();
        }
    }
    Comparable(std::initializer_list<T> initList) 
    {
        int i = 0;
        for (const auto& value : initList) {
            if (i < size) {
                m_data[i++] = value;
            }
        }
    }

    Comparable(const Comparable& other) 
    {
        for (int i = 0; i < size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }

    Comparable(T* other) 
    {
        for (int i = 0; i < size; ++i) {
            m_data[i] = other[i];
        }
    }

    T& operator[](int index) 
    {
        return m_data[index];
    }

    T Max() 
    {
        T maxValue = m_data[0];
        for (int i = 1; i < size; ++i) {
            if (m_data[i] > maxValue) {
                maxValue = m_data[i];
            }
        }
        return maxValue;
    }
};

/*Class partial specialization*/
template<int size>
class Comparable<const char*, size> 
{
    const char* m_data[size];
    public:
    Comparable() 
    {
        for (int i = 0; i < size; ++i) {
            m_data[i] = "";
        }
    }
    Comparable(std::initializer_list<const char*> initList) 
    {
        int i = 0;
        for (const auto& value : initList) {
            if (i < size) {
                m_data[i++] = value;
            }
        }
    }

    Comparable(const Comparable& other) 
    {
        for (int i = 0; i < size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }

    Comparable(const char** other) 
    {
        for (int i = 0; i < size; ++i) {
            m_data[i] = other[i];
        }
    }

    const char*& operator[](int index) 
    {
        return m_data[index];
    }

    const char* Max() 
    {
        const char* maxValue = m_data[0];
        for (int i = 1; i < size; ++i) {
            if (strcmp(m_data[i], maxValue) > 0) {
                maxValue = m_data[i];
            }
        }
        return maxValue;
    }
};
