/*$ ffmpeg -i input.mp4 -f image2pipe -vcodec ppm pipe:1 | ./rolling-shutter | x264 -o output.mp4 /dev/stdin

  https://nullprogram.com/blog/2017/07/02/
  https://nullprogram.com/blog/2017/11/03/
 */
#include <stdio.h>
#include <stdlib.h>

int read_frame()
{
     char head[2] = {0};
     int w;
     int h;
     int bitdepth;
     int size;

     char *line = (char*)malloc(w*3);

     if (scanf("%s %d %d %d\n", head, &w, &h, &bitdepth) < 4)
          return -1;

     /* printf("head: %s %d %d\n", head, w, h, bitdepth); */
     printf("P6\n%d %d\n255\n", w, h);
     for (int i = 0; i < h; i++) {
          size = fread(line, w*3, 1, stdin);
          if (size > 0)
               fwrite(line, w*3, 1, stdout);
     }

     return 0;
}

int main(int argc, char** argv)
{
     while (!read_frame())
          ;
     return 0;
}
