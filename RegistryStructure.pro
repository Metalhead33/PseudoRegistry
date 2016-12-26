#-------------------------------------------------
#
# Project created by QtCreator 2016-12-26T19:07:19
#
#-------------------------------------------------

#QT       -= core gui

TARGET = RegistryStructure
TEMPLATE = lib

DEFINES += REGISTRYSTRUCTURE_LIBRARY

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

unix {
    target.path = /usr/local/lib
    header_files1.path = /usr/local/include/RegistryStructure
    header_files1.files = ./inc/*
    header_files2.path = /usr/local/include/RegistryStructure/Filetypes
    header_files2.files = ./inc/Filetypes/*
    INSTALLS += target
    INSTALLS += header_files1
    INSTALLS += header_files2
}
