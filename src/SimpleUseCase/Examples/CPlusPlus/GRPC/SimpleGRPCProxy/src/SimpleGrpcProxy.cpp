#include "SimpleGrpcProxy.h"
#include "SimpleGrpcProxyPrivate.h"

SimpleGRPCProxy::SimpleGRPCProxy(std::shared_ptr<grpc::ChannelInterface> channel):
  private_ptr(new SimpleGRPCProxyPrivate(channel))
{
}

SimpleGRPCProxy::~SimpleGRPCProxy()
{
  if(private_ptr)
  {
    delete private_ptr;
    private_ptr = nullptr;
  }
}

std::string SimpleGRPCProxy::doSayHello(const std::string& name)
{
  std::string result;

  {
    result = private_ptr->doSayHello(name);
  }

  return result;
}
