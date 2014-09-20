#include "cv.h"
#include "highgui.h"

//IplImage * doPyrDown(IplImage* in, int filter = IPL_GAUSSIAN_5x5);
IplImage * doPyrDown(IplImage* in, int filter = IPL_GAUSSIAN_5x5)
{
	IplImage * out = cvCreateImage(cvSize(in->width/2, in->height/2), in->depth, in->nChannels);
	cvPyrDown(in, out);

	return(out);
}

int main()
{
	//创建窗口
	cvNamedWindow("Example5-in");
	cvNamedWindow("Example5-out");

	//载入图像并显示
	IplImage * in = cvLoadImage("leina2.jpg");
	if(in == NULL)
		return (-1);
	cvShowImage("Example5-in", in);

	// 缩放图像并显示
	//assert(in->width%2==0 && in->height%2==0); // 在debug中无法正常显示第二幅图像，在release中可运行
	IplImage * out = doPyrDown(in);
	cvShowImage("Example5-out", out);

	cvWaitKey(0);
	cvReleaseImage(&in);
	cvReleaseImage(&out);
	cvDestroyWindow("Example5-in");
	cvDestroyWindow("Example5-out");

	return(0);
}
