// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "MapService.h"
#include "MapSearch.h"
#include <protocol/TBinaryProtocol.h>
#include <server/TSimpleServer.h>
#include <transport/TServerSocket.h>
#include <transport/TBufferTransports.h>

#include <string>
#include <ctime>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;
using namespace std;

using namespace ::around7::mapservice;
//perf helper
void computeTimeTaken(clock_t t1, clock_t t2) {
	printf("Time taken(in ms) by %s : %lf\n", __FUNCTION__, (double)((t2-t1)*1000)/CLOCKS_PER_SEC);
}

class MapServiceHandler : virtual public MapServiceIf {
 private:
 	string dataFile; 		 
	MapSearch* mapSearch;
 public:
  MapServiceHandler(string fileName):dataFile(fileName) {
		mapSearch = new MapSearch(dataFile);	  
		printf("Initialization done.\n");
  }

  int32_t findCell(const double lat, const double lng) {
	clock_t t1 = clock();
	int cell = mapSearch->findCellIndex(lat, lng);
	clock_t t2 = clock();
	computeTimeTaken(t1, t2);
    printf("findCell completed %d\n", cell);
	return cell;
  }

  void findCells(std::vector<int32_t> & _return, const double lat, const double lng, const double radius) {
    printf("findCells called\n");
	clock_t t1 = clock();
	vector<int> cells = mapSearch->findCellsIndex(lat, lng, radius);
	clock_t t2 = clock();
	computeTimeTaken(t1, t2);
	printf("Total cells with radius %lf of %lf %lf is %d\n", radius, lat, lng, cells.size());
	//print first 10 results incase results are more than 10
	for(size_t i=0; i<cells.size() && i<10; ++i) {
		printf("%d ", cells[i]);
	}
	printf("\n");
	_return = cells;
  }

};

int main(int argc, char **argv) {
  if(argc < 2) {
  		printf("<data file>\n");
		return 1;
  }			
  string dataFile(argv[1]);
  int port = 11111;
  shared_ptr<MapServiceHandler> handler(new MapServiceHandler(dataFile));
  shared_ptr<TProcessor> processor(new MapServiceProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
  printf("Starting server on port : %d\n", port);

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}
