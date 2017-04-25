#include "fonctions.h"

std::vector<Mat*> get_letter(Mat image)
{
    std::vector< std::vector<Point> > contours;
    std::vector< std::vector<Point> > contours2;
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
           region_of_interest = Rect(p_max, p_min);
           if(region_of_interest.height > 10 && region_of_interest.width > 10)
           {
               Mat *tmp = new Mat(image(region_of_interest));
               resize(*tmp, *tmp, Size(HEIGHT, WIDTH));
               alphabet.push_back(tmp);
           }
         }
      return alphabet;
}



