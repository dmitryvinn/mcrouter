/*
 *  Copyright (c) 2017-present, Facebook, Inc.
 *
 *  This source code is licensed under the MIT license found in the LICENSE
 *  file in the root directory of this source tree.
 *
 */

/*
 *  THIS FILE IS AUTOGENERATED. DO NOT MODIFY IT; ALL CHANGES WILL BE LOST IN
 *  VAIN.
 *
 *  @generated
 */
#pragma once

#include <exception>
#include <memory>

#include <mcrouter/lib/network/RpcStatsContext.h>
#include <mcrouter/lib/network/ThriftTransport.h>
#include <mcrouter/McrouterFiberContext.h>
#include <thrift/lib/cpp/TApplicationException.h>
#include <thrift/lib/cpp/transport/TTransportException.h>
#include <thrift/lib/cpp2/async/RequestChannel.h>

#include "mcrouter/lib/carbon/test/gen/gen-cpp2/CarbonThriftTestAsyncClient.h"

namespace facebook {
namespace memcache {

template <>
class ThriftTransportMethods<carbon::test::CarbonThriftTestRouterInfo> : public ThriftTransportUtil {
 public:
  ThriftTransportMethods() = default;
  virtual ~ThriftTransportMethods() override = default;

void sendSyncHelper(
    typename carbon::test::CarbonThriftTestRouterInfo::RouteHandleAsyncClient* thriftClient,
    const carbon::test::DummyThriftRequest& request,
    apache::thrift::RpcOptions& rpcOptions,
    folly::Try<apache::thrift::RpcResponseComplete<carbon::test::DummyThriftReply>>& reply,
    RpcStatsContext* rpcStatsContext = nullptr) {
  bool needServerLoad = mcrouter::fiber_local<carbon::test::CarbonThriftTestRouterInfo>::getThriftServerLoadEnabled();
  if (needServerLoad) {
    rpcOptions.setWriteHeader(kLoadHeader, kDefaultLoadCounter);
  }

#ifndef LIBMC_FBTRACE_DISABLE
  traceRequest(request, rpcOptions);
#endif
  reply = thriftClient->sync_complete_thrift_test(
      rpcOptions, request);
  if (rpcStatsContext && reply.hasValue()) {
      auto& stats = reply->responseContext.rpcSizeStats;
      rpcStatsContext->requestBodySize = stats.requestSerializedSizeBytes;
      rpcStatsContext->replySizeBeforeCompression = stats.responseSerializedSizeBytes;
      rpcStatsContext->replySizeAfterCompression = stats.responseWireSizeBytes;
      if (needServerLoad && reply->responseContext.serverLoad) {
        rpcStatsContext->serverLoad = ServerLoad(
            static_cast<int32_t>(*reply->responseContext.serverLoad));
      }
  }
#ifndef LIBMC_FBTRACE_DISABLE
  traceResponse(request, reply);
#endif
}

void sendSyncHelper(
    typename carbon::test::CarbonThriftTestRouterInfo::RouteHandleAsyncClient* thriftClient,
    const carbon::test::ThriftTestRequest& request,
    apache::thrift::RpcOptions& rpcOptions,
    folly::Try<apache::thrift::RpcResponseComplete<carbon::test::ThriftTestReply>>& reply,
    RpcStatsContext* rpcStatsContext = nullptr) {
  bool needServerLoad = mcrouter::fiber_local<carbon::test::CarbonThriftTestRouterInfo>::getThriftServerLoadEnabled();
  if (needServerLoad) {
    rpcOptions.setWriteHeader(kLoadHeader, kDefaultLoadCounter);
  }

#ifndef LIBMC_FBTRACE_DISABLE
  traceRequest(request, rpcOptions);
#endif
  reply = thriftClient->sync_complete_test(
      rpcOptions, request);
  if (rpcStatsContext && reply.hasValue()) {
      auto& stats = reply->responseContext.rpcSizeStats;
      rpcStatsContext->requestBodySize = stats.requestSerializedSizeBytes;
      rpcStatsContext->replySizeBeforeCompression = stats.responseSerializedSizeBytes;
      rpcStatsContext->replySizeAfterCompression = stats.responseWireSizeBytes;
      if (needServerLoad && reply->responseContext.serverLoad) {
        rpcStatsContext->serverLoad = ServerLoad(
            static_cast<int32_t>(*reply->responseContext.serverLoad));
      }
  }
#ifndef LIBMC_FBTRACE_DISABLE
  traceResponse(request, reply);
#endif
}

void sendSyncHelper(
    typename carbon::test::CarbonThriftTestRouterInfo::RouteHandleAsyncClient* thriftClient,
    const McVersionRequest& request,
    apache::thrift::RpcOptions& rpcOptions,
    folly::Try<apache::thrift::RpcResponseComplete<McVersionReply>>& reply,
    RpcStatsContext* rpcStatsContext = nullptr) {
  bool needServerLoad = mcrouter::fiber_local<carbon::test::CarbonThriftTestRouterInfo>::getThriftServerLoadEnabled();
  if (needServerLoad) {
    rpcOptions.setWriteHeader(kLoadHeader, kDefaultLoadCounter);
  }

#ifndef LIBMC_FBTRACE_DISABLE
  traceRequest(request, rpcOptions);
#endif
  reply = thriftClient->sync_complete_mcVersion(
      rpcOptions, request);
  if (rpcStatsContext && reply.hasValue()) {
      auto& stats = reply->responseContext.rpcSizeStats;
      rpcStatsContext->requestBodySize = stats.requestSerializedSizeBytes;
      rpcStatsContext->replySizeBeforeCompression = stats.responseSerializedSizeBytes;
      rpcStatsContext->replySizeAfterCompression = stats.responseWireSizeBytes;
      if (needServerLoad && reply->responseContext.serverLoad) {
        rpcStatsContext->serverLoad = ServerLoad(
            static_cast<int32_t>(*reply->responseContext.serverLoad));
      }
  }
#ifndef LIBMC_FBTRACE_DISABLE
  traceResponse(request, reply);
#endif
}

};

template <>
class ThriftTransport<carbon::test::CarbonThriftTestRouterInfo> : public ThriftTransportMethods<carbon::test::CarbonThriftTestRouterInfo>,
                                       public ThriftTransportBase {
 public:
  ThriftTransport(folly::EventBase& eventBase, ConnectionOptions options)
      : ThriftTransportBase(eventBase, std::move(options)) {}
  ThriftTransport(folly::VirtualEventBase& eventBase, ConnectionOptions options)
      : ThriftTransportBase(eventBase.getEventBase(), std::move(options)) {}
  ~ThriftTransport() override {
    resetClient();
  }

  void setFlushList(FlushList* flushList) override final {
    flushList_ = flushList;
    if (thriftClient_) {
      auto* channel = static_cast<apache::thrift::RocketClientChannel*>(
          thriftClient_->getChannel());
      channel->setFlushList(flushList_);
    }
  }

  carbon::test::DummyThriftReply sendSync(
      const carbon::test::DummyThriftRequest& request,
      std::chrono::milliseconds timeout,
      RpcStatsContext* rpcStatsContext = nullptr) {
    return sendSyncImpl([this, &request, timeout, rpcStatsContext] {
      folly::Try<apache::thrift::RpcResponseComplete<carbon::test::DummyThriftReply>> reply;
      if (auto* thriftClient = getThriftClient()) {
        auto rpcOptions = getRpcOptions(timeout);
        sendSyncHelper(thriftClient, request, rpcOptions, reply, rpcStatsContext);
      } else {
        reply.emplaceException(
            folly::make_exception_wrapper<apache::thrift::transport::TTransportException>(
              apache::thrift::transport::TTransportException::NOT_OPEN,
              "Error creating thrift client."));
      }
      return reply;
    });
  }

  carbon::test::ThriftTestReply sendSync(
      const carbon::test::ThriftTestRequest& request,
      std::chrono::milliseconds timeout,
      RpcStatsContext* rpcStatsContext = nullptr) {
    return sendSyncImpl([this, &request, timeout, rpcStatsContext] {
      folly::Try<apache::thrift::RpcResponseComplete<carbon::test::ThriftTestReply>> reply;
      if (auto* thriftClient = getThriftClient()) {
        auto rpcOptions = getRpcOptions(timeout);
        sendSyncHelper(thriftClient, request, rpcOptions, reply, rpcStatsContext);
      } else {
        reply.emplaceException(
            folly::make_exception_wrapper<apache::thrift::transport::TTransportException>(
              apache::thrift::transport::TTransportException::NOT_OPEN,
              "Error creating thrift client."));
      }
      return reply;
    });
  }

  McVersionReply sendSync(
      const McVersionRequest& request,
      std::chrono::milliseconds timeout,
      RpcStatsContext* rpcStatsContext = nullptr) {
    return sendSyncImpl([this, &request, timeout, rpcStatsContext] {
      folly::Try<apache::thrift::RpcResponseComplete<McVersionReply>> reply;
      if (auto* thriftClient = getThriftClient()) {
        auto rpcOptions = getRpcOptions(timeout);
        sendSyncHelper(thriftClient, request, rpcOptions, reply, rpcStatsContext);
      } else {
        reply.emplaceException(
            folly::make_exception_wrapper<apache::thrift::transport::TTransportException>(
              apache::thrift::transport::TTransportException::NOT_OPEN,
              "Error creating thrift client."));
      }
      return reply;
    });
  }

 private:
  std::unique_ptr<carbon::test::thrift::CarbonThriftTestAsyncClient> thriftClient_;
  FlushList* flushList_{nullptr};

  carbon::test::thrift::CarbonThriftTestAsyncClient* getThriftClient() {
    if (UNLIKELY(!thriftClient_)) {
      thriftClient_ = createThriftClient<carbon::test::thrift::CarbonThriftTestAsyncClient>();
      if (flushList_ || connectionOptions_.thriftCompression) {
        auto* channel = static_cast<apache::thrift::RocketClientChannel*>(
            thriftClient_->getChannel());
        if (flushList_) {
          channel->setFlushList(flushList_);
        }
        if (connectionOptions_.thriftCompression) {
          channel->setNegotiatedCompressionAlgorithm(
              apache::thrift::CompressionAlgorithm::ZSTD);
        }
      }
    }
    return thriftClient_.get();
  }

  void resetClient() override final {
    if (thriftClient_) {
      if (auto channel = thriftClient_->getChannel()) {
        // Reset the callback to avoid the following cycle:
        //  ~ThriftAsyncClient() -> ~RocketClientChannel() ->
        //  channelClosed() -> ~ThriftAsyncClient()
        channel->setCloseCallback(nullptr);
      }
      thriftClient_.reset();
    }
  }
};

} // namespace memcache
} // namespace facebook