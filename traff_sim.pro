######################################################################
# Automatically generated by qmake (3.0) Fri Jul 3 11:25:06 2015
######################################################################
TEMPLATE = app
TARGET = traff_sim
CONFIG += c++11
DEFINES += QTCTREATOR
LIBS += -lpthread -lboost_system -lboost_thread

INCLUDEPATH += . test vendors/jsoncons/src

SOURCES += \
    main.cpp \
#    test/lizard/lizard.cpp \
    src/street.cpp \
    src/car.cpp \
    src/utilities.cpp \
    src/base_event.cpp \
    src/joint.cpp \
    src/city.cpp \
    src/server.cpp \
    src/main.helper.cpp

HEADERS += \
    inc/stdafx.hpp \
    inc/street.hpp \
    inc/car.hpp \
    inc/utilities.hpp \
    inc/base_event.hpp \
    inc/joint.hpp \
    test/lizard/lizard.hpp \
    test/lizard/stdafx.hpp \
    test/lizard/utilities.hpp \
    test/tests/basic/car_tester.hpp \
    test/tests/basic/joint_tester.hpp \
    test/tests/basic/street_tester.hpp \
    test/manifest.hpp \
    test/tests/basic/joint_kill_tester.hpp \
    test/tests/basic/joint_hold_tester.hpp \
    inc/city.hpp \
    inc/server.hpp \
    inc/http_request.hpp \
    inc/main.helper.hpp \
    vendors/jsoncons/src/jsoncons/json.hpp \
    vendors/jsoncons/src/jsoncons/json_deserializer.hpp \
    vendors/jsoncons/src/jsoncons/json_error_category.hpp \
    vendors/jsoncons/src/jsoncons/json_filter.hpp \
    vendors/jsoncons/src/jsoncons/json_input_handler.hpp \
    vendors/jsoncons/src/jsoncons/json_output_handler.hpp \
    vendors/jsoncons/src/jsoncons/json_parser.hpp \
    vendors/jsoncons/src/jsoncons/json_reader.hpp \
    vendors/jsoncons/src/jsoncons/json_serializer.hpp \
    vendors/jsoncons/src/jsoncons/json_structures.hpp \
    vendors/jsoncons/src/jsoncons/json_type_traits.hpp \
    vendors/jsoncons/src/jsoncons/jsoncons.hpp \
    vendors/jsoncons/src/jsoncons/jsoncons_config.hpp \
    vendors/jsoncons/src/jsoncons/jsoncons_io.hpp \
    vendors/jsoncons/src/jsoncons/output_format.hpp \
    vendors/jsoncons/src/jsoncons/ovectorstream.hpp \
    vendors/jsoncons/src/jsoncons/parse_error_handler.hpp
