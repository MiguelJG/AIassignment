CC=g++
CXXFLAGS=-g -fpermissive -Wmultichar -std=gnu++11

OBJS = Main.o coche.o Mapa.o -lncurses

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o practica.out ${OBJS}

clean:
	rm -rf *.o practica.out
