# HERE OLP Protobuf example

Code sample to demonstrate how to read HERE OLP geometry data with protobuf.
HERE OLP map consists from Catalogs.<br />
Catalogs from Layers.<br />
All map is divided on tiles with IDs.<br />

This example uses one predownloaded tile from HERE OLP:
```
catalog:    here-hdlm-protobuf-weu-2
layer:      topology-geometry
partition:  327031896
```
Program parses this tile using protobuf and prints all node IDs to the console.

## Prerequisites
```
cmake
c++ 14 or higher
protoc
```

## Build
To build the project just run this script from here-olp-protobuf-example folder.
```
 ./build.sh
 ```
Internally, script runs cmake which generate c++ code from proto files.


## Run

```
cd ./build
./topology-geometry
```


## Authors
Vladimir Bezkorovainyi - volodymyr.bezkorovainyi@deutschebahn.com

