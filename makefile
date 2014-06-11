all: eventStore

clean:
	-rm eventStore.o eventRepository.o binSer.o bon.o output/eventStoreApp output/serializeTest output/bonTest

eventStore: binSer.o bon.o eventStore.o
	g++ eventStoreApp.cc  eventStore.o eventRepository.o binSer.o bon.o  -o output/eventStoreApp -std=c++11 
	g++ serializeTest.cc  eventStore.o eventRepository.o binSer.o bon.o  -o output/serializeTest -std=c++11 
	g++ bonTest.cc  eventStore.o eventRepository.o binSer.o bon.o  -o output/bonTest -std=c++11
	g++ eventRepositoryTest.cc eventStore.o eventRepository.o binSer.o bon.o  -o output/eventRepositoryTest -std=c++11

binSer.o:
	g++ -v -c binSer.cc -std=c++11

bon.o:
	g++ -v -c bon.cc -std=c++11

eventStore.o:
	g++ -v -c eventStore.cc -std=c++11
	g++ -v -c eventRepository.cc -std=c++11
