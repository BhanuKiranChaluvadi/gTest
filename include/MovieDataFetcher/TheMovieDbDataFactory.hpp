#pragma once
#include "MovieDataFactory.hpp"

class TheMovieDbDataFactory : public MovieDataFactory
{
public:
	TheMovieDbDataFactory();
	~TheMovieDbDataFactory();

	std::shared_ptr<MovieData> CreateFromJson(const std::string& jsonString) const override;
};

