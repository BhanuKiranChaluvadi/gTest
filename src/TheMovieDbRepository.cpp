#include "TheMovieDbRepository.hpp"
#include "JsonHelper.hpp"
#include "MovieNotFoundException.hpp"
#include "StringHtmlEncoder.hpp"
#include "MovieDataFactory.hpp"

using namespace std;

TheMovieDbRepository::TheMovieDbRepository(const string& apiKey, const MovieDataFactory& movieDataFactory): 
m_apiKey(apiKey), m_movieDataFactory(movieDataFactory)
{
}


TheMovieDbRepository::~TheMovieDbRepository()
{
}

std::shared_ptr<MovieData> TheMovieDbRepository::FindMovieData(const std::string& movieName)
{
	auto encodedMovieName = StringHtmlEncoder::Encode(movieName);

	string getMovieListUrl = "http://api.themoviedb.org/3/search/movie?api_key=" + m_apiKey + "&page=1&query=" + encodedMovieName;
	string movieList = m_client.HttpGet(getMovieListUrl);
	if(movieList.length() == 0)
	{
		throw MovieNotFoundException(movieName);
	}

	auto movieId = JsonHelper::GetMatchingTitleIdFromMovieList(movieName, movieList);

	if(movieId.length() == 0)
	{
		throw MovieNotFoundException(movieName);
	}

	string getMovieDetailsUrl = "http://api.themoviedb.org/3/movie/" + movieId + "?api_key=" + m_apiKey;
	auto movieDataJson = m_client.HttpGet(getMovieDetailsUrl);

	return m_movieDataFactory.CreateFromJson(movieDataJson);
}
