#include <iostream>
#include <math.h>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
using namespace cv;
using namespace std;

int main()
{
	// Initializing and reading input image 
	Mat inputImage=imread("lena.jpg", 0);

	// Counting total number of rows and columns
	int rows = inputImage.rows ;
	int cols = inputImage.cols;

	// Initializing output image (all zero intensity pixels) where size and type is as like as input image 
	Mat outputImage = Mat::zeros(inputImage.rows, inputImage.cols, inputImage.type());

	for (int i = 0; i < rows; i++)
	{
		// Pointing starting of row of input and output image
		uchar *ptrIn = inputImage.ptr <uchar>(i);
		uchar *ptrOut = outputImage.ptr <uchar>(i);

		for (int j = 0; j < cols; j++)
		{
			// taking intensity value frim input image
			int intensity = ptrIn[j];
			
			// Forming output negative image
			ptrOut[j] = 255 - intensity;
		}
	}

	imshow("Original Image",inputImage);
	imshow("Negative Image", outputImage);
	
	//Waiting for key press for program termination 
	waitKey(0);
}