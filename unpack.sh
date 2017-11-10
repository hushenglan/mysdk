#!/bin/sh

pushd $CURRENT_DIR/deps/gtest
rm -fr ./googletest-release-1.8.0
tar -zxvf ./googletest-release-1.8.0.tar.gz
cd googletest-release-1.8.0/googletest/make
make gtest.a gtest_main.a
popd
