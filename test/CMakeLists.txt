set(CMAKE_CXX_STANDARD 14)

SET(GOOGLETEST_VERSION "1.12.1")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-${GOOGLETEST_VERSION}.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

include_directories(../src)
add_subdirectory(unit)

