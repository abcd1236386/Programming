#!/bin/bash
rooturl="http://news.cnblogs.com"
url="/"
wget $rooturl$url -O "index.html2"
echo "after wget"
grep -A 2 "news_entry" "index.html2"|sed -n 2~4p|./ParseA > "finalTitle"
echo "Done"


