cmake_minimum_required(VERSION 3.28)
project(PingPongProject LANGUAGES CXX) # Назовем проект "PingPongProject"

# 1. Настройка вывода исполняемого файла (он будет в build/bin/PingPong)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# 2. Использование FetchContent для автоматической загрузки SFML (Рекомендуемый современный подход)
include(FetchContent)
FetchContent_Declare(sfml
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(sfml)
# 3. Компиляция исходных файлов
# Добавляем ВСЕ ваши .cpp файлы
add_executable(PingPong  # Используем имя проекта как имя исполняемого файла
    src/main.cpp
    src/ball.cpp
    src/bat.cpp
    src/RandomGenerator.cpp
)

# 4. Настройка компилятора для вашей цели
# Установка стандарта C++17
target_compile_features(PingPong PRIVATE cxx_std_17)

# 5. Указание, где искать ВАШИ заголовочные файлы (.h)
# (${CMAKE_SOURCE_DIR} - это корень вашего проекта, где лежит src/ и include/)
target_include_directories(PingPong PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

# 6. Линковка
# Линкуем с скомпилированными модулями SFML, которые стали доступны через FetchContent
target_link_libraries(PingPong PRIVATE SFML::Graphics SFML::Window SFML::System SFML::Audio)
# Я добавил SFML::Window, так как он нужен для работы с окном.