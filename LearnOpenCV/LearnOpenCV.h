#pragma once


#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

void StartUp();

Mat LoadImg();

bool SaveImg(Mat img);

void ToGrayScale();

void Blur();