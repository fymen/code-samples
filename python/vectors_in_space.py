#!/usr/bin/python3
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import math

def plot_pipe():
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    # Translation matrix
    mat = np.array([[1, 0, 0, 5],
                    [0, 1, 0, 5],
                    [0, 0, 1, 5],
                    [0, 0, 0, 1]])

    # Rotation matrix
    rads = math.radians(-50)
    rotate_mat = np.array([[1, 0, 0, 0],
                           [0, math.cos(rads), -1.0 * math.sin(rads), 0],
                           [0, math.sin(rads), math.cos(rads), 0],
                           [0, 0, 0, 1]])

    x = np.linspace(-5, 5, 100)
    y = np.linspace(-5, 5, 100)

    xx, yy = np.meshgrid(x, y)
    zz = np.sqrt(xx**2 + yy**2)

    xx = xx.reshape(-1);
    yy = yy.reshape(-1);
    zz = zz.reshape(-1);

    for i in range(xx.shape[0]):
        tmp = rotate_mat @ mat @ np.array([[xx[i]],
                                           [yy[i]],
                                           [zz[i]],
                                           [1.0]])
        xx[i] = tmp[0][0];
        yy[i] = tmp[1][0];
        zz[i] = tmp[2][0];

    xx = xx.reshape(100, 100)
    yy = yy.reshape(100, 100)
    zz = zz.reshape(100, 100)

    # plot the plane
    ax.plot_surface(xx, yy, zz, alpha=0.2, color="red")


    ax.set_xlim([-20, 20])
    ax.set_ylim([-20, 20])
    ax.set_zlim([-20, 20])

    # Set labels and title
    ax.set_xlabel('X-axis')
    ax.set_ylabel('Y-axis')
    ax.set_zlabel('Z-axis')
    ax.set_title('Plane in 3D space')

    plt.show()

def main():
    plot_pipe()

if __name__=='__main__':
    main()
