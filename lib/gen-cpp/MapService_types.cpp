/**
 * Autogenerated by Thrift Compiler (0.8.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "MapService_types.h"

namespace around7 { namespace mapservice {

const char* TCell::ascii_fingerprint = "7DEF99DDE8C8A4B4BB31D32877DC6434";
const uint8_t TCell::binary_fingerprint[16] = {0x7D,0xEF,0x99,0xDD,0xE8,0xC8,0xA4,0xB4,0xBB,0x31,0xD3,0x28,0x77,0xDC,0x64,0x34};

uint32_t TCell::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->lat1);
          this->__isset.lat1 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->lng1);
          this->__isset.lng1 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->lat2);
          this->__isset.lat2 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->lng2);
          this->__isset.lng2 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->height);
          this->__isset.height = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->width);
          this->__isset.width = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t TCell::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("TCell");
  xfer += oprot->writeFieldBegin("lat1", ::apache::thrift::protocol::T_DOUBLE, 1);
  xfer += oprot->writeDouble(this->lat1);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("lng1", ::apache::thrift::protocol::T_DOUBLE, 2);
  xfer += oprot->writeDouble(this->lng1);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("lat2", ::apache::thrift::protocol::T_DOUBLE, 3);
  xfer += oprot->writeDouble(this->lat2);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("lng2", ::apache::thrift::protocol::T_DOUBLE, 4);
  xfer += oprot->writeDouble(this->lng2);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("height", ::apache::thrift::protocol::T_DOUBLE, 5);
  xfer += oprot->writeDouble(this->height);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("width", ::apache::thrift::protocol::T_DOUBLE, 6);
  xfer += oprot->writeDouble(this->width);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

}} // namespace
