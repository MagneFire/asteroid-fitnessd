TEMPLATE = app
QT -= gui
QT += dbus sensors
CONFIG += link_pkgconfig c++11
PKGCONFIG += giomm-2.4

HEADERS += \
    stepstracker.h
SOURCES += main.cpp \
    stepstracker.cpp

TRANSLATIONS = $$files(i18n/$$TARGET.*.ts)

TARGET = asteroid-fitnessd
target.path = /usr/bin/

schemas.files = org.asteroidos.steps.gschema.xml
schemas.path = /usr/share/glib-2.0/schemas/

INSTALLS += target schemas
