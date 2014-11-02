#!/bin/bash
if [ "$1" = "" ];then
    echo "missing file name";
    exit;
fi
if [ ! -f "$1".cpp ];then
    echo "no such $1.cpp file";
    exit;
fi
g++ "$1.cpp"
./a.out
