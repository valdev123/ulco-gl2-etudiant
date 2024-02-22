import mypackage.myfibo as mf

if __name__ == '__main__':
    
    # print fibo_naive(i) for i from 0 to 10
    for i in range(11):
        print(f"fibo_naive({i}) = " + str(mf.fibo_naive(i)))

    print()

    # print fibo_iterative(i) for i from 0 to 10
    for i in range(11):
        print(f"fibo_iterative({i}) = " + str(mf.fibo_iterative(i)))

