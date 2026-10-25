main: main.o player.o enemy.o
	$(CXX) -o $@ $^

main.o: main.cpp player.h enemy.h

player.o: player.cpp player.h enemy.h

enemy.o: enemy.cpp enemy.h player.h

clean:
	rm -f *.o main

.PHONY: clean