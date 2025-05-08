#pragma once

#ifndef __SIMPLEGRPCPROXY_H__
# define __SIMPLEGRPCPROXY_H__

#include <SimpleGRPC.grpc.pb.h>

class SimpleGRPCProxyPrivate;

class SimpleGRPCProxy
{
public:
  explicit SimpleGRPCProxy(std::shared_ptr<grpc::ChannelInterface> channel);
  ~SimpleGRPCProxy();
public:
  std::string doSayHello(const std::string& name);
private:
  SimpleGRPCProxyPrivate* private_ptr;;
};

#endif // !__SIMPLEGRPCPROXY_H__
