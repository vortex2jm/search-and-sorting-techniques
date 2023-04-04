COMPILE=gcc -c
LINK=gcc -o prog *.o
MOVE=mv *.o obj/

all:
	@echo Choose a sort method to compile!

selection-sort: general 
	@ $(COMPILE) selection-sort.c
	@ $(LINK)
	@ $(MOVE)

insertion-sort: general
	@ $(COMPILE) insertion-sort.c
	@ $(LINK)
	@ $(MOVE)

bubble-sort: general
	@ $(COMPILE) bubble-sort.c
	@ $(LINK)
	@ $(MOVE)

recursive-bubble-sort: general
	@ $(COMPILE) recursive-bubble-sort.c
	@ $(LINK)
	@ $(MOVE)

shaker-sort: general
	@ $(COMPILE) shaker-sort.c
	@ $(LINK)
	@ $(MOVE)

general: clean
	@ gcc -c client.c && mkdir obj

clean:
	@ rm -rf obj/ prog *.o
	@ clear
