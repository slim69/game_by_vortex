prog:player.o main.o backg.o sous_menu.o collision.o jouer.o menu.o sauvgarde.o
	gcc player.o main.o backg.o sous_menu.o jouer.o menu.c collision.o sauvgarde.o -o prog  -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
player.o:player.c
	gcc -c player.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
backg.o:backg.c
	gcc -c backg.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
sous_menu.o:sous_menu.c
	gcc -c sous_menu.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
collision.o:collision.c
	gcc -c collision.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
jouer.o:jouer.c
	gcc -c jouer.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
menu.o:menu.c
	gcc -c menu.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
sauvgarde.o:sauvgarde.c
	gcc -c sauvgarde.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
