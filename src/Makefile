CC=g++
CXXFLAGS=-g -fpermissive -Wmultichar -std=gnu++11 -lncurses

OBJS = Main.o coche.o Mapa.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o practica.out ${OBJS}

clean:
	rm -rf *.o practica.out
