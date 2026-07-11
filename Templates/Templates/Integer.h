#ifndef INTEGER_H_
#define INTEGER_H_

class Integer {
    int* pValue;
public:
    //Integer();
    Integer(int value = 0);
    Integer(const Integer& other);
    Integer(Integer&& other) noexcept;
    ~Integer();

    Integer& operator=(const Integer& other);
    Integer& operator=(Integer&& other) noexcept;

    int getValue() const;
    void setValue(int value);
};

#endif  // INTEGER_H_