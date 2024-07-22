cmake_minimum_required(VERSION 3.25)
project(Work5)

set(CMAKE_CXX_STANDARD 17)

add_executable(Work5 main.cpp Address.h Address.cpp Person.cpp Person.h Lawyer.cpp Lawyer.h Client.cpp Client.h LawFirm.cpp LawFirm.h)
