function(DownloadOCV)

    include(FetchContent)
    if(NOT EXISTS "${THIRDPARTY_DIR}/opencv")
        FetchContent_Declare(
            opencv
            SOURCE_DIR "${THIRDPARTY_DIR}/opencv"
            GIT_REPOSITORY https://github.com/opencv/opencv.git
            GIT_TAG 4.6.0
            GIT_PROGRESS TRUE
        )
        FetchContent_MakeAvailable(opencv)
    endif()

endfunction()
