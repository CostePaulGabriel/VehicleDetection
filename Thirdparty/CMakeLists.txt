# This CMake script will download and configure the external libraries

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

include(DownloadOCV)
DownloadOCV()
