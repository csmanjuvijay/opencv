project(stitching)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${OpenCV_SOURCE_DIR}/modules/core/include"
    "${OpenCV_SOURCE_DIR}/modules/imgproc/include"
    "${OpenCV_SOURCE_DIR}/modules/objdetect/include"
    "${OpenCV_SOURCE_DIR}/modules/ml/include"
    "${OpenCV_SOURCE_DIR}/modules/highgui/include"
    "${OpenCV_SOURCE_DIR}/modules/video/include"
    "${OpenCV_SOURCE_DIR}/modules/features2d/include"
    "${OpenCV_SOURCE_DIR}/modules/flann/include"
    "${OpenCV_SOURCE_DIR}/modules/calib3d/include"
    "${OpenCV_SOURCE_DIR}/modules/legacy/include"
    "${OpenCV_SOURCE_DIR}/modules/imgproc/src" # for gcgraph.hpp
    "${OpenCV_SOURCE_DIR}/modules/gpu/include"
    )

set(stitching_libs opencv_core pthread opencv_imgproc opencv_highgui opencv_features2d opencv_calib3d opencv_gpu)

FILE(GLOB stitching_files "*.hpp" "*.cpp")

set(the_target opencv_stitching)    
add_executable(${the_target} ${stitching_files})

add_dependencies(${the_target} ${stitching_libs})
set_target_properties(${the_target} PROPERTIES
                      DEBUG_POSTFIX "${OPENCV_DEBUG_POSTFIX}"
                      ARCHIVE_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_PATH}
                      RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
                      INSTALL_NAME_DIR lib
                      OUTPUT_NAME "opencv_stitching")
					  
if(ENABLE_SOLUTION_FOLDERS)
	set_target_properties(${the_target} PROPERTIES FOLDER "applications")
endif()	

target_link_libraries(${the_target} ${stitching_libs})

install(TARGETS ${the_target} RUNTIME DESTINATION bin COMPONENT main)
