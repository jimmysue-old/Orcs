#pragma once

#include <opencv2/core.hpp>


class MatchPoint
{

};


class Matcher : public cv::Algorithm
{
public:
	virtual ~Matcher();

	
	/*
	Main routine of a matcher to perform matching
	*/
	CV_WRAP virtual void compute(cv::InputArray left_image,  cv::InputArray right_image,
		CV_OUT CV_IN_OUT std::vector<MatchPoint>& matchpoints);

	
};