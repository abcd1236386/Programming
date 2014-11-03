#!/bin/bash
if [ "$1" = "" ];then
    echo "missing file name";
    exit;
fi
file="$1"
if [ ! -f "$1"  ];then
    file="$file.cpp";
    if [ ! -f "$file" ]; then
        echo "no such $1.cpp file";
        exit;
    fi
fi
g++ "$file"
./a.out
