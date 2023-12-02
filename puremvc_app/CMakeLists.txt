
set(TARGET puremvc_app)

add_executable(${TARGET}
 	main.cpp
)

add_dependencies(${TARGET} 
	PureMVClito
)

target_link_libraries(${TARGET} PUBLIC
	PureMVClito
)

