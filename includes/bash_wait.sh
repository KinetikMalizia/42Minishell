#!/bin/bash
read -s -n 1 k <&1
if [[ $k = q ]] ; then
./minishell
fi
