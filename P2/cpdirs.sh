#!/bin/bash

dir1=$1
dir2=$2
dir3=$3

if [[ ! -e $dir3 ]]; then
        mkdir $dir3
fi

files1=`ls $dir1`
files2=`ls $dir2`

if [ ! -d $dir1 ]; then
   echo "usage: cpdirs.sh source_directory1 source_directory2 dest_directory"
exit
fi

if [ ! -d $dir2 ]; then
   echo "usage: cpdirs.sh source_directory1 source_directory2 dest_directory"
exit
fi

if [ -f $dir3 ]; then
   echo "usage: cpdirs.sh source_directory1 source_directory2 dest_directory"
exit
fi

for var in $files1 ; do
   if [ ! -e $dir1/$var ]; then
	cp $dir1/$var $dir3
     else
      if [ -e $dir2/$var ]; then
	if [ $dir1/$var -nt $dir2/$var ]; then
	    cp $dir1/$var $dir3
        else
	    cp $dir2/$var $dir3   
        fi
      else
	cp $dir1/$var $dir3
      fi
    fi
done

for var2 in $files2 ; do
   if [ ! -e $dir2/$var2 ]; then
     cp $dir2/$var2 $dir3
     else
       if [ -e $dir1/$var2 ]; then
	  if [ $dir2/$var2 -nt $dir1/$var2 ]; then
	      cp $dir2/$var2 $dir3
  	  else
	      cp $dir1/$var2 $dir3
	  fi
	else
	    cp $dir2/$var2 $dir3
	 fi
      fi
done  
