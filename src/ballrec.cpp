#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
  Mat image;
  image=imread("ball2.jpg",CV_LOAD_IMAGE_COLOR);

  cout << "/* hello bitchess */" << '\n';
  imshow("readIM",image);
  waitKey(0);
  return 0;
}
