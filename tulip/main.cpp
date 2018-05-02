#include <opencv2/opencv.hpp>
#include <iostream>
#include "tiny_obj_loader.h"

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

	std::string inputfile = "cylinder.obj";
	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;
	std::string err;
	bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &err, inputfile.c_str());

	if (!err.empty()) { // `err` may contain warning message.
		std::cerr << err << std::endl;
	}

	waitKey(0); // Wait for any keystroke in the window

	destroyWindow(windowName); // destroy the created window

	return 0;
}
