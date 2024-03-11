#include <fstream>
#include <functional>
#include <iostream>

using logFunc_t = std::function<void(const std::string &)>;

int add3(int n) {
    return n+3;
}

int mul2(int n) {
    return n*2;
}

int mycomputeF(logFunc_t logF, int v0){
    logF("add3 " + std::to_string(v0) + "\n");
    const int v1 = add3(v0);
    logF("mul2 " + std::to_string(v1) + "\n");
    const int v2 = add3(v1);
    return v2;
}

int main() {
    std::cout << "this is log-cpp" << std::endl;

    logFunc_t f1 = [](const std::string & str){
        std::cout << str;
    };

    const int res1 = mycomputeF(f1,18);
    std::cout << res1 << std::endl;

    std::ofstream ofs("log2f.txt");
    logFunc_t f2 = [&ofs](const std::string & str){
        ofs << str;
    };

    const int res2 = mycomputeF(f2,18);
    std::cout << res2 << std::endl;

    return 0;
}

