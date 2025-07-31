
#pragma once

#include <string_view>
#include <msgpack.hpp>
#include "tracelink-workload.hpp"

namespace Storage {

struct StartTransaction {
    static constexpr std::string_view _name_ = "StartTransaction";
    tracelink::Packable n, tid, readTs, rc, ignorePrepare;
    bool _did_abort = false;
    tracelink::Packable _meta;
    MSGPACK_DEFINE_MAP(n, tid, readTs, rc, ignorePrepare, _did_abort, _meta);
};

struct TransactionWrite {
    static constexpr std::string_view _name_ = "TransactionWrite";
    tracelink::Packable n, tid, k, v, ignoreWriteConflicts;
    bool _did_abort = false;
    tracelink::Packable _meta;
    MSGPACK_DEFINE_MAP(n, tid, k, v, ignoreWriteConflicts, _did_abort, _meta);
};

struct TransactionRead {
    static constexpr std::string_view _name_ = "TransactionRead";
    tracelink::Packable n, tid, k, v;
    bool _did_abort = false;
    tracelink::Packable _meta;
    MSGPACK_DEFINE_MAP(n, tid, k, v, _did_abort, _meta);
};

struct TransactionRemove {
    static constexpr std::string_view _name_ = "TransactionRemove";
    tracelink::Packable n, tid, k;
    bool _did_abort = false;
    tracelink::Packable _meta;
    MSGPACK_DEFINE_MAP(n, tid, k, _did_abort, _meta);
};

struct PrepareTransaction {
    static constexpr std::string_view _name_ = "PrepareTransaction";
    tracelink::Packable n, tid, prepareTs;
    bool _did_abort = false;
    tracelink::Packable _meta;
    MSGPACK_DEFINE_MAP(n, tid, prepareTs, _did_abort, _meta);
};

struct CommitTransaction {
    static constexpr std::string_view _name_ = "CommitTransaction";
    tracelink::Packable n, tid, commitTs;
    bool _did_abort = false;
    tracelink::Packable _meta;
    MSGPACK_DEFINE_MAP(n, tid, commitTs, _did_abort, _meta);
};

struct CommitPreparedTransaction {
    static constexpr std::string_view _name_ = "CommitPreparedTransaction";
    tracelink::Packable n, tid, commitTs, durableTs;
    bool _did_abort = false;
    tracelink::Packable _meta;
    MSGPACK_DEFINE_MAP(n, tid, commitTs, durableTs, _did_abort, _meta);
};

struct AbortTransaction {
    static constexpr std::string_view _name_ = "AbortTransaction";
    tracelink::Packable n, tid;
    bool _did_abort = false;
    tracelink::Packable _meta;
    MSGPACK_DEFINE_MAP(n, tid, _did_abort, _meta);
};

struct SetStableTimestamp {
    static constexpr std::string_view _name_ = "SetStableTimestamp";
    tracelink::Packable n, ts;
    bool _did_abort = false;
    tracelink::Packable _meta;
    MSGPACK_DEFINE_MAP(n, ts, _did_abort, _meta);
};

struct SetOldestTimestamp {
    static constexpr std::string_view _name_ = "SetOldestTimestamp";
    tracelink::Packable n, ts;
    bool _did_abort = false;
    tracelink::Packable _meta;
    MSGPACK_DEFINE_MAP(n, ts, _did_abort, _meta);
};

struct RollbackToStable {
    static constexpr std::string_view _name_ = "RollbackToStable";
    tracelink::Packable n;
    bool _did_abort = false;
    tracelink::Packable _meta;
    MSGPACK_DEFINE_MAP(n, _did_abort, _meta);
};

using AnyOperation = std::variant<
    StartTransaction
    , TransactionWrite
    , TransactionRead
    , TransactionRemove
    , PrepareTransaction
    , CommitTransaction
    , CommitPreparedTransaction
    , AbortTransaction
    , SetStableTimestamp
    , SetOldestTimestamp
    , RollbackToStable
>;
};
    