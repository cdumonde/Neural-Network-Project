#ifndef FONCTIONS_H
#define FONCTIONS_H
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

#define HEIGHT 50
#define WIDTH 50

using namespace cv;

std::vector<Mat*> get_letter(Mat image);
#endif // FONCTIONS_H
