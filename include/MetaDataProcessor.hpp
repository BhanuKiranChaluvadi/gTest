#pragma once
#include <string>
#include <vector>

using namespace std;

class MovieData;

typedef vector<MovieData> Movies;

class MetaDataProcessor
{
public:
	MetaDataProcessor();
	~MetaDataProcessor();
	void processMovies(const vector<string> &fileNames, Movies &reesult);
};