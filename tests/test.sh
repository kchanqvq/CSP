#!/bin/bash
##############################
#  Released under AGPL v2.0  #
#       CSP test script      #
#      Author: BlueFlo0d     #
#Email:hongqiantan@pku.edu.cn#
##############################
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
    echo "Testing $fn (${i+1}/$test_files_count)..."
    result=`cc -E $fn.h`
    result=`echo $result|sed 's/[ \t]*//g'`
    target=`cat $fn.txt`
    target=`echo $target|sed 's/[ \t]*//g'`
    if [[ "$result" =~ "$target" ]];
    then
        ((okcount++))
        echo 'Test OK!'
    else
        ((failcount++))
        echo 'Test failed!'
        echo 'Expected:'
        echo $target
        echo 'Got:'
        echo $result
    fi
done
echo "Test completed. $test_files_count in total, $okcount passed, $failcount failed."
