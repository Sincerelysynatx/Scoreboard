#include <stdio.h>
#include <cstdlib>
#include <limits.h>
#include "Scoreboard.h"

Scoreboard::Scoreboard(int numCompetitors, int numPeriods)
{
	m_maxCompetitors = numCompetitors;
	m_maxPeriods = numPeriods;
	for (int i = 0; i < numCompetitors; i++)
	{
		std::vector<int> temp(numPeriods, 0);
		m_scoreboard.push_back(temp);
 	}
}

void Scoreboard::setScore(int competitor, int period, int score)
{
	if (!checkBounds(--competitor, --period))
	{
		return;
	}
	m_scoreboard[competitor][period] = score;
	notifyObservers();
}

int Scoreboard::getScore(int competitor, int period)
{
	if (!checkBounds(--competitor, --period))
	{
		return INT_MIN;
	}
	return m_scoreboard[competitor][period];
}

int Scoreboard::getTotalScore(int competitor)
{
	if (!checkBounds(--competitor, 0))
	{
		return -1;
	}
	int total = 0;
	for (auto periods : m_scoreboard[competitor])
	{
		total += periods;
	}
	return total;
}

void Scoreboard::clearScoreboard()
{
	for (int i = 0; i < m_maxCompetitors; i++)
		for(int j = 0; j < m_maxPeriods; j++)
		{
			m_scoreboard[i][j] = 0;
			notifyObservers();
		}

}

bool Scoreboard::checkBounds(int competitor, int period)
{
	if (competitor >= m_maxCompetitors || competitor < 0 || period >= m_maxPeriods || period < 0)
	{
		return 0;
	}
	return 1;
}

Scoreboard::~Scoreboard()
{}