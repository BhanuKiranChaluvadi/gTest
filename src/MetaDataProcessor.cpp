#include "MetaDataProcessor.hpp"
#include "MovieData.hpp"

using namespace std;

MetaDataProcessor::MetaDataProcessor(MovieMetaDataRepository &jsonClient) : m_repository(jsonClient) {}

MetaDataProcessor::~MetaDataProcessor() {}

void MetaDataProcessor::processMovies(const vector<string> &movieNames, Movies &result)
{
	if (movieNames.size() == 0)
	{
		return;
	}

	for (auto movieName : movieNames)
	{
		try
		{
			std::shared_ptr<MovieData> movieData = m_repository.FindMovieData(movieName);
			result.push_back(movieData);
		}
		catch (...)
		{
			// TODO: error handling
		}
	}
}