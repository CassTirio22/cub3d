#!/bin/sh
make
gcc -lmlx -framework OpenGL -framework AppKit cub3d.a cub3d.c
./a.out map.cub