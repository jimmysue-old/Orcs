#pragma once

#include <opencv2/core.hpp>


class MatchPoint
{
public:
	MatchPoint(){}
	MatchPoint(cv::Point2f p1, cv::Point2f p2) :p1(p1), p2(p2){}
	MatchPoint(double x1, double y1, double x2, double y2) :p1(x1, y1), p2(x2, y2) {}
public:
	cv::Point2f p1, p2;
	double corr;
	double angle;
	double speed;
};


class Matcher : public cv::Algorithm
{
public:
	virtual ~Matcher();

	
	/*
	Main routine of a matcher to perform matching
	*/
	CV_WRAP virtual void compute(cv::InputArray leftImage,  cv::InputArray rightImage,
		CV_OUT std::vector<MatchPoint>& matchpoints);
	CV_WRAP virtual void compute(cv::InputArray leftImage, cv::InputArray rightImage, 
		std::vector<cv::KeyPoint> &leftKpts, std::vector<cv::KeyPoint> &rightKpts, std::vector<cv::DMatch> & dMatches);
	
};