cmake_minimum_required(VERSION 3.12)
project(untitled4)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(untitled4 main.cpp BindedSymbolMap.h Value.h LocalValue.h BindedValue.h OpenDataServerCommand.h
               ConnectCommand.h Expressioner.h BindedValue.h Inputer.h BindedSymbolMap.cpp StringsLibrary.cpp
            StringsLibrary.h StringExpression.h PrintCommand.h BindCommand.h
            VarCommand.h  NewExpression.h ValueExpression.h Command.h AssignmentCommand.h ProgramTools.h Expressioner.cpp Parser.cpp CommandSet.h IfCommand.h SetExpression.h ConditionExpression.h ConditionExpression.cpp ExitCommand.h CommandSet.cpp WhileCommand.h VarCommand.cpp Expointer.h Lexer.cpp CommandExpression.h Command.h Commands.h)