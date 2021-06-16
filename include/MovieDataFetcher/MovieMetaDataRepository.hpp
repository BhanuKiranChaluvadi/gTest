#pragma once

#include "MovieData.hpp"
#include <memory>

class MovieMetaDataRepository
{
public:
	virtual ~MovieMetaDataRepository() = default;

	virtual std::shared_ptr<MovieData> FindMovieData(const std::string &movieName) = 0;
};