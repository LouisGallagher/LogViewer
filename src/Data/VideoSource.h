#include "../Options.h"

#include <cstdint>

#ifndef VIDEOSOURCE_H_ 
#define VIDEOSOURCE_H_

class VideoSource
{
	public:
		VideoSource()
		{
			depth = new unsigned short[Options::get().height * Options::get().width];
			image = new unsigned char[Options::get().height * Options::get().width * 3];
		}

		virtual ~VideoSource(){}

		virtual bool getNext() = 0;

		unsigned short * depth;
		unsigned char * image; 

		int frameNumber;

		int64_t timestamp;
};
#endif // VIDEOSOURCE_H_