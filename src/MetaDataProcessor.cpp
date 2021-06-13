#include "MetaDataProcessor.hpp"

using namespace std;

MetaDataProcessor::MetaDataProcessor()
{
}

MetaDataProcessor::~MetaDataProcessor() {}
void MetaDataProcessor::processMovies(const vector<string> &fileNames, Movies &reesult)
{
	if (fileNames.size() == 0)
	{
		return;
	}
}