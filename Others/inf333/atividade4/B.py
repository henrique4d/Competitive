import numpy as np
x = np.array([[4],
                [5]
              ])
y = ([45,0])
scalars = np.linalg.solve(x, y)
print(scalars)