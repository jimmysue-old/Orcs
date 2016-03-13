#include "delaunay_matcher.h"


class DelauneyMatcher_Impl : public DelauneyMatcher
{
public :
	explicit DelauneyMatcher_Impl(const std::vector<MatchPoint> match_points);
};



cv::Ptr<DelauneyMatcher> DelauneyMatcher::create(const std::vector<MatchPoint> match_points)
{
	return cv::Ptr<DelauneyMatcher>();
}

DelauneyMatcher_Impl::DelauneyMatcher_Impl(const std::vector<MatchPoint> match_points) 
{

}
