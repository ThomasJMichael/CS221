#
# In order to execute this "Makefile" just type "make"
#	A. Delis (ad@di.uoa.gr)
#

OBJS	= main.o invent.o order.o product.o
SOURCE	= main.cpp invent.cpp order.cpp product.cpp
HEADER	= invent.h order.h product.h
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 
# -g option enables debugging mode 
# -c flag generates object code for separate files


all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)


# create/compile the individual files >>separately<<
CheckoutSystem.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

invent.o: invent.cpp
	$(CC) $(FLAGS) invent.cpp 

order.o: order.cpp
	$(CC) $(FLAGS) order.cpp 

product.o: product.cpp
	$(CC) $(FLAGS) product.cpp 


# clean house
clean:
	rm -f $(OBJS) $(OUT)