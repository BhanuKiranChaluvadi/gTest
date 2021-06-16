#include "MovieData.hpp"

using namespace std;

MovieData::MovieData() : m_length(0) {}

MovieData::~MovieData() {}

void MovieData::SetImdbId(std::string id) { m_id = id; }

void MovieData::SetTitle(std::string title) { m_title = title; }

void MovieData::SetLengthMin(unsigned length) { m_length = length; }

void MovieData::SetActors(std::vector<std::string> actors) { m_actors = actors; }

void MovieData::SetPlot(std::string plot) { m_plot = plot; }

std::string MovieData::GetImdbId() const { return m_id; }

std::string MovieData::GetTitle() const { return m_title; }

unsigned MovieData::GetLengthMin() const { return m_length; }

std::vector<std::string> MovieData::GetActors() const { return m_actors; }

std::string MovieData::GetPlot() const { return m_plot; }