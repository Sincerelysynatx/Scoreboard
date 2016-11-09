#include "IScoreboard.h"
#include <vector>



class MyScoreboard : public IScoreboard
{
public:
	MyScoreboard(int, int);
	~MyScoreboard();
	virtual void setScore(int competitor, int period, int score);
	virtual int getScore(int competitor, int period);
	virtual int getTotalScore(int competitor);
	virtual void clearScoreboard();
	void checkBounds(int, int);
private:
	std::vector<std::vector<int> > m_scoreboard;
	int m_maxCompetitors;
	int m_maxPeriods;
};