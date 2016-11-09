#include <stdio.h>
#include <cstdlib>
#include "MyScoreboard.h"

int main()
{
	MyScoreboard scoreboard(12, 3);
	scoreboard.setScore(5, 0, 3);
	printf("%d\n", scoreboard.getScore(5, 0));
	scoreboard.setScore(5, 1, 12);
	printf("%d\n", scoreboard.getTotalScore(5));
	scoreboard.clearScoreboard();
	printf("%d\n", scoreboard.getTotalScore(5));
	printf("%d\n", scoreboard.getScore(1000, 2000));
	return 0;
}

MyScoreboard::MyScoreboard(int numCompetitors, int numPeriods)
{
	m_maxCompetitors = numCompetitors;
	m_maxPeriods = numPeriods;
	for (int i = 0; i < numCompetitors; i++)
	{
		std::vector<int> temp(numPeriods, 0);
		m_scoreboard.push_back(temp);
 	}
}

void MyScoreboard::setScore(int competitor, int period, int score)
{
	checkBounds(competitor, period);
	m_scoreboard[competitor][period] = score;
}

int MyScoreboard::getScore(int competitor, int period)
{
	checkBounds(competitor, period);
	return m_scoreboard[competitor][period];
}

int MyScoreboard::getTotalScore(int competitor)
{
	checkBounds(competitor, 0);
	int total = 0;
	for (auto periods : m_scoreboard[competitor])
	{
		total += periods;
	}
	return total;
}

void MyScoreboard::clearScoreboard()
{
	for (int i = 0; i < m_maxCompetitors; i++)
		for(int j = 0; j < m_maxPeriods; j++)
			m_scoreboard[i][j] = 0;

}

void MyScoreboard::checkBounds(int competitor, int period)
{
	if (competitor >= m_maxCompetitors || competitor < 0 || period >= m_maxPeriods || period < 0)
	{
		printf("Error: out of bounds.\n");
		exit(1);
	}
}

MyScoreboard::~MyScoreboard()
{}