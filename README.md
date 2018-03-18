# nullfuse

**nullfuse** is a dummy Fuse based filesystem, which allows to measure the performance overhead imposed on [Fuse](https://github.com/libfuse/libfuse) based filesystems.


## Building and installation

**nullfuse** needs the following dependencies to be build:

* cmake >= 3.0.0
* Fuse >= 2.9

To build and install **nullfuse** simply follow these steps:

```
$ mkdir _build && cd _build
$ cmake ..
$ make
$ make install
```

## Usage

**nullfuse** can be mounted by running the `nullfuse` binary with provided mount point, e.g.

```
$ nullfuse /mnt/nullfuse
```

To unmount the filesystem use:

```
$ fusermout -uz /mnt/nullfuse
```

All created files and directories, along with their metadata, are persisted in memory until the **nullfuse** is unmounted. All data written to files in that filesystem however is lost, i.e. they act as `/dev/null` device. When reading the files which have non-zero size, the reading process will receive a sequence of `x` characters. e.g.

```
$ echo TEST > /mnt/nullfuse/file.txt
$ cat /mnt/nullfuse/file.txt
xxxx
```

## Testing

Below are some examples of what can be tested with the **nullfuse** filesystem:

### Measure performance of directory creation

```
$ time mkdir -p {00..99}/{00..99}         
mkdir -p {00..99}/{00..99}  0,01s user 0,12s system 99% cpu 0,129 total
```

### Measure performance of file creation

```
$ time touch {00..99}/{00..99}/file.txt    
touch {00..99}/{00..99}/file.txt  0,00s user 0,09s system 93% cpu 0,105 total
```

### Measure write throughput 

```
$ dd if=/dev/zero of=file.txt bs=1M count=1000
1000+0 records in
1000+0 records out
1048576000 bytes (1,0 GB, 1000 MiB) copied, 0,577779 s, 1,8 GB/s
```

### Measure read throughput 

```
$ dd if=file.txt of=/dev/null bs=1M
1000+0 records in
1000+0 records out
1048576000 bytes (1,0 GB, 1000 MiB) copied, 0,128954 s, 8,1 GB/s
```


## Implementation

Most of **nullfuse** is implemented using C++14 standard except for interfacing with Fuse which is in plain C.



## LICENSE

Copyright 2018 [onedata.org](onedata.org)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

[http://www.apache.org/licenses/LICENSE-2.0](http://www.apache.org/licenses/LICENSE-2.0)

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.

