#!/bin/bash

OBJ=obj
BIN=bin
USR=.users

echo -n "Initializing project..."

if [ -d "$OBJ"]
then
    echo -n "Object file already exists!"
else
    mkdir $OBJ
fi