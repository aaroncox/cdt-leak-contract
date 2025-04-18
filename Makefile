#!/bin/bash

.PHONY: build
build:
	cdt-cpp -abigen -abigen_output=build/buggy.abi -o build/buggy.wasm src/buggy.cpp -R src -I include -D DEBUG
