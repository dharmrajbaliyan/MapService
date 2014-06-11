/**
 * Autogenerated by Thrift Compiler (0.8.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef MapService_H
#define MapService_H

#include <TProcessor.h>
#include "MapService_types.h"

namespace around7 { namespace mapservice {

class MapServiceIf {
 public:
  virtual ~MapServiceIf() {}
  virtual int32_t findCell(const double lat, const double lng) = 0;
  virtual void findCells(std::vector<int32_t> & _return, const double lat, const double lng, const double radius) = 0;
};

class MapServiceIfFactory {
 public:
  typedef MapServiceIf Handler;

  virtual ~MapServiceIfFactory() {}

  virtual MapServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(MapServiceIf* /* handler */) = 0;
};

class MapServiceIfSingletonFactory : virtual public MapServiceIfFactory {
 public:
  MapServiceIfSingletonFactory(const boost::shared_ptr<MapServiceIf>& iface) : iface_(iface) {}
  virtual ~MapServiceIfSingletonFactory() {}

  virtual MapServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(MapServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<MapServiceIf> iface_;
};

class MapServiceNull : virtual public MapServiceIf {
 public:
  virtual ~MapServiceNull() {}
  int32_t findCell(const double /* lat */, const double /* lng */) {
    int32_t _return = 0;
    return _return;
  }
  void findCells(std::vector<int32_t> & /* _return */, const double /* lat */, const double /* lng */, const double /* radius */) {
    return;
  }
};

typedef struct _MapService_findCell_args__isset {
  _MapService_findCell_args__isset() : lat(false), lng(false) {}
  bool lat;
  bool lng;
} _MapService_findCell_args__isset;

class MapService_findCell_args {
 public:

  MapService_findCell_args() : lat(0), lng(0) {
  }

  virtual ~MapService_findCell_args() throw() {}

  double lat;
  double lng;

  _MapService_findCell_args__isset __isset;

  void __set_lat(const double val) {
    lat = val;
  }

  void __set_lng(const double val) {
    lng = val;
  }

  bool operator == (const MapService_findCell_args & rhs) const
  {
    if (!(lat == rhs.lat))
      return false;
    if (!(lng == rhs.lng))
      return false;
    return true;
  }
  bool operator != (const MapService_findCell_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MapService_findCell_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class MapService_findCell_pargs {
 public:


  virtual ~MapService_findCell_pargs() throw() {}

  const double* lat;
  const double* lng;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MapService_findCell_result__isset {
  _MapService_findCell_result__isset() : success(false) {}
  bool success;
} _MapService_findCell_result__isset;

class MapService_findCell_result {
 public:

  MapService_findCell_result() : success(0) {
  }

  virtual ~MapService_findCell_result() throw() {}

  int32_t success;

  _MapService_findCell_result__isset __isset;

  void __set_success(const int32_t val) {
    success = val;
  }

  bool operator == (const MapService_findCell_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const MapService_findCell_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MapService_findCell_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MapService_findCell_presult__isset {
  _MapService_findCell_presult__isset() : success(false) {}
  bool success;
} _MapService_findCell_presult__isset;

class MapService_findCell_presult {
 public:


  virtual ~MapService_findCell_presult() throw() {}

  int32_t* success;

  _MapService_findCell_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _MapService_findCells_args__isset {
  _MapService_findCells_args__isset() : lat(false), lng(false), radius(false) {}
  bool lat;
  bool lng;
  bool radius;
} _MapService_findCells_args__isset;

class MapService_findCells_args {
 public:

  MapService_findCells_args() : lat(0), lng(0), radius(0) {
  }

  virtual ~MapService_findCells_args() throw() {}

  double lat;
  double lng;
  double radius;

  _MapService_findCells_args__isset __isset;

  void __set_lat(const double val) {
    lat = val;
  }

  void __set_lng(const double val) {
    lng = val;
  }

  void __set_radius(const double val) {
    radius = val;
  }

  bool operator == (const MapService_findCells_args & rhs) const
  {
    if (!(lat == rhs.lat))
      return false;
    if (!(lng == rhs.lng))
      return false;
    if (!(radius == rhs.radius))
      return false;
    return true;
  }
  bool operator != (const MapService_findCells_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MapService_findCells_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class MapService_findCells_pargs {
 public:


  virtual ~MapService_findCells_pargs() throw() {}

  const double* lat;
  const double* lng;
  const double* radius;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MapService_findCells_result__isset {
  _MapService_findCells_result__isset() : success(false) {}
  bool success;
} _MapService_findCells_result__isset;

class MapService_findCells_result {
 public:

  MapService_findCells_result() {
  }

  virtual ~MapService_findCells_result() throw() {}

  std::vector<int32_t>  success;

  _MapService_findCells_result__isset __isset;

  void __set_success(const std::vector<int32_t> & val) {
    success = val;
  }

  bool operator == (const MapService_findCells_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const MapService_findCells_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MapService_findCells_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MapService_findCells_presult__isset {
  _MapService_findCells_presult__isset() : success(false) {}
  bool success;
} _MapService_findCells_presult__isset;

class MapService_findCells_presult {
 public:


  virtual ~MapService_findCells_presult() throw() {}

  std::vector<int32_t> * success;

  _MapService_findCells_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class MapServiceClient : virtual public MapServiceIf {
 public:
  MapServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  MapServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t findCell(const double lat, const double lng);
  void send_findCell(const double lat, const double lng);
  int32_t recv_findCell();
  void findCells(std::vector<int32_t> & _return, const double lat, const double lng, const double radius);
  void send_findCells(const double lat, const double lng, const double radius);
  void recv_findCells(std::vector<int32_t> & _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class MapServiceProcessor : public ::apache::thrift::TProcessor {
 protected:
  boost::shared_ptr<MapServiceIf> iface_;
  virtual bool process_fn(apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, std::string& fname, int32_t seqid, void* callContext);
 private:
  std::map<std::string, void (MapServiceProcessor::*)(int32_t, apache::thrift::protocol::TProtocol*, apache::thrift::protocol::TProtocol*, void*)> processMap_;
  void process_findCell(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_findCells(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  MapServiceProcessor(boost::shared_ptr<MapServiceIf> iface) :
    iface_(iface) {
    processMap_["findCell"] = &MapServiceProcessor::process_findCell;
    processMap_["findCells"] = &MapServiceProcessor::process_findCells;
  }

  virtual bool process(boost::shared_ptr<apache::thrift::protocol::TProtocol> piprot, boost::shared_ptr<apache::thrift::protocol::TProtocol> poprot, void* callContext);
  virtual ~MapServiceProcessor() {}
};

class MapServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  MapServiceProcessorFactory(const ::boost::shared_ptr< MapServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< MapServiceIfFactory > handlerFactory_;
};

class MapServiceMultiface : virtual public MapServiceIf {
 public:
  MapServiceMultiface(std::vector<boost::shared_ptr<MapServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~MapServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<MapServiceIf> > ifaces_;
  MapServiceMultiface() {}
  void add(boost::shared_ptr<MapServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  int32_t findCell(const double lat, const double lng) {
    size_t sz = ifaces_.size();
    for (size_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        return ifaces_[i]->findCell(lat, lng);
      } else {
        ifaces_[i]->findCell(lat, lng);
      }
    }
  }

  void findCells(std::vector<int32_t> & _return, const double lat, const double lng, const double radius) {
    size_t sz = ifaces_.size();
    for (size_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        ifaces_[i]->findCells(_return, lat, lng, radius);
        return;
      } else {
        ifaces_[i]->findCells(_return, lat, lng, radius);
      }
    }
  }

};

}} // namespace

#endif