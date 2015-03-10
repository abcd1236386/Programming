#!/bin/bash
rooturl="http://news.cnblogs.com"
url="/"
wget $rooturl$url -O "index.html2"
echo "after wget"
grep -A 2 "news_entry" "index.html2"|./removeH2|./ParseA > "finalTitle"
echo "Done"


