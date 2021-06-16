#pragma once
#include <string>
#include <vector>
#include "MovieMetaDataRepository.hpp"
#include <memory>

class MovieData;

typedef std::vector<std::shared_ptr<MovieData>> Movies;

class MetaDataProcessor
{
	MovieMetaDataRepository &m_repository;

public:
	MetaDataProcessor(MovieMetaDataRepository &respository);
	~MetaDataProcessor();

	void processMovies(const std::vector<std::string> &movieNames, Movies &result);
};