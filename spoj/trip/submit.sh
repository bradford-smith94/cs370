#!/bin/sh

pdflatex report.tex
rm report.aux
rm report.log
zip cs370-assignment6.zip ./*
rm report.pdf
