
#include "VideoSource.h"
#include "../Options.h"

#include <iostream>

#include <boost/filesystem.hpp>

#ifndef LOGREADER_H_
#define LOGREADER_H_

class LogReader : public VideoSource
{
	public:
		LogReader();
		virtual ~LogReader();
		virtual bool getNext();

	private: 
		bool hasNext();

		FILE * f;
		int64_t timestamp;
		int32_t depthSize;
		int32_t imageSize;
		int32_t numFrames;
		int32_t currentFrame;
};

#endif // LOGREADER_H_