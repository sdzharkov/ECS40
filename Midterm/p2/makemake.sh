#!/bin/bash

final=$1
new=$final
if [[ $# -eq 0 ]]; 
   then echo "Executable name required."
   echo "usage: makemake.sh executable_name"
   exit 1
fi

echo -e -n  "$1 : " > Makefile
for f in *.cpp; do
   echo -e -n "${f%*cpp}o " >> Makefile
done
echo -e -n "\n\tg++ -ansi -Wall -g -o $final " >> Makefile 
shift

for v in $@ ; do
   echo -n "$v " >>Makefile
done

for f in *.cpp; do
   echo -e -n "${f%*cpp}o " >> Makefile
done
echo >> Makefile

for f in *.cpp; do
   echo -e -n  "\n${f%*cpp}o : $f " >> Makefile
   awk -F \" ' /#include *\"/ {printf( $2" " ) } ' $f  >> Makefile
   echo -e -n "\n\tg++ -ansi -Wall -g -c " >> Makefile 

   for var in $@; do
      echo -n "$var " >> Makefile
   done
   
   echo -n "$f " >> Makefile
   echo >> Makefile
done
echo >> Makefile 

echo -e -n  "clean : " >> Makefile
echo -e -n "\n\trm -f $new " >> Makefile
 
for f in *.cpp; do
   echo -e -n "${f%*cpp}o  " >> Makefile
done

echo >> Makefile
