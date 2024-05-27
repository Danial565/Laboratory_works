cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME CmakeGit)				 # имя проекта		 
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/file/time.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

include_directories("inc/")


add_executable("${PROJECT_NAME}" main.cpp src/Func.cpp inc/Func.hpp file/time.txt)
											
