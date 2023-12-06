#!/usr/bin/python3
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

x = [2, 0, 0, 2]   # x-coordinates
y = [0, 2, 0, 0]   # y-coordinates
z = [0, 2, 0, 0]   # z-coordinates

ax.scatter(x, y, z, color='red')
ax.plot(x, y, z)

xx, yy = np.meshgrid(x, y)
zz = yy

xx *= 2;
yy *= 2;
zz *= 2;

ax.scatter(4, 2, 2, color='red')

print(xx)
print(".........")
print(yy)
print(zz)

# plot the plane
ax.plot_surface(xx, yy, zz, alpha=0.2)


ax.set_xlim([-3, 10])
ax.set_ylim([-3, 10])
ax.set_zlim([-3, 10])

# Set labels and title
ax.set_xlabel('X-axis')
ax.set_ylabel('Y-axis')
ax.set_zlabel('Z-axis')
ax.set_title('Plane in 3D space')

plt.show()
