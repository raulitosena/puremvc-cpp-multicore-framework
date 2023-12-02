
cmake_minimum_required(VERSION 3.10.0)
project(PureMVC LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# PIC allows the shared library to be loaded at any available address, 
# ensuring independence from the memory layout of the main program or other shared libraries.
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# RPATH specify directories to search for shared libraries at runtime.
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

# $ORIGIN refers to the directory where the executable is located.
set(CMAKE_INSTALL_RPATH "$ORIGIN")

set(BASE_DIR ${CMAKE_CURRENT_LIST_DIR})
set(TM_BUILD ${BASE_DIR}/build/${CMAKE_BUILD_TYPE})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${TM_BUILD})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${TM_BUILD})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TM_BUILD})

include_directories(
	${CMAKE_CURRENT_LIST_DIR}/include
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(LIBRARY_NAME "PureMVCd")
else()
    set(LIBRARY_NAME "PureMVC")
endif()

include_directories(${CMAKE_CURRENT_LIST_DIR}/src)

add_library(${LIBRARY_NAME} STATIC
	include/PureMVC/Interfaces/INotifier.hpp
	include/PureMVC/Interfaces/IProxy.hpp
	include/PureMVC/Interfaces/IIterator.hpp
	include/PureMVC/Interfaces/IFacade.hpp
	include/PureMVC/Interfaces/IAggregate.hpp
	include/PureMVC/Interfaces/ICommand.hpp
	include/PureMVC/Interfaces/IModel.hpp
	include/PureMVC/Interfaces/IMediator.hpp
	include/PureMVC/Interfaces/IController.hpp
	include/PureMVC/Interfaces/IObserver.hpp
	include/PureMVC/Interfaces/IView.hpp
	include/PureMVC/Interfaces/INotification.hpp
	include/PureMVC/Patterns/Mediator/Mediator.hpp
	include/PureMVC/Patterns/Iterator/Iterator.hpp
	include/PureMVC/Patterns/Observer/Notification.hpp
	include/PureMVC/Patterns/Observer/Observer.hpp
	include/PureMVC/Patterns/Observer/Notifier.hpp
	include/PureMVC/Patterns/Command/MacroCommand.hpp
	include/PureMVC/Patterns/Command/SimpleCommand.hpp
	include/PureMVC/Patterns/Command/DelegateCommand.hpp
	include/PureMVC/Patterns/Facade/Facade.hpp
	include/PureMVC/Patterns/Proxy/Proxy.hpp
	include/PureMVC/PureMVC.hpp
	include/PureMVC/Core/View.hpp
	include/PureMVC/Core/Model.hpp
	include/PureMVC/Core/Controller.hpp

	src/PureMVC/PureMVC.cpp
	src/PureMVC/Common.hpp
	src/PureMVC/Patterns/Mediator/Mediator.cpp
	src/PureMVC/Patterns/Observer/Notification.cpp
	src/PureMVC/Patterns/Observer/Notifier.cpp
	src/PureMVC/Patterns/Command/SimpleCommand.cpp
	src/PureMVC/Patterns/Command/MacroCommand.cpp
	src/PureMVC/Patterns/Facade/Facade.cpp
	src/PureMVC/Patterns/Proxy/Proxy.cpp
	src/PureMVC/Core/Model.cpp
	src/PureMVC/Core/View.cpp
	src/PureMVC/Core/Controller.cpp
)

link_directories(
	${TM_BUILD}
)

include_directories(
	${BASE_DIR}/include
)

add_subdirectory(puremvc_app)

