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
	//��������
	cvNamedWindow("Example5-in");
	cvNamedWindow("Example5-out");

	//����ͼ����ʾ
	IplImage * in = cvLoadImage("leina2.jpg");
	if(in == NULL)
		return (-1);
	cvShowImage("Example5-in", in);

	// ����ͼ����ʾ
	//assert(in->width%2==0 && in->height%2==0); // ��debug���޷�������ʾ�ڶ���ͼ����release�п�����
	IplImage * out = doPyrDown(in);
	cvShowImage("Example5-out", out);

	cvWaitKey(0);
	cvReleaseImage(&in);
	cvReleaseImage(&out);
	cvDestroyWindow("Example5-in");
	cvDestroyWindow("Example5-out");

	return(0);
}
