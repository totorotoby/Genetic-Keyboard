#!/bin/sh

tr '[:upper:]' '[:lower:]' < text.txt > testfile

cat testfile | tr -cd '[:alpha:].?,;\s\"' > testfile1