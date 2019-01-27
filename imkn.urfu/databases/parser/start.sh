#!/bin/bash

PGUSER=ts_admin \
PGHOST=localhost \
PGPASSWORD=qweqwe \
PGDATABASE=test_system \
PGPORT=5433 \
HOST=http://10.0.0.129 \
node index.js
