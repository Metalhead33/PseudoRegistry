#-------------------------------------------------
#
# Project created by QtCreator 2016-12-26T19:07:19
#
#-------------------------------------------------

#QT       -= core gui

TARGET = RegistryStructure
TEMPLATE = lib

DEFINES += REGISTRYSTRUCTURE_LIBRARY

unix {
    target.path = /usr/local/lib
    header_files.path = /usr/local/include
    header_files.files = $$HEADERS
    INSTALLS += header_files
    INSTALLS += target
}

VPATH += ./src
INCLUDEPATH += ./inc
INCLUDEPATH += ./inc/Filetypes
INCLUDE += ./inc

HEADERS += \
    inc/Filetypes/CustomFile.hpp \
    inc/Filetypes/RawFile.hpp \
    inc/Filetypes/RawFileContainer.hpp \
    inc/Filetypes/String16File.hpp \
    inc/Filetypes/String32File.hpp \
    inc/Filetypes/StringFile.hpp \
    inc/Directory.hpp \
    inc/Element.hpp \
    inc/File.hpp \
    inc/Global.h \
    inc/Seeker.hpp \
    inc/Tokenizer.h \
    inc/Unserialize.hpp

SOURCES += \
    src/Filetypes/RawFile.cpp \
    src/Filetypes/RawFileContainer.cpp \
    src/Filetypes/String16File.cpp \
    src/Filetypes/String32File.cpp \
    src/Filetypes/StringFile.cpp \
    src/Directory.cpp \
    src/Element.cpp \
    src/File.cpp \
    src/Seeker.cpp \
    src/Unserialize.cpp \
    src/Tokenizer.c
