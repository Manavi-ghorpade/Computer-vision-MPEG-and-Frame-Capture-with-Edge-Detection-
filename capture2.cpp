#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define BILLION 1E9
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

// See www.asciitable.com
#define ESCAPE_KEY (27)
#define SYSTEM_ERROR (-1)
int main()
{
   VideoCapture cam0(0);
   namedWindow("video_display");
   	char winInput;
	double ti1 = 0;
	double ti2 = 0;
	double ti3 = 0;
	double c1 = 0;
	double c2 = 0;
	double c3 = 0;
        int f1 = 0;
	int f2 = 0;
	int f3 = 0;
	
   if (!cam0.isOpened())
   {
       exit(SYSTEM_ERROR);
   }

 
 cam0.set(CAP_PROP_FRAME_WIDTH, 640);
 cam0.set(CAP_PROP_FRAME_HEIGHT, 480);
	 
char a='n';
while (1)
      {
	struct timespec start1,start2,start3,end1,end2,end3;
        Mat frame;
	Mat frame_blur;
      	Mat frame_grey;
      	Mat frame_canny;
	Mat frame_sobel;
        Mat grad_x, grad_y;
        Mat abs_grad_x, abs_grad_y;  
	cam0.read(frame);
	cvtColor(frame,frame_grey,COLOR_BGR2GRAY);
        GaussianBlur(frame_grey,frame_blur,Size(3,3),0,0,BORDER_DEFAULT);
	

//Normal Video
clock_gettime(CLOCK_MONOTONIC, &start1);
if((winInput = waitKey(10)) == 'n'|| a=='n')
{	f1++;
	imshow("video_display", frame);
	a='n';
	if((winInput = waitKey(10)) == 's'|| (winInput = waitKey(10))=='c')
	{
		cout<<"Average of normal video = "<<f1/c1<<endl;
	}
}
clock_gettime(CLOCK_MONOTONIC, &end1);
	ti1=(end1.tv_sec-start1.tv_sec)+(end1.tv_nsec-start1.tv_nsec)/BILLION;
	c1+=ti1;

//Canny Edge
clock_gettime(CLOCK_MONOTONIC, &start2);
if(( winInput = waitKey(10)) == 'c'|| a=='c')
{	f2++;
	Canny(frame_blur,frame_canny,0,100,3);
        imshow("video_display", frame_canny);
	a='c';
	if((winInput = waitKey(10)) == 's'|| (winInput = waitKey(10))=='n')
	{
		
		cout<<"Average of Canny = "<<f2/c2<<endl;
	}
}	

clock_gettime(CLOCK_MONOTONIC, &end2);
	ti2=(end2.tv_sec-start2.tv_sec)+(end2.tv_nsec-start2.tv_nsec)/BILLION;
	c2+=ti2;

//Sobel Edge
clock_gettime(CLOCK_MONOTONIC, &start3);
if((winInput = waitKey(10)) == 's'|| a=='s')
{	f3++;
	Sobel(frame_blur, grad_x, CV_16S, 1, 0,1,1, 0, BORDER_DEFAULT);
        Sobel(frame_blur, grad_y, CV_16S , 0, 1,1,1,0,BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);
    	convertScaleAbs(grad_y, abs_grad_y);
    	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, frame_sobel);
	imshow("video_display",frame_sobel);
	a='s';
     	if((winInput = waitKey(10)) == 'n'|| (winInput = waitKey(10))=='c')
       	{	
		
		cout<<"Average of Sobel = "<<f3/c3<<endl;
       	}
}
clock_gettime(CLOCK_MONOTONIC, &end3);
	ti3=(end3.tv_sec-start3.tv_sec)+(end3.tv_nsec-start3.tv_nsec)/BILLION;
	c3+=ti3; 
       
if ((winInput = waitKey(10)) == ESCAPE_KEY)
        {
         break;
        }
	
}
destroyWindow("video_display");
};

