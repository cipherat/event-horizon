#!/usr/bin/bash

set -xe

if [[ "$1" == "build" ]]; then
	cc -Wall -Wextra -lm event-horizon.c -o event-horizon
elif [[ "$1" == "run" ]]; then
	./event-horizon
else
	cc -Wall -Wextra -lm event-horizon.c -o event-horizon
	./event-horizon
fi
