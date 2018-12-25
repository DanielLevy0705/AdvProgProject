cmake_minimum_required(VERSION 3.12)
project(untitled4)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(untitled4 main.cpp BindedSymbolMap.h Value.h LocalValue.h BindedValue.h OpenDataServerCommand.h
               ConnectCommand.h Expressioner.h BindedValue.h Inputer.h BindedSymbolMap.cpp StringsLibrary.cpp
            StringsLibrary.h StringExpression.h PrintCommand.h BindCommand.h
            VarCommand.h  NewExpression.h Printable.h ValueExpression.h Commands.h AssignmentCommand.h Expressions.h ProgramTools.h Expressioner.cpp Parser.cpp BoolExpression.h CommandSet.h IfCommand.h SetExpression.h ConditionExpression.h ConditionExpression.cpp ExitCommand.cpp ExitCommand.h CommandSet.cpp)