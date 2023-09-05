import os
from random import randint

import joblib

Args = []

for i in range(10):
    Args.append((3 * 10 ** 5, ))

for _ in range(20):
    Args.append((randint(1, 3 * 10 ** 5), ))

print(len(Args))
print(Args)

def call(id, args):
    cmd = f"python3 tools/gen-call.py { id } { ' '.join(map(str, args)) }"
    os.popen(cmd)

joblib.Parallel(n_jobs=2)(
    joblib.delayed(call)(id, args) for id, args in enumerate(Args)
)
