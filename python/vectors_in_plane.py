#!/usr/bin/python3
import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()
axe = fig.add_subplot()

ax = [0, 4]   # x-coordinates
ay = [0, 2]   # y-coordinates

bx = [0, -1]   # x-coordinates
by = [0, 2]   # y-coordinates

axe.scatter(ax, ay, color='red')
axe.scatter(bx, by, color='red')

axe.plot(ax, ay)
axe.plot(bx, by)

# Plotting x-axis (horizontal line at y=0) and y-axis (vertical line at x=0)
axe.axhline(0, color='black',linewidth=0.5)  # Horizontal line for x-axis
axe.axvline(0, color='black',linewidth=0.5)  # Vertical line for y-axis

# Set labels for x and y axes
axe.set_xlabel('X-axis')
axe.set_ylabel('Y-axis')


axe.set_xlim([-3, 10])
axe.set_ylim([-3, 10])

# Set labels and title
axe.set_title('Vectors in 2D space')

plt.show()
