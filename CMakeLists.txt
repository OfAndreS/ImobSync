cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(wx_cmake_fetchcontent_template LANGUAGES CXX)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(wxBUILD_SHARED OFF)


set(FETCHCONTENT_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.cmake_deps_cache")
file(MAKE_DIRECTORY ${FETCHCONTENT_BASE_DIR}) 
set(FETCHCONTENT_BASE_DIR ${FETCHCONTENT_BASE_DIR} CACHE PATH "Base directory for FetchContent downloads")
set(FETCHCONTENT_STAMP_DIR "${FETCHCONTENT_BASE_DIR}/stamps" CACHE PATH "Directory for FetchContent stamps")
set(FETCHCONTENT_TMP_DIR "${FETCHCONTENT_BASE_DIR}/tmp" CACHE PATH "Directory for FetchContent temporary files")

message(STATUS "Fetching wxWidgets (using cache: ${FETCHCONTENT_BASE_DIR})...")

FetchContent_Declare(
    wxWidgets
    GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
    GIT_SHALLOW ON
    SOURCE_DIR "${FETCHCONTENT_BASE_DIR}/wxWidgets"
    BINARY_DIR "${FETCHCONTENT_BASE_DIR}/wxWidgets_build"
)

FetchContent_MakeAvailable(wxWidgets)

# Define a pasta onde os arquivos-fonte estão
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Define a pasta onde os arquivos de recurso estão
set(RESOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/resources)

# Inclui os diretórios globais de cabeçalho
set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Define os arquivos-fonte da aplicação
file(GLOB_RECURSE APP_SRCS
    "${SOURCE_DIR}/main.cpp"
    "${SOURCE_DIR}/core/*.cpp" # Inclui todos os .cpp da pasta core
    "${SOURCE_DIR}/database/*.cpp" # Inclui todos os .cpp da pasta database
    "${SOURCE_DIR}/ui/**/*.cpp" # Inclui todos os .cpp da pasta ui e suas subpastas
)

if(APPLE)
    add_executable(main MACOSX_BUNDLE ${APP_SRCS})
    set_target_properties(main PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${RESOURCE_DIR}/manifest/Info.plist)
else()
    add_executable(main WIN32 ${APP_SRCS} ${RESOURCE_DIR}/manifest/main.exe.manifest)
endif()

target_link_libraries(main PRIVATE wxcore wxnet) # Continue linkando com as libs do wxWidgets

# Adiciona os diretórios de inclusão para o seu projeto
target_include_directories(main PRIVATE
    ${PROJECT_INCLUDE_DIR}
    ${SOURCE_DIR}/core # Se houver includes dentro da pasta core
    ${SOURCE_DIR}/database # Se houver includes dentro da pasta database
    ${SOURCE_DIR}/ui # Se houver includes dentro da pasta ui
    # ... e qualquer outra pasta que contenha includes para o seu próprio código
)