#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
int main()
{
	cv::Mat img(300, 200, CV_8SC1,cv::Scalar(100));

	std::cout << "img = " << "\n";
	std::cout << img;
	std::cout << "\n";
	
	cv::imshow("image", img);
	cv::waitKey(0);
	return 0;
}