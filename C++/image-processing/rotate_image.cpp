#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
// using namespace std;

void i3imshow(auto *s, Mat& img)
{
  while (1) {
    imshow(s, img);
    int k = waitKey(0); // Wait for a keystroke in the window
    if (k == 27) {
      destroyAllWindows();
      return;
    }
  }
}

int main()
{
  std::string image_path = "../../images/lenna.png";
  Mat img = imread(image_path, IMREAD_COLOR);
  // Check for failure
  if (img.empty()) {
    std::cout << "Could not open or find the image" << std::endl;
    return -1;
  }

  i3imshow("test", img);

  return 0;
}
