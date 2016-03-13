#include "grid_matcher.h"

#include <cstdio>
#include <cstdlib>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;
class GridMatcher_Impl : public GridMatcher
{
public:
	
	explicit GridMatcher_Impl(size_t refWin, size_t searchWin, int xOff, int yOff, size_t step, double corrThreshold);
	CV_WRAP virtual void compute(cv::InputArray left_image, cv::InputArray right_image,
		CV_OUT std::vector<MatchPoint>& matchpoints);
	CV_WRAP virtual void compute(cv::InputArray leftImage, cv::InputArray rightImage,
		std::vector<cv::KeyPoint> &leftKpts, std::vector<cv::KeyPoint> &rightKpts, std::vector<cv::DMatch> & dMatches);
private:
	
private:
	size_t refWin, searchWin, step; 
	double corrThreshold; 
	int xOff, yOff;
};



cv::Ptr<GridMatcher> GridMatcher::create(size_t refWin, size_t searchWin, int xOff, int yOff, size_t step, double corrThreshold)
{
	return cv::makePtr<GridMatcher_Impl>(refWin, searchWin, xOff, yOff, step, corrThreshold);
}




GridMatcher_Impl::GridMatcher_Impl(size_t _refWin, size_t _searchWin, int _xOff, int _yOff, size_t _step, double _corrThreshold)
	:refWin(_refWin), searchWin(_searchWin), xOff(_xOff), yOff(_yOff), step(_step), corrThreshold(_corrThreshold)
{
	if (refWin <= 2) refWin = 3;
	if (refWin % 2 != 1) ++refWin;

	if (searchWin <= refWin) searchWin = refWin + 1;
	if (searchWin % 2 != 1) ++searchWin;

	if (step <= 0) step = 1;
}

CV_WRAP void GridMatcher_Impl::compute(cv::InputArray _left, cv::InputArray _right, CV_OUT std::vector<MatchPoint>& matchpoints)
{
	/*Mat leftImage = _left.getMat();
	Mat rightImage = _right.getMat();
	CV_Assert(leftImage.empty() || rightImage.empty());
	CV_Assert(leftImage.size() == rightImage.size());
	matchpoints.clear();
	

	size_t resultWin = searchWin - refWin;

	Mat resultMat(resultWin, resultWin, CV_64FC1);

	size_t startX, startY, endX, endY;

	startX = cv::max(refWin / 2, searchWin / 2 - xOff);
	startY = cv::max(refWin / 2, searchWin / 2 - yOff);

	endX = cv::min(rightImage.size().width - startX - 1, )
	endY = cv::min()
	endX = rightImage.size().width - startX;
	endY = rightImage.size().height - startY;
	
	size_t xOffRef, yOffRef;
	size_t xOffSearch, yOffSearch;
	xOffRef = yOffRef = refWin / 2;
	xOffSearch = yOffSearch = searchWin / 2;

	cv::Rect refRegion, searchRegion;
	cv::Mat  refImage, searchImage;

	double minVal, maxVal;
	cv::Point minLoc, maxLoc;

	

	for (size_t x = startX; x <= endX; x += step)
		for (size_t y = startY; y <= endY; y += step)
		{
			refRegion.x = x - xOffRef;
			refRegion.y = y - yOffRef;
			refRegion.width = refWin;
			refRegion.height = refWin;

			searchRegion.x = x + xOff - xOffSearch;
			searchRegion.y = y + yOff - yOffSearch;
			searchRegion.width = searchWin;
			searchRegion.height = searchWin;

			refImage = leftImage(refRegion);
			searchImage = rightImage(searchRegion);

			cv::matchTemplate(refImage, searchImage, resultMat, TM_CCOEFF_NORMED);
			cv::minMaxLoc(resultMat, &minVal, &maxVal, &minLoc, &maxLoc);
			
			if (maxVal >= corrThreshold) {
				double x1, y1, x2, y2;

				x1 = x;
				y1 = y;

				x2 = searchRegion.x + maxLoc.x;
				y2 = searchRegion.y + maxLoc.y;
				MatchPoint mp(x1, y1, x2, y2);
				mp.corr = maxVal;
				matchpoints.push_back(mp);
			}
		}*/
	return CV_WRAP void();
}

CV_WRAP void GridMatcher_Impl::compute(cv::InputArray _left, cv::InputArray _right, std::vector<cv::KeyPoint>& leftKpts, std::vector<cv::KeyPoint>& rightKpts, std::vector<cv::DMatch>& dMatches)
{
	Mat leftImage = _left.getMat();
	Mat rightImage = _right.getMat();
	/*CV_Assert(leftImage.empty() || rightImage.empty());
	CV_Assert(leftImage.size() == rightImage.size());*/
	
	leftKpts.clear();
	rightKpts.clear();
	dMatches.clear();

	size_t resultWin = searchWin - refWin;

	Mat resultMat(resultWin, resultWin, CV_64FC1);

	size_t startX, startY, endX, endY;

	startX = cv::max(refWin / 2, searchWin / 2 - xOff);
	startY = cv::max(refWin / 2, searchWin / 2 - yOff);

	endX = cv::min(leftImage.size().width - refWin / 2 - 1, rightImage.size().width - searchWin / 2 - xOff - 1);
	endY = cv::min(leftImage.size().height - refWin / 2 - 1, rightImage.size().height - searchWin / 2 - yOff - 1);
	size_t xoff, yoff;
	xoff = searchWin / 2;
	yoff = searchWin / 2;

	size_t xOffRef, yOffRef;
	size_t xOffSearch, yOffSearch;
	xOffRef = yOffRef = refWin / 2;
	xOffSearch = yOffSearch = searchWin / 2;

	cv::Rect refRegion, searchRegion;
	cv::Mat  refImage, searchImage;

	double minVal, maxVal;
	cv::Point minLoc, maxLoc;

	cv::KeyPoint lKpt, rKpt;
	cv::DMatch  dMatch;

	for (size_t x = startX; x <= endX; x += step)
		for (size_t y = startY; y <= endY; y += step)
		{
			refRegion.x = x - xOffRef;
			refRegion.y = y - yOffRef;
			refRegion.width = refWin;
			refRegion.height = refWin;

			searchRegion.x = x - xOffSearch;
			searchRegion.y = y - yOffSearch;
			searchRegion.width = searchWin;
			searchRegion.height = searchWin;

			refImage = leftImage(refRegion);
			searchImage = rightImage(searchRegion);
			/*imshow("left", refImage); waitKey(0);
			imshow("right", searchImage); waitKey(0);*/
			cv::matchTemplate(refImage, searchImage, resultMat, TM_CCOEFF_NORMED);
			cv::minMaxLoc(resultMat, &minVal, &maxVal, &minLoc, &maxLoc);
			/*cout << resultMat << endl;*/

			if (maxVal >= corrThreshold) {

				double x1, y1, x2, y2;
				x1 = x;
				y1 = y;
				x2 = searchRegion.x + maxLoc.x + xOffRef;
				y2 = searchRegion.y + maxLoc.y + yOffRef;		
				lKpt.pt.x = x1;
				lKpt.pt.y = y1;
				rKpt.pt.x = x2;
				rKpt.pt.y = y2;

				leftKpts.push_back(lKpt);
				rightKpts.push_back(rKpt);
				dMatch.queryIdx = leftKpts.size() - 1;
				dMatch.trainIdx = leftKpts.size() - 1;
				dMatches.push_back(dMatch);
			}
		}
	return CV_WRAP void();
}

