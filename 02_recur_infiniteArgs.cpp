
// only 2 var 
template <typename T1, typename T2>
auto min2(const T1& a, const T2& b)
-> typename std::common_type<const T1&, const T2&>::type
{
    return a < b ? a : b;
}

template <typename T1, typename T2, typename ... Args>
auto min2(const T1& a, const T2& b, const Args& ... args)
-> typename std::common_type<const T1&, const T2&, const Args& ...>::type
{
    return min2(min2(a, b), args...);
}

int main()
{
    auto minimum = min2(4, 5.8f, 3, 1.8, 3, 1.1, 9);
    std::cout << "the minimum number: " << minimum << '\n';

}