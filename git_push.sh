#!/bin/bash

git add .
echo "Enter git commit comment:"
read message
git commit -m "$message"
git push
