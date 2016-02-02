#!/bin/bash
# grepdir

dir=$1
pattern=$2
if [[ $# -lt 2 ]] 
   then echo "usage: grepdir.sh directory pattern [-grep option]*"
   exit 1
fi
if [[ ! -d $dir ]]
   then echo "usage: grepdir.sh directory pattern [-grep option]*"
   exit 1
fi

shift 
shift 
for var in $@; do
	if [[ "$var" != -* ]]
	    then
            echo "usage: grepdir.sh directory pattern [-grep option]*"
	    exit 1
        else
	    continue
	fi
done
find $dir -type f  -exec grep $@ "$pattern" {} \;
shift
[[
