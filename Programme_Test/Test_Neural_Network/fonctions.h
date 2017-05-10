#ifndef FONCTIONS_H
#define FONCTIONS_H
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include "Sources/Data.h"

#define HEIGHT 25
#define WIDTH 50
#define SIZE 6

using namespace cv;

std::vector<Mat*> get_letter(Mat image);
std::vector<Point> extractPoint(Mat img);
Data vecToData(std::vector<Point> dat);
int extractPointFromFile(std::string filename, int index, std::vector<Point> *patterns, string *name);
#endif // FONCTIONS_H
