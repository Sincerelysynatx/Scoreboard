#include "IScoreboard.h"
#include "ObserverPattern.hpp"
#include <vector>

class Scoreboard : public IScoreboard, public Observable
{
public:
	Scoreboard(int, int);
	~Scoreboard();
	virtual void setScore(int competitor, int period, int score);
	virtual int getScore(int competitor, int period);
	virtual int getTotalScore(int competitor);
	virtual void clearScoreboard();
	bool checkBounds(int, int);
private:
	std::vector<std::vector<int> > m_scoreboard;
	int m_maxCompetitors;
	int m_maxPeriods;
};