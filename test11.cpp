#include <iostream>
#include <vector>



#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc_c.h"
#include <direct.h>
#include <fstream>

using namespace std;
using namespace cv;

int test11(int argc, char *argv[])
{
	string path="H:/��Ƶ�泵�Ʋ��Լ�/�龯��/3.ts";
	string savePath= "H:/��Ƶ�泵�Ʋ��Լ�/�龯��/3/0V";

	CvCapture* pCap = cvCaptureFromFile(path.c_str());
	if (pCap == NULL)
	{
		cout << "���������Ƶ�ļ�·��������" << endl;
		return false;
	}
	IplImage* bgr = cvQueryFrame(pCap);
	int nFrame=0;
	while (1)
	{




		if (!(bgr = cvQueryFrame(pCap)))
		{
			break;
		}

		nFrame++;
		cout << "nFrame:" << nFrame  << endl;


		char str[25] = { 0 };
		//itoa(nFrame, str, 10);
		sprintf(str, "%d", nFrame);

		string iPath = savePath +"/"+ string(str)+ ".jpg";


		cvSaveImage(iPath.c_str(), bgr);

	}
	// frame



	cvReleaseCapture(&pCap);
	return 0;
}