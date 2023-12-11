import cv2
import numpy as np
import math
import time

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

    rot_height = height * 2;
    rot_width = width * 2;
    rot_midy = rot_width / 2
    rot_midx = rot_height / 2

    rot_img = np.uint8(np.zeros((rot_height, rot_width, 3)))
    midy = width / 2
    midx = height / 2

    rads = math.radians(degree)

    mat = np.array([[math.cos(rads), -1.0 * math.sin(rads)],
                    [math.sin(rads), math.cos(rads)]])

    for i in range(height):
        for j in range(width):
            xin = (i-midx)
            yin = (j-midy)
            x = xin * mat[0][0] + yin * mat[1][0]
            y  = xin * mat[0][1] + yin * mat[1][1]
            x = int(round(x) + rot_midx)
            y = int(round(y) + rot_midy)

            rot_img[x,y] = image[i, j]

    return rot_img

def main():
    image = cv2.imread("lenna.png")
    i = 0;
    while (1) :
        i = i+10
        rotated_image = naive_image_rotate(image, i)
        cv2.imshow("Rotated image", rotated_image)
        cv2.waitKey(100)


if __name__=='__main__':
    main()
