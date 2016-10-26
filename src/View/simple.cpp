#include "../Data/LogReader.h"
#include "Options.h"

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <signal.h>

LogReader * lr; 

void ctrlc_handler(int sig)
{
	delete lr;

	cv::destroyAllWindows();
	std::exit(EXIT_SUCCESS);
}

int main(int argc, char ** argv)
{
	signal(SIGINT, ctrlc_handler);

	Options::get(argc, argv);

	lr = new LogReader();

	cv::namedWindow("Image", CV_WINDOW_AUTOSIZE);
	cv::namedWindow("Depth", CV_WINDOW_AUTOSIZE);

	unsigned char * image;
	unsigned short * depth;

	while(lr->getNext())
	{	
		image = new unsigned char[Options::get().height * Options::get().width * 3];
		depth = new unsigned short[Options::get().height * Options::get().width];

		memcpy(image, lr->image, Options::get().height * Options::get().width * 3);
		memcpy(depth, lr->depth, Options::get().height * Options::get().width * 2);

		cv::Mat im(Options::get().height, Options::get().width, CV_8UC3, image);
		cv::Mat dp(Options::get().height, Options::get().width, CV_16U, depth);

		cv::cvtColor(dp, dp, CV_GRAY2RGB);

		cv::imshow("Image", im);
		cv::imshow("Depth", dp);
		cv::moveWindow("Depth", Options::get().width + 60, 0);
		cv::waitKey(33);

		delete image;
		delete depth;
	}

	delete lr;

	cv::destroyAllWindows();	
}