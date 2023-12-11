#!/usr/bin/python3
import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()
ax = fig.add_subplot()

identity_mat = np.array([[1, 3],
                         [0, 1]])

input_mat = np.array([[0],
                     [1]])

output_mat = identity_mat @ input_mat

ax.scatter(input_mat[0], input_mat[1], color='blue')
ax.scatter(output_mat[0], output_mat[1], color='red')

# outMat = array_multiply(identity_mat, input_mat)
# print(identity_mat @ input_mat)
# print(input_mat * 10)

# Plotting x-axis (horizontal line at y=0) and y-axis (vertical line at x=0)
ax.axhline(0, color='black',linewidth=0.5)  # Horizontal line for x-axis
ax.axvline(0, color='black',linewidth=0.5)  # Vertical line for y-axis

# Set labels for x and y axes
ax.set_xlabel('X-axis')
ax.set_ylabel('Y-axis')

ax.set_xlim([-10, 10])
ax.set_ylim([-10, 10])

# Set labels and title
ax.set_title('Vectors in 2D space')
plt.show()
