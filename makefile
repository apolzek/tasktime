# makefile

all: 
	cd src/ && gcc -o tasktime tasktime.c
	cd src/ && mv tasktime ../