/**
 * @file Morphology_1.cpp
 * @brief Erosion and Dilation sample code
 * @author OpenCV team
 */

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;
Mat img_original;
char window_name[50] = "Image";
int bright = 150;
int contrast = 1;
void on_bright(int n, void*)
{
    Mat img_temp;
    img_original.convertTo(img_temp, -1, contrast, bright - 150);
    imshow(window_name, img_temp);
}
void brightnessandcontast()
{
    namedWindow("B&GControl", WINDOW_AUTOSIZE);
    createTrackbar("Brightness", "B&GControl", &bright, 300, on_bright);
    createTrackbar("Contrast", "B&GControl", &contrast, 4, on_bright);
}
int main(int argc, char** argv)
{
    img_original = imread("C:\\Users\\HP\\Downloads\\lovely-beach-picture-beautiful-260nw-1554809048.jpg", 1);
    const char* pz_original_image = "Original Image";
    if (img_original.empty())
    {
        cout << "Could not open or find the image!\n" << endl;
        cin.get();
        return -1;
    }
    namedWindow(pz_original_image, WINDOW_AUTOSIZE);
    imshow(pz_original_image, img_original);
    brightnessandcontast();
    const char* pz_rotated_image = "Rotated Image";
    namedWindow(pz_rotated_image, WINDOW_AUTOSIZE);
    int iAngle = 45;
    createTrackbar("ANGLE", pz_rotated_image, &iAngle, 360);
    int iImageHeight = img_original.rows / 2;
    int iImageWidth = img_original.cols / 2;
    while (true)
    {
        Mat matRotation = getRotationMatrix2D(Point(iImageWidth, iImageHeight), (iAngle - 180), 1);
        Mat imgRotated;
        warpAffine(img_original, imgRotated, matRotation, img_original.size());
        imshow(pz_rotated_image, imgRotated);
        int iRet = waitKey(30);
        if (iRet == 27)
        {
            break;
        }

    }
    return 0;

}
    