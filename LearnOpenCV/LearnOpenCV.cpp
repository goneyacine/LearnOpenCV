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

	std::cout << "Enter 1 for ConvertToGrayScale" << "\n";

	int choice;
	std::cin >> choice;

	switch (choice)
	{
	case 1 :
		ToGrayScale();
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