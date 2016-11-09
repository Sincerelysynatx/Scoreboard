main: MyScoreboard.o
	g++ MyScoreboard.o -o app

MyScoreboard.o: MyScoreboard.cpp MyScoreboard.h IScoreboard.h
	g++ -c --std=c++14 MyScoreboard.cpp

clean:
	rm *.o app