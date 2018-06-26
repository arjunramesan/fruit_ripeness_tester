#include <opencv\cvaux.h>
#include <opencv\highgui.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
Mat img;
char _filename[1024];
HOGDescriptor hog;
hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
namedWindow("people detector", 1);
//argv[1]="r1.jpg";
//img = imread(argv[1]);
CvCapture* cap=cvCreateCameraCapture(0);
img=cvQueryFrame(cap);
for(;;){
img=cvQueryFrame(cap);
fflush(stdout);
vector<Rect> found, found_filtered;

// run the detector with default parameters. to get a higher hit-rate
// (and more false alarms, respectively), decrease the hitThreshold and
// groupThreshold (set groupThreshold to 0 to turn off the grouping completely).
int can = img.channels();
hog.detectMultiScale(img, found, 1, Size(8,8), Size(32,32), 1.01, 2);

size_t i, j;
for( i = 0; i < found.size(); i++ ){
Rect r = found[i];
for( j = 0; j < found.size(); j++ )
if( j != i && (r & found[j]) == r)
break;
if( j == found.size() )
found_filtered.push_back(r);
}
for( i = 0; i < found_filtered.size(); i++ ){
Rect r = found_filtered[i];
// the HOG detector returns slightly larger rectangles than the real objects.
// so we slightly shrink the rectangles to get a nicer output.
r.x += cvRound(r.width*0.1);
r.width = cvRound(r.width*0.8);
r.y += cvRound(r.height*0.07);
r.height = cvRound(r.height*0.8);
rectangle(img, r.tl(), r.br(), cv::Scalar(0,255,0), 3);
}
imshow("people detector", img);
cvWaitKey(1);
}
return 0;
}