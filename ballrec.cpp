#include <opencv2/opencv.hpp>

#include <iostream>

using namespace std;
using namespace cv;

int main()
{
  Mat image,image_gray,image_blur;
  image=imread("BallImages/ball2.jpg",CV_LOAD_IMAGE_COLOR);

  cvtColor(image,image_gray,CV_BGR2GRAY);
  GaussianBlur(image_gray,image_blur,Size(9,9),2,2);
  Mat bw=image_gray>190; //trying thresholding
  Mat bwb=image_blur>190;
  cout << "/* hello bitchess */" << '\n';
  imshow("readIM",image);
  imshow("grayScale",image_gray);
  imshow("blurred",image_blur);
  imshow("BlackAndWhite",bw);
  imshow("thresholding blur",bwb);
  waitKey(0);
  return 0;
}
