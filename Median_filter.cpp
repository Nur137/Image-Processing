#include <iostream>
#include <math.h>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
using namespace cv;
using namespace std;


int main() {
	int mask_size;
	cout << "Mask Size? : ";
	cin >> mask_size;

	if (mask_size % 2 == 0)
	{
		cout << "Invalid mask_size";
		return 0;
	}

	Mat image = imread("lena.jpg", 0);
	imshow("Original Image", image);


	int size = mask_size / 2;
	int rows = image.rows;
	int cols = image.cols;


	Mat med_filtered;
	copyMakeBorder(image, med_filtered, size, size, size, size, BORDER_REPLICATE);
	for (int x = size; x < rows-size; x++)
	{
		uchar *ptr_in = image.ptr<uchar>(x);
		uchar *mdptr_out = med_filtered.ptr<uchar>(x-size);
	
		for (int y = size; y < cols-size; y++)
		{
			vector<int> values;
			for (int i = -size; i <= size; i++)
			{

				for (int j = -size; j <= size; j++)
				{
					int cindex = y + j;
					int new_val = (int)((ptr_in+i)[cindex]);
					values.push_back(new_val);
				}
			}
			int pos = (mask_size*mask_size) / 2;
			sort(values.begin(),values.end());
			mdptr_out[y-size]=values[pos];
		}
	}
	imshow("Median Filter", med_filtered);
	waitKey(0);
	return 0;
}
