#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include<stdio.h>
using namespace cv;
using namespace std;

void help()
{
	cout <<" fruits.jpg image not available,keep fruits.jpg in this directory \n" << endl;
}

int edgeThresh = 1;
Mat image, gray, edge, cedge;

// define a trackbar callback
void onTrackbar(int, void*)
{
    printf("function name=%s line name=%d\n",__func__,__LINE__);
    blur(gray, edge, Size(3,3));

    // Run the edge detector on grayscale
    printf("function name=%s line name=%d\n",__func__,__LINE__);
    Canny(edge, edge, edgeThresh, edgeThresh*3, 3);
    cedge = Scalar::all(0);
    printf("function name=%s line name=%d\n",__func__,__LINE__);
    
    image.copyTo(cedge, edge);
    imwrite("./edgelena.jpg",cedge);
//    imshow("Edge map", cedge);
}

int main( int argc, char** argv )
{
   // char* filename = argc == 2 ? argv[1] : (char*)"fruits.jpg";
    printf("function name=%s line name=%d\n",__func__,__LINE__);
   // image = imread("./fruits.jpg", 1);
    image = imread( "./lena.jpg", 1 );
    if(image.empty())
    {
    printf("function name=%s line name=%d\n",__func__,__LINE__);
    	help();
        return -1;
    }
   // help();
    printf("function name=%s line name=%d\n",__func__,__LINE__);
    cedge.create(image.size(), image.type());
    printf("function name=%s line name=%d\n",__func__,__LINE__);
    cvtColor(image, gray, CV_BGR2GRAY);

    // Create a window
  //  namedWindow("Edge map", 1);

    // create a toolbar
   // createTrackbar("Canny threshold", "Edge map", &edgeThresh, 100, onTrackbar);

    printf("function name=%s line name=%d\n",__func__,__LINE__);
    // Show the image
    onTrackbar(0, 0);

    // Wait for a key stroke; the same function arranges events processing
   // waitKey(0);

    return 0;
}
