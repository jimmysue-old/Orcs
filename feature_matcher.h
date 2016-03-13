#pragma once

#include "matcher.h"
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>

class FeatureMatcher : public Matcher
{
public:

public:
	static cv::Ptr<FeatureMatcher> create(const cv::Ptr<cv::FeatureDetector> &ft_detector);
};