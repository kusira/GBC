import os
from random import randint
import sys
import joblib

args = sys.argv

id = str(int(args[1])).zfill(4)
N = int(args[2])

Phi = 1

file = open(f"testcases/in/01_test-{id}.txt", "w")
# file.write(str(Phi) + "\n")

def call():
    seed = randint(0, 1 << 30)
    file.write(os.popen(f"./tools/gen-impl.exe { seed } { N }").read())

joblib.Parallel(n_jobs=1)(
    joblib.delayed(call)() for _ in [0] * Phi
)

file.close()
