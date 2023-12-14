#!/bin/bash

# Get the number from the user
read -p "Enter a number: " number

# Reverse the number
reversed_number=$(rev "$number")

# Check if the number and its reverse are equal
if [[ "$number" == "$reversed_number" ]]; then
  echo "The number $number is a palindrome."
else
  echo "The number $number is not a palindrome."
fi