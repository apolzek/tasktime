#!/bin/bash

ping www.google.com.br -c 1 >/dev/null

if [ "$?" = "0" ]; then
   echo "ping google [OK]"
else
   echo "ping google [FAIL]"
fi
