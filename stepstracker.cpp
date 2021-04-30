/*
 * Copyright (C) 2021 - Darrel Griët <idanlcontact@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <giomm.h>
#include "stepstracker.h"
#include <QtSensors/QStepCounterSensor>
#include <QDebug>


StepsTracker::StepsTracker(QObject *parent) : QObject(parent) {
    m_stepCounterSensor = new QStepCounterSensor(this);
    QObject::connect(m_stepCounterSensor, SIGNAL(readingChanged()), this, SLOT(stepsChanged()));
    QObject::connect(m_stepCounterSensor, SIGNAL(sensorError(int)), this, SLOT(sensorError(int)));
    //m_stepCounterSensor->setAlwaysOn(true); // Holds a wakelock!
    
    if (!m_stepCounterSensor->connectToBackend()) {
        qWarning() << "Could not connect to the orientation sensor backend";
    } else {
        if (!m_stepCounterSensor->start())
            qWarning() << "Could not start the orientation sensor";
    }
}

void StepsTracker::stepsChanged() {
    QStepCounterReading* reading = m_stepCounterSensor->reading();
    qWarning() << "READING " << reading->steps();

    const Glib::RefPtr<Gio::Settings> settings = Gio::Settings::create("org.asteroidos.fitness");
    settings->set_int("steps", reading->steps());
}
void StepsTracker::sensorError(int error) {

}