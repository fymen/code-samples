#!/usr/bin/python3
import cv2
import numpy as np
import math
import time

import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Rotate image by two-dimensional matrix

def i3imshow(wname, img):
    while True:
        cv2.imshow(wname, img)
        k = cv2.waitKey(33)
        # Esc key to stop
        if k == 27:
            cv2.destroyAllWindows()
            return

def naive_image_rotate(image, degree):
    height = image.shape[0]
    width = image.shape[1]

    rot_height = height * 3;
    rot_width = width * 3;
    rot_midy = rot_width / 2
    rot_midx = rot_height / 2

    rot_img = np.uint8(np.zeros((rot_height, rot_width, 3)))
    midy = width / 2
    midx = height / 2

    rads = math.radians(degree)

    rot = np.array([[-1, 0],
                    [0, 1]])
    mat = np.array([[1, 1],
                    [0, 1]])

    color = np.array([[1, 0, 0],
                      [0, 1, 0],
                      [0, 0, 1]])
    mat = np.array([[math.cos(rads), -1.0 * math.sin(rads)],
                    [math.sin(rads), math.cos(rads)]])
    mat = mat @ rot

    for i in range(height):
        for j in range(width):
            xin = (i-midx)
            yin = (j-midy)
            x = xin * mat[0][0] + yin * mat[1][0]
            y  = xin * mat[0][1] + yin * mat[1][1]
            x = int(round(x) + rot_midx)
            y = int(round(y) + rot_midy)

            rot_img[x,y] = image[i, j] @ color

    return rot_img

def show_image_3d_gpt(img):
    img = cv2.resize(img, (120,90), interpolation= cv2.INTER_LINEAR)
    img_array = np.array(img)

    pixels = img_array.reshape((-1, 3))

    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    ax.scatter(pixels[:, 0], pixels[:, 1], pixels[:, 2], c = pixels / 255.0)

    # Set labels for each axis
    ax.set_xlabel('Red')
    ax.set_ylabel('Green')
    ax.set_zlabel('Blue')

    # Show plot
    plt.show()

def show_image_3d(img):
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')

    downscale_factor = int(img.shape[1] / 64)
    dimg = img[::downscale_factor, ::downscale_factor, :]

    float_list = [(item / 255)for item in dimg.reshape(-1)]
    fimg = np.array(float_list)

    colors = fimg.reshape(dimg.shape[0] * dimg.shape[1], 3);
    rgb = np.array_split(colors, 3, axis=1)

    ax.scatter(rgb[0], rgb[1], rgb[2], c=colors)

    ax.scatter(1, 0, 0, c=(1,0,0));
    ax.scatter(0, 1, 0, c=(0,1,0));
    ax.scatter(0, 0, 1, c=(0,0,1));

    ax.set_xlim([0, 1])
    ax.set_ylim([0, 1])
    ax.set_zlim([0, 1])
    plt.grid(True)
    plt.show()


def main():
    image = cv2.imread("../images/lenna.png")
    i = 180;

    rotated_image = naive_image_rotate(image, i)

    # show_image_3d(rotated_image)
    # show_image_3d_gpt(rotated_image)

    # i3imshow("test", rotated_image)
    while (1) :
        i = i+10
        rotated_image = naive_image_rotate(image, i)
        cv2.imshow("Rotated image", rotated_image)
        cv2.waitKey(100)

if __name__=='__main__':
    main()
