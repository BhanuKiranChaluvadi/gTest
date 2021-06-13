#include <gtest/gtest.h>

#include <vector>
#include "MetaDataProcessor.hpp"
#include "MovieData.hpp"

using namespace std;


TEST(MovieDataProcessor, ProcessMovies_PassEmptyMovieList_ReturnEmptyResult){
	MetaDataProcessor processor;
	Movies result;

	processor.processMovies({}, result);
	ASSERT_EQ(0, result.size());
}

TEST(MovieDataProcessor, simple) {
	ASSERT_EQ(4, 2+2);
}