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

#ifndef STEPSTRACKER_H
#define STEPSTRACKER_H

#include <QObject>

class QStepCounterSensor;

class StepsTracker : public QObject
{
    Q_OBJECT
public:
    explicit StepsTracker(QObject *parent = 0);
private slots:
    void stepsChanged();
    void sensorError(int error);
private:
    QStepCounterSensor* m_stepCounterSensor;
};

#endif // STEPSTRACKER_H