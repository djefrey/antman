#!/bin/bash

total=0
fail=0

function compress_file {
    ../../antman/antman $1 $2 > compress.txt
    ../../giantman/giantman compress.txt $2 > decompress.txt
    diff=$(diff <(cat $1) <(cat decompress.txt))
    rm compress.txt
    rm decompress.txt
    total=$((total + 1))
    if [ -n "$diff" ]
    then
        printf "\e[31mFAILED\e[0m"
        fail=$((fail + 1))
        printf "         $1" >> ../diff.txt
        printf "" >> ../diff.txt
        printf "$diff" >> ../diff.txt
        printf "" >> ../diff.txt
        printf "         -------[NEXT]-------" >> ../diff.txt
        printf "" >> ../diff.txt
    else
        printf "\e[32mSUCCESS\e[0m"
    fi
}

function compress_folder {
    fail=0

    list=`ls $1`

    cd $1
    printf "\e[1m\e[34mTests $1\e[0m\n"
    for file in $list
    do
        printf "File \e[33m$file\e[0m\n"
        compress_file $file 1
        printf "\n"
    done
    printf "\n"
    cd ..
}

function main {
    rm -f diff.txt
    compress_folder "./lyrics" 1
    compress_folder "./html" 2
    printf "\e[1mResults\e[0m\n"
    printf "Total : \e[32m$total\e[0m - Fail : \e[31m$fail\e[0m\n"
}

main