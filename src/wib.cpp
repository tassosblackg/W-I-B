/**wib.cpp
**where is ball project- detection code
**ball recognition by create a circle around the obj
**|author:soylisK |email:soylis.k@gmail.com|
**/

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

void help();
void detectBallnDraw(string img_file);

/*main variables*/
CascadeClassifier ball_casc;
string cascade_file ="../../data/cascade.xml"; //file created by opencv_traincascade

int main(int argc, char const *argv[])
{
  /*check argv if there is any problem*/
  if(argc<2)
  {
    cout<<"You doesn't insert an image file name"<<endl;
    cout<<"Use -help to see how to.."<<endl;
    exit(1);
  }
  else if(argc>2)
  {
    cout<< "Too many arguments..Error"<<endl;
  }
  else
  {
    string input= argv[1]; //take input file name

    /*call help or continue to the program*/
    if((input.compare("-help")==0)||(input.compare("help")==0)) //if you asked for help then call help()
    {
        help();
    }
    else
    {

        cout << "/* Where is ball? Searching.. */" << '\n';
        /*Load cascade.xml to cascade obj*/
        if(!ball_casc.load(cascade_file))
        {
          cout<<"Error during loading cascade.xml"<<endl;
          return -1;
        }
        else
          detectBallnDraw(input);
      }

    }

      waitKey(0);
  return 0;
}

/*help prints */
void help()
{
  cout<<"_______________________________________________________________\n";
  cout<<"To run the programm.."<<endl;
  cout<<"./wib image_file_name"<<endl;
  cout<<"e.g ./wib ball.jpg"<<endl;
  cout<<"note that img file must in the same folder.."<<endl;
  cout<<"else you have to use full path like /somedir/ball.jpg"<<endl;
  cout<<"simple as that.."<<endl;
  cout<<"_______________________________________________________________\n"<<endl;
}
void detectBallnDraw(string img_file)
{
  Mat image,img_gray,img_blur;
  image=imread(img_file.c_str(),CV_LOAD_IMAGE_COLOR);
  if(!image.data)
  {
    cout<<"Image file error. Image can't be read.."<<endl;
    exit(EXIT_FAILURE);
  }
  Mat resized_img(Size(320, 240), CV_8UC3);
	resize(image, resized_img, resized_img.size());
  image = resized_img.clone();

  cvtColor(image,img_gray,CV_BGR2GRAY); //convert to gray scale
  //GaussianBlur(img_blur,img_gray,Size(9,9),1,1); //reduce noise in img
  //Histogram equalization ??
  //equalizeHist( img_gray, img_gray );

  vector<Rect> balls;

  //Detect ball
  ball_casc.detectMultiScale( img_gray, balls, 1.1, 5, 8, Size(16, 16) );
  cout<<"*/"<<balls.size()<<endl;

  //Mat img=image.clone();
  //Draw the detected obj
  //Point_ <int> center;
  //int radius;
  for( unsigned int i = 0; i < balls.size(); i++ )
 {
    Point center( balls[i].x + cvRound(balls[i].width*0.5), cvRound(balls[i].y + balls[i].height*0.5) );
    cout<<"balls.x= "<<balls[i].x<<",y= "<<balls[i].y <<endl;
    cout<<"center= "<<center<<endl;
    cout << "ball[i]" <<balls[i] <<endl;
    circle(image, center, cvRound(balls[i].width*0.5), Scalar( 255, 0, 255 ), 2, 8, 1 );
    Mat ballROI = image( balls[i] );
    imshow("ROI",ballROI);
}




  imshow("Detect_Ball",image); //show results
}
