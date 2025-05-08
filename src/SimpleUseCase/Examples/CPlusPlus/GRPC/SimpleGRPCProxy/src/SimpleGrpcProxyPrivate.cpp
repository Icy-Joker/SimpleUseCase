//#include "stdafx.h"

#include "SimpleGrpcProxyPrivate.h"

SimpleGRPCProxyPrivate::SimpleGRPCProxyPrivate(std::shared_ptr<grpc::ChannelInterface> channel):
  stub(SimpleGRPC::SimpleService::NewStub(channel))
{
}

SimpleGRPCProxyPrivate::~SimpleGRPCProxyPrivate()
{
}

std::string SimpleGRPCProxyPrivate::doSayHello(const std::string& name)
{
  std::string result;

  {
    SimpleGRPC::SimpleRequest request;
    request.set_name(name);

    SimpleGRPC::SimpleResponse response;
    grpc::ClientContext context;

    grpc::Status status = this->stub->doSayHello(&context,request,&response);
    if(status.ok())
    {
      result = response.message();
    }
    else
    {
      std::cerr << "RPC failed: " << status.error_message() << std::endl;
      result = "RPC Error";
    }
  }

  return result;
};
