#include "feature_matcher.h"


class FeatureMatcher_Impl : public FeatureMatcher
{
public:
	explicit FeatureMatcher_Impl(const cv::Ptr< cv::FeatureDetector> &fd);
};

cv::Ptr<FeatureMatcher> FeatureMatcher::create(const cv::Ptr<cv::FeatureDetector> &ft_detector)
{
	return cv::makePtr<FeatureMatcher_Impl>(ft_detector);
}

FeatureMatcher_Impl::FeatureMatcher_Impl(const cv::Ptr< cv::FeatureDetector> &fd)
{

}
