#include "fonctions.h"

std::vector<Mat*> get_letter(Mat image)
{
    std::vector< std::vector<Point> > contours;
    std::vector< std::vector<Point> > contours2;
    std::vector< std::vector<Point> > contours3;
    std::vector<Vec4i> hierarchy;
    std::vector<Mat*> alphabet;
    Mat imgcpy;
    Point p_max, p_min;
    Rect region_of_interest;
    imgcpy = image.clone();
    threshold(imgcpy, imgcpy, 240, 255, THRESH_BINARY);
    findContours(imgcpy,contours,hierarchy, RETR_TREE,CV_CHAIN_APPROX_SIMPLE );
    int father;
    for(unsigned int i = 0; i < contours.size(); i++ )
    {
        if((hierarchy[i])[3] < 0)
        {
               father = i;
               break;
        }
    }
    for(unsigned int i = 0; i < contours.size(); i++ )
    {
        if((hierarchy[i])[3] == father)
        {
               contours2.push_back(contours[i]);
        }
    }
    for(unsigned int i = 0; i < contours2.size(); i++ )
    {
        p_max.x = (contours2[i])[0].x;
        p_max.y = (contours2[i])[0].y;
        p_min.x = (contours2[i])[0].x;
        p_min.y = (contours2[i])[0].y;
        for(unsigned int j = 0; j < contours2[i].size(); j++)
        {
            p_max.x = max(p_max.x, (contours2[i])[j].x);
            p_max.y = max(p_max.y, (contours2[i])[j].y);
            p_min.x = min(p_min.x, (contours2[i])[j].x);
            p_min.y = min(p_min.y, (contours2[i])[j].y);
        }
        p_max.x += 5;
        p_max.y += 5;
        p_min.x -= 5;
        p_min.y -= 5;
        region_of_interest = Rect(p_max, p_min);
        if(region_of_interest.height > 10 && region_of_interest.width > 10)
        {
            Mat *tmp = new Mat(image(region_of_interest));
            resize(*tmp, *tmp, Size(HEIGHT, WIDTH));
            alphabet.push_back(tmp);
            //delete tmp;
        }
    }
      return alphabet;
}
std::vector<Point> extractPoint(Mat img) {
    Mat thresholded;
    threshold( img, thresholded, 205, 255, THRESH_BINARY );
    bitwise_not(thresholded, thresholded);
    Mat skel(thresholded.size(), CV_8UC1, cv::Scalar(0));
    Mat temp;
    Mat eroded;
    Mat element = cv::getStructuringElement(cv::MORPH_CROSS, cv::Size(3, 3));
    bool done;
    do
    {
      cv::erode(thresholded, eroded, element);
      cv::dilate(eroded, temp, element);
      cv::subtract(thresholded, temp, temp);
      cv::bitwise_or(skel, temp, skel);
      eroded.copyTo(thresholded);
      done = (cv::countNonZero(thresholded) == 0);
    } while (!done);
    std::vector<Point> corners;
    std::vector<Point> patterns;
    Point tmp;
    goodFeaturesToTrack(skel,corners, SIZE, 0.01, 8, noArray(), 3, true);
    for(int i = 1; i < corners.size(); i++)
    {
        tmp.x = corners[i].x-corners[i-1].x;
        tmp.y = corners[i].y-corners[i-1].y;
        patterns.push_back(tmp);
    }
    if(patterns.size() != 5) {
        for(int i = patterns.size(); i < 5; i++) {
            tmp.x = 0;
            tmp.y = 0;
            patterns.push_back(tmp);
        }
    }
    return patterns;
}
Data vecToData(std::vector<Point> dat) {
    Data data;
    for(int i = 0; i < dat.size(); i++) {
        data.add_data(dat[i].x);
        data.add_data(dat[i].y);
    }
    return data;
}
 int extractPointFromFile(std::string filename, int index, std::vector<Point> *patterns, std::string *name) {
    std::ifstream file;
    std::string input, parsed;
    Point tmp;
    file.open(filename);
    for(int i = 0; i <= index; i++) {
        if(!getline(file, input)) return 0;
    }
    std::stringstream input_stringstream(input);
    getline(input_stringstream, parsed, ';');
    *name = parsed;
    for(int i = 0; i < 5; i++) {
        getline(input_stringstream, parsed, ';');
        tmp.x = stoi(parsed);
        getline(input_stringstream, parsed, ';');
        tmp.y = stoi(parsed);
        patterns->push_back(tmp);
    }
    file.close();
    return 1;
}


