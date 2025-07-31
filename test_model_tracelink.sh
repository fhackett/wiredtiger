#!/usr/bin/env bash

set -x -e

pushd build
ninja
popd

rm -rf ./tmp
mkdir ./tmp

./build/test/model/tools/model_tracelink
