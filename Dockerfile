FROM python:3.8.12-slim-bullseye

RUN apt update

RUN apt install -y libboost-dev \
    libpolyclipping-dev \
    libnlopt-cxx-dev \
    cmake \
    build-essential

RUN pip install nest2D

