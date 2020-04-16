all:
	gcc main.c actions.c axes.o init.c lumiere.o switch_blend.o switch_light.o VM_init.o -lm -lGL -no-pie -lGLU -lglut -o test