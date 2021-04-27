cmake_minimum_required(VERSION 3.17)
project(ImmobileAdministrator C)

set(CMAKE_C_STANDARD 99)

add_executable(ImmobileAdministrator main.c presentation/userInterface.h business/service.h presentation/userInterface.c business/service.c persistence/repository.c persistence/repository.h domain/valueObject.h validation/validator.c validation/validator.h test/test.c test/test.h domain/expense.c domain/apartment.c persistence/dynamicVector.c persistence/dynamicVector.h persistence/dynamicStaticVector.c persistence/dynamicStaticVector.h)