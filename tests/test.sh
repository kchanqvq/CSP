#!/bin/bash
##############################
#  Released under AGPL v2.0  #
#       CSP test script      #
#      Author: BlueFlo0d     #
#Email:hongqiantan@pku.edu.cn#
##############################
if hash ack 2>/dev/null;
then
    echo Required tool found: ack
else
    echo Required tool not found: ack
    echo Exiting
    exit 127
fi
declare -a test_files
echo "Scanning test cases."
for fn in `ls`;
do
    OLD_IFS="$IFS"
    IFS="."
    fnarr=($fn)
    IFS="$OLD_IFS"
    if [[ ${fnarr[1]} = "h" ]];
    then
        test_files+=("${fnarr[0]}")
    fi
done
if [[ ${#test_files[@]} = 1 ]];
then
    echo "1 test case found."
else
    echo "${#test_files[@]} test cases found."
fi
test_files_count=${#test_files[@]}
okcount=0
failcount=0
for (( i=0;i<test_files_count;i++))
do
    fn=${test_files[i]}
    echo "Testing $fn ($((i+1))/$test_files_count)..."
    result=`cc -E $fn.h`
    result=`echo $result|sed 's/ //g'`
    rtarget=`cat $fn.txt`
    target=`echo $rtarget|sed 's/ //g'`
    target="${target//(/\\(}"
    target="${target//)/\\)}"
    if [[ `echo $result|ack $target[^\)]*$` != "" ]];
    then
        ((okcount++))
        echo 'Test OK!'
    else
        ((failcount++))
        echo 'Test failed!'
        echo 'Expected:'
        echo $rtarget
        echo 'Got:'
        echo $result
    fi
done
echo "Test completed. $test_files_count in total, $okcount passed, $failcount failed."
