draw.exe : draw.o pacman.o mapc.o hantei.o	cookie.o
				cc -o draw.exe draw.o pacman.c mapc.o hantei.o	cookie.o -lncursesw
draw.o: draw.c
		cc -c draw.c
pacman.o: pacman.c
		cc -c pacman.c
mapc.o: mapc.c
		cc -c mapc.c
hantei.o: hantei.c mapc.h
		cc -c hantei.c
cookie.o: cookie.c mapc.h
		cc -c cookie.c 
