#pragma once

#ifndef __SIMPLEGRPCSERVER_H__
# define __SIMPLEGRPCSERVER_H__

#include <SimpleGRPC.grpc.pb.h>

class SimpleGRPCService : public SimpleGRPC::SimpleService::Service
{
public:
  grpc::Status doSayHello(grpc::ServerContext* context, const SimpleGRPC::SimpleRequest* request,SimpleGRPC::SimpleResponse* response) override;
public:
  void run();
};

#endif // !__SIMPLEGRPCSERVER_H__
