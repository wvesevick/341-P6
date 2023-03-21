blah: main.cpp hashtable.o hashTableLinearProbing.o hashTableChaining.o hashTableCuckoo.o
	g++ main.cpp  hashtable.o hashTableLinearProbing.o hashTableChaining.o hashTableCuckoo.o -o blah

hashtable.o: hashtable.cpp hashtable.h
	g++ -c hashtable.cpp

hashTableLinearProbing.o: hashTableLinearProbing.cpp hashTableLinearProbing.h hashtable.o
	g++ -c hashTableLinearProbing.cpp hashtable.o

hashTableChaining.o: hashTableChaining.cpp hashTableChaining.h hashtable.o
	g++ -c hashTableChaining.cpp hashtable.o

hashTableCuckoo.o: hashTableCuckoo.h hashTableCuckoo.cpp hashtable.o hashTableLinearProbing.o
	g++ -c hashTableCuckoo.cpp hashtable.o hashTableLinearProbing.o

clean:
	rm -f *.o blah
