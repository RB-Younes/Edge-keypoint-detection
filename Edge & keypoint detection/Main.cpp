#include <opencv2/core/core.hpp>
#include <iostream>
#include "tpEdge_keypoint.h"

using namespace std;
using namespace cv;

int main() {
	String filename = "corridor.png";
	Mat src = imread(samples::findFile(filename), IMREAD_GRAYSCALE);
	// Check if image is loaded fine
	if (src.empty()) {
		printf(" Error opening image\n");
		return -1;
	}
	Mat res = HoughLines(src);
	// Show results
	imshow("Source", src);
	imshow("Detected Lines (in red) - Standard Hough Line Transform", res);
	// Wait and Exit
	waitKey();
	return 0;
}