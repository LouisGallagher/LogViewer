#include "LogReader.h"

LogReader::LogReader():
VideoSource()
{
	assert(boost::filesystem::exists(Options::get().logfile));

	f = fopen(Options::get().logfile.c_str(), "r");

	assert(fread(&numFrames, sizeof(int32_t), 1, f));
}

LogReader::~LogReader()
{
	delete depth;
	delete image;
	
	fclose(f);
}

bool LogReader::getNext()
{
	if(!hasNext())return false;

	assert(fread(&timestamp, sizeof(int64_t), 1, f));
	assert(fread(&depthSize, sizeof(int32_t), 1, f));
	assert(fread(&imageSize, sizeof(int32_t), 1, f));

	assert(fread(depth, sizeof(char), depthSize, f));
	assert(fread(image, sizeof(char), imageSize, f));

	currentFrame++;

	return true;
}

bool LogReader::hasNext()
{
	return currentFrame < numFrames - 1;
}