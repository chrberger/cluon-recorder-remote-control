## Microservice to start/stop a remotely running recording session

This repository provides source code for a microservice to start or stop a
remotely running microservices that await `cluon.data.RecorderCommand` messages.

[![License: GPLv3](https://img.shields.io/badge/license-GPL--3-blue.svg
)](https://www.gnu.org/licenses/gpl-3.0.txt)


## Table of Contents
* [Dependencies](#dependencies)
* [Usage](#usage)
* [Build from sources on the example of Ubuntu 16.04 LTS](#build-from-sources-on-the-example-of-ubuntu-1604-lts)
* [License](#license)


## Dependencies
You need a C++14-compliant compiler to compile this project.

The following dependency is part of the source distribution:
* [libcluon](https://github.com/chrberger/libcluon) - [![License: GPLv3](https://img.shields.io/badge/license-GPL--3-blue.svg
)](https://www.gnu.org/licenses/gpl-3.0.txt)


## Usage
Command for commandline to start a recording:
```
docker run --rm -ti --init --net=host chrberger/cluon-recorder-remote-control-multi:v0.0.1 --cid=111 --start
```

Command for commandline to start a recording:
```
docker run --rm -ti --init --net=host chrberger/cluon-recorder-remote-control-multi:v0.0.1 --cid=111 --stop
```


## Build from sources on the example of Ubuntu 16.04 LTS
To build this software, you need cmake, C++14 or newer, libyuv, libvpx, and make.
Having these preconditions, just run `cmake` and `make` as follows:

```
mkdir build && cd build
cmake -D CMAKE_BUILD_TYPE=Release ..
make && make test && make install
```


## License

* This project is released under the terms of the GNU GPLv3 License

