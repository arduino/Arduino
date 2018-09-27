# Building Arduino with Docker

[Building Arduino](https://github.com/arduino/Arduino/wiki/Building-Arduino) requires some specific dependencies versions and this task can be hard if you can't have those dependencies. For this we have created this Docker image that will allow you to build your very own version of Arduino and run it on your local machine.

## Building the Docker image

`docker build -f build/Dockerfile -t arduino .` this will build the build docker image.

## Running the image

`docker run -it --rm -v "$(pwd)":/data arduino` this command runs the docker image built on previous step and shares the current project folder to `/data` directory inside docker image and will connect you to inside the docker image.

## Building inside Docker image

`cd build && ant clean dist` this command will build Arduino and 

## Exporting built runnable

