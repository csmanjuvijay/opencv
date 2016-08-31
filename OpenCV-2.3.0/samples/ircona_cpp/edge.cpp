#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include<stdio.h>
using namespace cv;
using namespace std;

void help()
{
	cout <<"fruits.jpg is not found keep fruits.jpg in current folder\n" << endl;

}

int edgeThresh = 1;
Mat image, gray, edge, cedge;

int main( int argc, char** argv )
{
    printf("finding Canny edge detection on fruits.jpg \n");
    image = imread("./fruits.jpg", 1);
    if(image.empty())
    {
    	help();
        return -1;
    }
    cedge.create(image.size(), image.type());
    cvtColor(image, gray, CV_BGR2GRAY);
    // Show the image
	
    blur(gray, edge, Size(3,3));
 
    // Run the edge detector on grayscale
    printf("Canny edge detection calling \n");
    Canny(edge, edge, edgeThresh, edgeThresh*3, 3);
    cedge = Scalar::all(0);
 
    image.copyTo(cedge, edge);
    imwrite("./fruitedge.jpg",cedge);
    printf("fruitedge.jpg image created \n");
    return 0;
}
