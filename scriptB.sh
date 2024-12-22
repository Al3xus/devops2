#!/bin/bash

ENDPOINT="http://localhost"

while true; do
    delay=$((RANDOM % 6 + 5))
    (
        response=$(curl -s -o /dev/null -w "Request to $ENDPOINT returned status %{http_code}\n" $ENDPOINT)
        echo "$response"
    ) &
    echo "Next request in $delay seconds..."
    sleep $delay
done
