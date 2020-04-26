#!/bin/bash

function publicip() {
    PUBLIC_IP=$(curl --silent http://ipv4.icanhazip.com/)
    if [ -z $PUBLIC_IP ]; then
        echo "NULL"
        return 1337
    else
        echo "$PUBLIC_IP"
        return 0
    fi
}

publicip
