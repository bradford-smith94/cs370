#!/bin/sh
# Mike Curry, Kareem Mohamed and Bradford Smith
# CS 370 Group Project 2 SPOJ LCMSUM
# 04/29/2016
# "We pledge our honor that we have abided by the Stevens Honor System"

# make sure to build the presentation
make -C presentation all
make -C presentation clean

# make sure C-soln is clean
make -C C-soln fclean

zip -r cs370_group-project2.zip ./*
