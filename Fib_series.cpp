
// compiled and built with VS2019
#include <iostream>     // std::cout
using namespace std;

// 1. specialized type
template<long N>
struct Fib
{
    enum{ value =  Fib <N - 2>::value  + Fib <N - 1>::value };  //  
};

template<>
struct Fib<1>
{
    enum { value = 1 };
};

template<>
struct Fib<2>
{
    enum { value = 1 };
};

// C++ 11 for Fib
#include <type_traits>
#include <iostream>

template<long long n>
struct Fib_c11 :
    std::integral_constant<long long, (Fib_c11 <n - 1>::value) + (Fib_c11 <n - 2>::value) > {};

template<>
struct Fib_c11<0> :
    std::integral_constant<long long, 1> {};

template<>
struct Fib_c11<1> :
    std::integral_constant<long long, 1> {};

template<>
struct Fib_c11<2> :
    std::integral_constant<long long, 1> {};

// C++ 14
constexpr long long Fib_c14(long long n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return Fib_c14(n - 1) + Fib_c14(n - 2);
}

int main()
{
    // Fibonnacci in template/meta programming
    cout << " To calculate Fibonnacci by meta programming" << endl;
    cout << "Fib<5>::value = " << Fib<5>::value << endl;
    std::cout << "Fib_c11(7): " << Fib_c11<7>::value << '\n';
    std::cout << "Fib_c14(7): " << Fib_c14(7) << '\n';
}// end of main