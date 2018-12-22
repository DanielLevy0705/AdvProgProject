cmake_minimum_required(VERSION 3.12)
project(untitled4)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(untitled4 main.cpp BindedSymbolMap.h Value.h LocalValue.h BindedValue.h OpenDataServerCommand.h
               ConnectCommand.h Expressioner.h BindedValue.h Inputer.h )