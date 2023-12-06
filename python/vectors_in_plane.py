#!/usr/bin/python3
import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()
ax = fig.add_subplot()

x = [4, -2]   # x-coordinates
y = [1, 2]   # y-coordinates

ax.scatter(x, y, color='red')
ax.plot(x, y)

ax.scatter(2, 3, color='red')
ax.scatter(6, -1, color='blue')

ax.set_xlim([-3, 10])
ax.set_ylim([-3, 10])

# Set labels and title
ax.set_xlabel('X-axis')
ax.set_ylabel('Y-axis')
ax.set_title('Vectors in 2D space')

plt.show()
