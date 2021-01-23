#!/bin/bash

total=0
fail=0

function compress_file {
    ../../antman/antman $1 $2 > compress.txt
    ../../giantman/giantman compress.txt $2 > decompress.txt
    diff=$(diff <(cat $1) <(cat decompress.txt))
    ori_size=$(stat -c%s $1)
    compress_size=$(stat -c%s compress.txt)
    if [ $ori_size -eq 0 ]
    then
        ratio=0
    else
        ratio=$(bc -l <<< "scale=2;(1-$compress_size/$ori_size)*100")
    fi
    rm compress.txt
    rm decompress.txt
    total=$((total + 1))
    if [ -n "$diff" ]
    then
        printf "\e[31mFAILED\e[0m"
        fail=$((fail + 1))
        printf "         $1\n$diff\n         -------[NEXT]-------\n" >> ../diff.txt
    else
        printf "\e[32mSUCCESS $ratio%%\e[0m"
    fi
}

function compress_folder {
    fail=0

    list=`ls $1`

    cd $1
    printf "\e[1m\e[34mTests $1\e[0m\n"
    for file in $list
    do
        if [ $file = "compress.txt" ] || [ $file = "decompress.txt" ]
        then
            continue
        fi
        printf "File \e[33m$file\e[0m\n"
        compress_file $file $2
        printf "\n"
    done
    printf "\n"
    cd ..
}

function main {
    rm -f diff.txt
    compress_folder "./lyrics" 1
    compress_folder "./html" 2
    compress_folder "./ppm" 3
    printf "\e[1mResults\e[0m\n"
    printf "Total : \e[32m$total\e[0m - Fail : \e[31m$fail\e[0m\n"
}

main