FROM ubuntu
WORKDIR /usr/src/app

RUN apt-get update
RUN apt-get -y install gcc-8 g++-8 avr-libc gcc-avr avrdude binutils-avr gdb-avr file
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-8 60 --slave /usr/bin/g++ g++ /usr/bin/g++-8
RUN cp /usr/lib/avr/include/avr/io.h /usr/lib/avr/include/avr/io2.h
RUN echo "# include <avr/iom328p.h>" | cat - /usr/lib/avr/include/avr/io.h >> /usr/lib/avr/include/avr/io2.h