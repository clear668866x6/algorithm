#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <string>
#include <type_traits>
#include <vector>
using namespace std;

template <class T, class = decay_t<decltype(*begin(declval<T>()))>,
          class = enable_if_t<!is_same<T, string>::value>>
ostream& operator<<(ostream& os, const T& c) { // 定义容器的流输出
    for (auto it = c.begin(); it != c.end(); ++it) {
        os << &", "[2 * (it == c.begin())] << *it;
    }
    return os;
}

template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) { // 定义pair的流输出
    return os << '[' << p.first << ", " << p.second << ']';
}

template <class... Args> void _(Args... args) { // 可变模板输出
    auto _ = [&](auto x) -> void { cout << x << " "; };
    cout << "--->";
    int arr[] = {(_(args), 0)...};
    cout << "\n";
}

template <class T, class = decay_t<decltype(*begin(declval<T>()))>,
          class = enable_if_t<!is_same<T, string>::value>>
void _(T args) {
    cout << "{" << args << "}\n";
} // 容器输出

template <class T> void _i(T args) { // 旧时代容器输出
    cout << "{";
    for (auto i : args)
        cout << i << ", ";
    cout << "}\n";
}

template <class T> void _ii(T args) { // 旧时代容器输出
    cout << "{";
    for (auto [i, j] : args)
        cout << i << " " << j << ", ";
    cout << "}\n";
}

#endif // DEBUG_H