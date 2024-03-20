#include "tpEdge_keypoint.h"
#include <opencv2/core.hpp>
#include "opencv2/imgproc.hpp"


using namespace cv;
using namespace std;

cv::Mat  HoughLines(Mat src_img) {

	Mat res = src_img.clone();
	Mat cdst,dst;

	Canny(src_img, res, 50, 200, 3);

	// Copy edges to the images that will display the results in BGR
	cvtColor(res, cdst, COLOR_GRAY2BGR);

	// Standard Hough Line Transform
	vector<Vec2f> lines; // will hold the results of the detection
	HoughLines(res, lines, 1, CV_PI / 190, 180, 0, 0); // runs the actual detection
	// Draw the lines
	for (size_t i = 0; i < lines.size(); i++)
	{
		float rho = lines[i][0], theta = lines[i][1];
		Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a * rho, y0 = b * rho;
		pt1.x = cvRound(x0 + 1000 * (-b));
		pt1.y = cvRound(y0 + 1000 * (a));
		pt2.x = cvRound(x0 - 1000 * (-b));
		pt2.y = cvRound(y0 - 1000 * (a));
		line(cdst, pt1, pt2, Scalar(0, 0, 255), 3, LINE_AA);
	}

	return cdst;

}
