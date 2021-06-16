#pragma once

#include <string>
#include <vector>

class MovieData
{
	std::string m_id;
	std::string m_title;
	std::string m_posterUrl;
	unsigned m_length;
	std::vector<std::string> m_actors;
	std::string m_plot;

protected:
	// Setters
	virtual void SetImdbId(std::string id);
	virtual void SetTitle(std::string title);
	virtual void SetLengthMin(unsigned length);
	virtual void SetActors(std::vector<std::string> actors);
	virtual void SetPlot(std::string plot);

	MovieData();

public:
	~MovieData();

	// Getters
	std::string GetImdbId() const;
	std::string GetTitle() const;
	unsigned GetLengthMin() const;
	std::vector<std::string> GetActors() const;
	std::string GetPlot() const;
};