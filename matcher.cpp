#include "matcher.h"

Matcher::~Matcher()
{
}

CV_WRAP void Matcher::compute(cv::InputArray left_image, cv::InputArray right_image, CV_OUT CV_IN_OUT std::vector<MatchPoint>& matchpoints)
{
	return CV_WRAP void();
}

CV_WRAP void Matcher::compute(cv::InputArray leftImage, cv::InputArray rightImage, std::vector<cv::KeyPoint>& leftKpts, std::vector<cv::KeyPoint>& rightKpts, std::vector<cv::DMatch>& dMatches)
{
	return CV_WRAP void();
}
