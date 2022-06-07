#!/bin/bash

cd /tmp/
for module in `find ./third-party | grep "makefile" | awk -F'/makefile' '{print $1}'`
do
    echo $module
    rm -rf $module
done
zip -r third-party.zip third-party