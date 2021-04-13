CC=gcc
LD=gcc
CFLAGS=
LDFLAGS=
GTKFLAGS=`pkg-config --cflags --libs gtk+-2.0`
DOXYGEN=doxygen

all: oxo

oxo: main.o controller.o view.o model.o
	$(LD) -o oxo main.o view.o controller.o model.o $(LDFLAGS) $(GTKFLAGS)

main.o: main.c view.h controller.h model.h
	$(CC) -c main.c -o main.o $(CFLAGS) $(GTKFLAGS)

controller.o: controller.h controller.c view.h model.h
	$(CC) -c controller.c -o controller.o $(CFLAGS) $(GTKFLAGS)	

view.o: view.h view.c controller.h model.h
	$(CC) -c view.c -o view.o $(CFLAGS) $(GTKFLAGS)

model.o: model.h model.c
	$(CC) -c model.c -o model.o $(CFLAGS) $(GTKFLAGS)

doc: 
	$(DOXYGEN) doc_conf

clean:
	rm -f *.o
	rm -f oxo
	clear
