#!/usr/bin/env bash

source common.sh

if [[ ! -d "$PKG_DIR/fbthrift" ]]; then
  git clone https://github.com/facebook/fbthrift
fi

cd "$PKG_DIR/fbthrift/thrift" || die "cd fbthrift failed"

mkdir -p "$INSTALL_DIR/pymodules"

autoreconf --install
LD_LIBRARY_PATH="$INSTALL_DIR/lib:$LD_LIBRARY_PATH" \
    LD_RUN_PATH="$INSTALL_DIR/lib:$LD_RUN_PATH" \
    ./configure --prefix="$INSTALL_DIR" PY_PREFIX="$INSTALL_DIR/pymodules" \
                PY_INSTALL_HOME="$INSTALL_DIR/lib/python" \
                --without-cpp --with-folly="$INSTALL_DIR" && \
    make $MAKE_ARGS && make install $MAKE_ARGS