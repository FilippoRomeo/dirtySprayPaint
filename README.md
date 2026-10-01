# Dirty Spray Paint

A remote-controlled spray-paint machine built as a physical-computing experiment in **mechanical, imperfect image-making**.

The system uses an ESP32, a PlayStation controller, two servos, a laser, and a solenoid-controlled pneumatic paint system. Rather than aiming for plotter-like precision, the project treats the instability of air pressure, mechanics, and human control as part of the visual output.

## System

```text
PS3 controller
     ↓
ESP32
 ├── pan servo
 ├── tilt servo
 ├── aiming laser
 └── solenoid valve
          ↓
    compressed air
          ↓
 pressurised paint container
          ↓
        nozzle
```

## Controls

The firmware reads the controller through `Ps3Controller` and drives the mechanism in realtime:

- left analogue stick: pan / tilt movement
- `L3`: return both servos to their centre position
- cross button: open the solenoid and activate the laser while spraying
- `R2`: toggle the aiming laser independently

The main firmware lives in `dirtySprayPaint.ino`.

## Hardware

- ESP32
- two servos for pan and tilt
- air compressor
- normally closed solenoid valve
- pressurised paint container
- tubing and spray nozzle
- laser aiming module
- PlayStation controller
- tripod-mounted pan / tilt assembly

## Code structure

```text
.
├── dirtySprayPaint.ino
├── Laser.cpp
├── Laser.h
├── SolenoidValve.cpp
├── SolenoidValve.h
├── Switchable.cpp
└── Switchable.h
```

The laser and solenoid are wrapped as small switchable components, while the Arduino sketch handles controller input and servo movement.

## How the paint system works

The solenoid normally blocks airflow from the compressor. When the spray control is held, the valve opens and compressed air enters the paint container. Pressure forces paint through the outlet tube and towards the nozzle mounted on the pan / tilt mechanism.

The operator controls the nozzle direction manually with the analogue stick, using the laser as a visual aiming reference.

## Demo

[Watch the machine in operation on YouTube](https://youtu.be/zP4An39l2bM)

## Project intent

Dirty Spray Paint explores the difference between instructing a digital image and negotiating with a physical process. Servo movement can be controlled numerically, but pressure, paint flow, mechanics, and hand input introduce behaviour that is much less exact.

That tension between software control and material unpredictability is the point of the project.

## Stack

`ESP32` `Arduino / C++` `Ps3Controller` `ESP32Servo` `pneumatics` `physical computing`

## Status

Historical physical-computing project. The repository contains the firmware used for the working prototype and a short video demonstration.
