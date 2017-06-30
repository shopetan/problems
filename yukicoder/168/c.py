import numpy as np

hoge = map(int, raw_input().split())

A = np.array([[hoge[0],1],[hoge[1],1]])
P = np.array([hoge[1],hoge[2]])
X = np.linalg.solve(A,P)

print((hoge[2] * X[0].astype(int)) + X[1].astype(int))
