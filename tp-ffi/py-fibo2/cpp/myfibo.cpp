#include <cassert>

int fiboNaive(int n) {
    assert(n => 0);
    return n < 2 ? n : fiboNaive(n-1) + fiboNaive(n-2);
}

// implement fiboIterative

int fiboIterative(int n) {
    assert(n => 0);
    if (n == 0) return 0;
    else{
        if (n == 1) return 1;
        else {
            int n0 = 0;
            int n1 = 1;
            for(int i = 1; i < n;i++){
                int tmp = n1;
                n1 = n0 + n1;
                n0 = tmp;
            }
            return n1;
        }
    } 
    
}




#include <pybind11/pybind11.h>

PYBIND11_MODULE(myfibo, m) {

    // export fiboNaive (as fibo_naive)

    m.def("fibo_naive", &fiboNaive);

    // export fiboIterative (as fibo_iterative)

    m.def("fibo_iterative", &fiboIterative);

}

