find_package(OpenCV REQUIRED)
link_libraries(opencv_imgcodecs opencv_imgproc opencv_core)
link_libraries(cr_core)
link_libraries(pthread rt dl)

cx_add_mod(cr_media cr)
