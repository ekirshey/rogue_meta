include_directories(
	${PROJECT_SOURCE_DIR}/src
)
	
file( GLOB SRC 
	#INCLUDE
	${PROJECT_SOURCE_DIR}/src/*.h

	#SOURCE
	${PROJECT_SOURCE_DIR}/src/*.cpp
)

add_executable(meta_rogue
	${SRC}
)