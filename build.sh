#!/bin/bash

g++ main.cpp src/enemies.cpp src/spaceship.cpp src/game.cpp src/laser.cpp src/shield.cpp src/health.cpp src/flame.cpp src/explode.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -g
