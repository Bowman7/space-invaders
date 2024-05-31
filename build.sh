#!/bin/bash

g++ main.cpp enemies.cpp spaceship.cpp game.cpp laser.cpp shield.cpp health.cpp flame.cpp explode.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -g
