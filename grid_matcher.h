#pragma once
#include <iostream>
#include <cstdlib>
#include "matcher.h"

using namespace std;
class GridMatcher : public Matcher
{
public:
	static cv::Ptr<GridMatcher> create(std::size_t dx, std::size_t dy);
};
