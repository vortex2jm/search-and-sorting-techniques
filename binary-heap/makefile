COMPILE=gcc -c
LINK=gcc -o prog *.o
MOVE=mv *.o obj/

all:
	@echo Choose a sort method to compile!

heap: general 
	@ $(COMPILE) heap.c
	@ $(LINK)
	@ $(MOVE)

general: clean
	@ gcc -c client.c && mkdir obj

clean:
	@ rm -rf obj/ prog *.o
	@ clear
