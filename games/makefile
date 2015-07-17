draw.exe : draw.o pacman.o mapc.o hantei.o
				cc -o draw.exe draw.c pacman.c mapc.c hantei.c -lncursesw
draw.o: draw.c
		cc -c draw.c
pacman.o: pacman.c
		cc -c pacman.c
mapc.o: map.c
		cc -c map.c
hantei.o: hantei.c mapc.h
		cc -c hantei.c 
