cmake_minimum_required(VERSION 3.13)
project(librdkafka_producer)

set(CMAKE_CXX_STANDARD 11)

#库根目录
#librdkafka
set(LIBRDKAFKA "/home/obsidian/Downloads/faceDetect/librdkafka_producer/librdkafka")

#头文件
include_directories(${LIBRDKAFKA}/include)

#源
add_executable(librdkafka_producer main.cpp CKafkaProducer.cpp CKafkaProducer.h)

#链接库
target_link_libraries(
        librdkafka_producer
        ${LIBRDKAFKA}/lib/librdkafka.so
        ${LIBRDKAFKA}/lib/librdkafka++.so
)