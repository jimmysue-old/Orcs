#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>
#include "matcher.h"
#include "grid_matcher.h"

using namespace std;
using namespace cv;

int main(int argc, char ** argv)
{
	string leftImageName = "D:\\sjinz\\Documents\\git\\Orcs\\test1.jpg";
	string rightImageName = "D:\\sjinz\\Documents\\git\\Orcs\\test2.jpg";

	Mat imageLeft, imageRight;
	imageLeft = imread(leftImageName);
	imageRight = imread(rightImageName);
	
	cv::Ptr<Matcher> mc = GridMatcher::create(21, 100, 0, 0, 20, 0.9);

	vector<KeyPoint> leftKpts, rightKpts;
	vector<DMatch> dMatches;
	mc->compute(imageLeft, imageRight, leftKpts, rightKpts, dMatches);
	Mat matchResult;
	drawMatches(imageLeft, leftKpts, imageRight, rightKpts, dMatches, matchResult);
	imshow("result", matchResult);
	waitKey(0);
}