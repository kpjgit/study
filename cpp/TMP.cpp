#include <iostream>

template<int X, int Y>
struct gcd {
    static const int value = gcd<Y, X % Y>::value;
};
template<int X>
struct gcd<X, 0> {
    static const int value = X;
};

template<int N, int D = 1>
struct Ratio {
    typedef Ratio<N, D> type;
    static const int num = N;
    static const int den = D;
};
template<typename R1, typename R2> /*<class R1, class R2>*/
struct _Ratio_add {
    typedef Ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den> type;
};

template<class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

int main() {
    typedef gcd<36, 24> gcd36_24;
    std::cout << gcd36_24::value << std::endl;

    typedef Ratio<2, 3> rat;
    typedef Ratio<3, 2> rat2;
    using rat3 =  Ratio_add<rat, rat2>;
    using rat4 = Ratio_add<rat, rat3>;

    std::cout << rat3::num << " / " << rat3::den << std::endl;
}