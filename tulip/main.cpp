#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat image = cv::imread("0.jpg");

	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); // wait for any key press
		return -1;
	}

	String windowName = "The Guitar"; // Name of the window

	namedWindow(windowName); // Create a window

	imshow(windowName, image); // Show our image inside the created window.

	waitKey(0); // Wait for any keystroke in the window

	destroyWindow(windowName); // destroy the created window

	return 0;
}
