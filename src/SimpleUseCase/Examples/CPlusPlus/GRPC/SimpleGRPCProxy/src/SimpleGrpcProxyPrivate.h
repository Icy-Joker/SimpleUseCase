#pragma once

#ifndef __SIMPLEGRPCPROXYPRIVATE_H__
# define __SIMPLEGRPCPROXYPRIVATE_H__

#include <SimpleGRPC.grpc.pb.h>

class SimpleGRPCProxyPrivate
{
private:
  explicit SimpleGRPCProxyPrivate(std::shared_ptr<grpc::ChannelInterface> channel);
  ~SimpleGRPCProxyPrivate();
private:
  std::string doSayHello(const std::string& name);
private:
  std::unique_ptr<SimpleGRPC::SimpleService::Stub> stub;

  friend class SimpleGRPCProxy;
};

#endif // !__SIMPLEGRPCPROXYPRIVATE_H__
