#!/bin/bash

OBJ=obj
BIN=bin
USR=.users

echo -e "Initializing project..."
echo -e ""

if [ -d "$OBJ" ]
then
    echo -e "Object folder already exists!"
else
    echo -e "Created object folder!"
    mkdir $OBJ
fi

if [ -d "$BIN" ]
then
    echo -e "Binary folder already exists!"
else
    echo -e "Created binary folder!"
    mkdir $BIN
fi

if [ -d "$USR" ]
then
    echo -e "Users folder already exists!"
else
    echo -e "Created users folder!"
    mkdir $USR
    touch $USR/.user_meta
    chmod 700 $USR
fi

echo -e ""
echo -e "PassPal has been succesfully created! Type 'make && make run' to start PassPal!" 