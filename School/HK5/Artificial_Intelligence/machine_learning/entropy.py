import numpy as np
def entropy(X):
    s=0
    sp = sum(X)
    for i in range(len(X)):
        if X[i] != 0:
            s += X[i]/sp*np.log2(X[i]/sp)
    return -s
def AE(X):
    s = [sum(i) for i in X]
    total_s = sum(s)
    result = [s[i]/total_s*entropy(X[i]) for i in range(len(X))]
    return sum(result)