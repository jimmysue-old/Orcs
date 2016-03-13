#pragma once
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "matcher.h"

using namespace std;
class GridMatcher : public Matcher
{
public:

	
	static cv::Ptr<GridMatcher> create(size_t refWin, size_t searchWin, int xOff = 0, int yOff = 0, size_t step = 1, double corrThreshold = 0.7);
};
