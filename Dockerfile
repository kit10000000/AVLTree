FROM ubuntu:16.04

RUN apt update
RUN apt install -yy gcc g++ cmake 

COPY . demo/
WORKDIR demo

RUN cmake -H. -B_build 
RUN cmake --build _build
RUN cmake --build _build --target test -- ARGS=--verbose
