#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "LearnOpenCV.h"
#include <iostream>
using namespace cv;

void StartUp()
{
	std::cout << "Hello" << "\n";
	std::cout << "What do you wanna do ?" << "\n";

	std::cout << "Enter 1 for ConvertToGrayScale, 2 for Blur, 3 for ToRed, 4 for ToGreen, 5 for ToBlue, 6 for Surbtract" << "\n";

	int choice;
	std::cin >> choice;

	switch (choice)
	{
	case 1 :
		ToGrayScale();
		break;
	case 2:
		Blur();
		break;
	case 3 :
		ToRed();
		break;
	case 4: 
		ToGreen();
		break;
	case 5 : 
		ToBlue();
		break;
	case 6 :
		Subtract();
		break;
	}
}

Mat LoadImg()
{
	std::cout << "Enter the target image path" << "\n";
	std::string path = "";
	std::cin >> path;
	return imread(path);
}

bool SaveImg(Mat img)
{
	std::cout << "Enter the save path" << "\n";
	std::string path = "";
	std::cin >> path;
	return imwrite(path, img);
}

void ToGrayScale()
{
	Mat img = LoadImg();
	std::cout << "IMAGE LOADED SUCCEFULLY" << "\n";


	Mat outputImg;
	cvtColor(img, outputImg,COLOR_BGR2GRAY);
	std::cout << "IMAGE CONVERTED TO GRAY SCALE" << "\n";
    

	SaveImg(outputImg);
	std::cout << "IMAGE SAVE SUCCEFULLY " << "\n";
}

void Blur()
{
	Mat srcImg = LoadImg();
	std::cout << "IMAGE LOADED SUCCEFULLY" << "\n";

	std::cout << "Enter kernel size " << "\n";
	int kernelSize; 
	std::cin >> kernelSize;

	Mat outputImg;
	blur(srcImg, outputImg, Size(kernelSize,kernelSize));

	SaveImg(outputImg);
	std::cout << "IMAGE SAVED SUCCEFULLY" << "\n";

}

void ToRed()
{
	Mat srcImg = LoadImg();
	
	Mat outputImg;
	bitwise_and(srcImg, Mat(srcImg.rows, srcImg.cols, CV_8UC3, Scalar(0, 0, 255)), outputImg);

	SaveImg(outputImg);
}

void ToGreen()
{
	Mat srcImg = LoadImg();

	Mat outputImg;
	bitwise_and(srcImg, Mat(srcImg.rows, srcImg.cols, CV_8UC3, Scalar(0,255, 0)), outputImg);

	SaveImg(outputImg);
}

void ToBlue()
{
	Mat srcImg = LoadImg();

	Mat outputImg;
	bitwise_and(srcImg, Mat(srcImg.rows, srcImg.cols, CV_8UC3, Scalar(255, 0,0)), outputImg);

	SaveImg(outputImg);
}

void Subtract()
{
	Mat srcImg1 = LoadImg();
	std::cout << "Image 1 loaded" << "\n";

	Mat srcImg2 = LoadImg();
	std::cout << "Image 2 loaded" << "\n";

	Mat outputImg;

	subtract(srcImg1, srcImg2, outputImg);


	SaveImg(outputImg);

}