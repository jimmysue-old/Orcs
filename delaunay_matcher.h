#pragma once

#include "matcher.h"


class DelauneyMatcher : public Matcher
{
public:
	static cv::Ptr<DelauneyMatcher> create(const std::vector<MatchPoint> match_points);
};

