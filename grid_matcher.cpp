#include "grid_matcher.h"

#include <cstdio>
#include <cstdlib>

using namespace std;

class GridMatcher_Impl : public GridMatcher
{
public:
	explicit GridMatcher_Impl(std::size_t dx, std::size_t dy);
};

cv::Ptr<GridMatcher> GridMatcher::create(std::size_t dx, std::size_t dy)
{
	return cv::makePtr<GridMatcher_Impl>(dx, dy);
}

GridMatcher_Impl::GridMatcher_Impl(std::size_t dx, std::size_t dy)
{

}

