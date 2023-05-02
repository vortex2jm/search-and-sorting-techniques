COMPILE=gcc -c
LINK=gcc -o prog *.o
MOVE=mv *.o obj/

all:
	@echo Choose a sort method to compile!

merge-sort: general
	@ $(COMPILE) merge-sort.c
	@ $(LINK)
	@ $(MOVE)

quick-sort: general
	@ $(COMPILE) quick-sort.c
	@ $(LINK)
	@ $(MOVE)

general: clean
	@ gcc -c client.c && mkdir obj

clean:
	@ rm -rf obj/ prog *.o
	@ clear
