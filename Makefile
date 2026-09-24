all: task1.out task2.out

task1.out: task1.c
	gcc task1.c -o task1.out

task2.out: task2.c
	gcc task2.c -o task2.out

clean:
	rm -f task1.out task2.out
