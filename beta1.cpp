#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <opencv2/gpu/gpu.hpp>


using namespace cv;
using namespace std;


int main()
{
    
    
	
	Mat img = imread("/Users/dutt/Downloads/RoadCr.jpg",CV_LOAD_IMAGE_COLOR); // (158,158,158)

   

    cout<<img.size();
    Mat img2 = Mat::zeros(1000,1000,CV_8UC3);
    Mat omg = Mat::zeros(img2.size(),CV_8UC3);
    
    Rect brect;
    brect.x = 250;
    brect.y =250;
    brect.width=img.cols;
    brect.height=img.rows;
    
    
    Mat destROI = img2(brect);
    img.copyTo(destROI);
    
     imshow("img2",img2);
    
    Mat hom;
    vector<Point2f> ipA;
    ipA.push_back(Point2f(250+213,250+245));
    ipA.push_back(Point2f(250+271,250+245));
    ipA.push_back(Point2f(250+111,250+4));
    ipA.push_back(Point2f(250+101,250+4));
    
    
    vector<Point2f> opA;
    opA.push_back(Point2f(250+213,250+485));
    opA.push_back(Point2f(250+271,250+485));
    opA.push_back(Point2f(250+271,250+4));
    opA.push_back(Point2f(250+213,250+4));
    
    hom=getPerspectiveTransform(ipA,opA);
    
    
    
    warpPerspective(img2, omg, hom, img2.size());
//    img, omg, hom);
    imshow("omg",omg);
    
    
    cv::waitKey();



}