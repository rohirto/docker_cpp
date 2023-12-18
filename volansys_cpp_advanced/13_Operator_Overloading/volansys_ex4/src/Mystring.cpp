#include <iostream>
#include <cstring>
#include "Mystring.h"

 // No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

//Unary overload - member function
char* Mystring::operator-() const
{
    char* lower = new char[strlen(str)+1];
    strcpy(lower, str);
    for (size_t i = 0; i < strlen(lower); ++i) 
    {
        lower[i] = std::tolower(lower[i]);
    }

    return lower;

}

//Equality operator - member function
bool Mystring::operator==(const Mystring &rhs) const
{
    return (std::strcmp(str, rhs.str) == 0);
}

//Inequality op - member func
bool Mystring::operator!=(const Mystring &rhs) const
{
    return !(*this == rhs);
}

// Less than operator - member func
bool Mystring::operator<(const Mystring &rhs) const
{
    return (std::strcmp(str, rhs.str) < 0);
}

// Greater than operator - mem func
bool Mystring::operator>(const Mystring &rhs) const
{
    return (std::strcmp(str, rhs.str) > 0);
}

// Concatenation operator
Mystring Mystring::operator+(const Mystring &rhs) const
{
    char* buff = new char[strlen(str) + strlen(rhs.str) + 1];
    strcpy(buff, str);
    strcat(buff, rhs.str);

    Mystring temp{buff};
    delete[] buff;

    return temp;
}

// Concatenation assignment operator
Mystring &Mystring::operator+=(const Mystring &rhs)
{
    *this = *this + rhs;
    return *this;
}

// Repeat operator -> repeat string n times
Mystring Mystring::operator*(int n) const
{
    Mystring result;
    for (int i = 0; i < n; ++i) {
        result += *this;
    }
    return result;
}

// Repeat assignment operator
Mystring &Mystring::operator*=(int n)
{
    *this = *this * n;
    return *this;
}

// Pre-increment operator - convert the string to upper case
Mystring &Mystring::operator++()
{
    for (size_t i = 0; i < strlen(str); ++i) {
        str[i] = std::toupper(str[i]);
    }
    return *this;
}

// Post-increment operator
Mystring Mystring::operator++(int)
{
    Mystring temp(*this);
    operator++();
    return temp;
}