cmake_minimum_required(VERSION 3.1...3.29)

project(clydespace_challenge
  VERSION
    1.0
  DESCRIPTION
    "Clydespace Challenge"
  LANGUAGES
    C
)

set(SRC_LIST
    challenge_api.c
    i2c.c
    main.c
)

add_executable(main ${SRC_LIST} ${HEADER_LIST})
target_include_directories(main PRIVATE includes)