FROM ubuntu
WORKDIR /usr/src/app

RUN apt-get update
RUN apt-get -y install gcc-8 g++-8
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-8 60 --slave /usr/bin/g++ g++ /usr/bin/g++-8
# RUN apt-get install nano