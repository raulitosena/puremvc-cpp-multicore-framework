
set(TARGET puremvc_app)

add_executable(${TARGET}
 	main.cpp
)

add_dependencies(${TARGET} 
	${LIBRARY_NAME}
)

target_link_libraries(${TARGET} PUBLIC
	${LIBRARY_NAME}
)

