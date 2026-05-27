<div align="center" style="text-align: center;">

<h1>unofficial opendb-c</h1>
<p>
  <b>opendbc is a Python API for your car.</b>
  <br>
  <b>opendb-c is a fork of opendbc, a C API for your car.</b>
  <br>
  Control the gas, brake, steering, and more. Read the speed, steering angle, and more, with morals in mind.
  <br>
  <b> -> i highly discourage the use of this, this fork is not official and the only reviewer is me <- </b>
  <br>
  this is a project i am doing just for fun and for a learning experience, most if not all links lead to official sources.
</p>

<h3>
  <a href="https://docs.comma.ai">official docs</a>
  <span> · </span>
  <a href="https://discord.comma.ai">official discord</a>
</h3>

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![X Follow](https://img.shields.io/twitter/follow/comma_ai)](https://x.com/comma_ai)
[![Discord](https://img.shields.io/discord/469524606043160576)](https://discord.comma.ai)

<br>
<h3><i>How to Port a Car — Jason Young, COMMA_CON 2023</i></h3>
<a href="https://www.youtube.com/watch?v=XxPS5TpTUnI&t=142s">
  <img src="https://github.com/user-attachments/assets/ae89198e-561b-4210-a0d4-ccecd917577d" alt="▶ How to Port a Car - Jason Young, COMMA_CON 2023" width="800">
</a>
<br>

<h3><i>How Do We Control The Car? — Robbe Derks, COMMA_CON 2021</i></h3>
<a href="https://www.youtube.com/watch?v=nNU6ipme878">
  <img src="https://github.com/user-attachments/assets/28c40bc0-7884-47e9-b392-f47f03190497" alt="▶ How Do We Control The Car? - Robbe Derks, COMMA_CON 2021" width="800">
</a>
<br>

</div>

---

Most cars since 2016 have electronically-actuatable steering, gas, and brakes thanks to [LKAS](https://en.wikipedia.org/wiki/Lane_departure_warning_system#Lane_keeping_and_next_technologies) and [ACC](https://en.wikipedia.org/wiki/Adaptive_cruise_control).
The goal of this project is to support controlling the steering, gas, and brakes on every single one of those cars.

While the primary focus is on supporting ADAS interfaces for [openpilot](https://github.com/commaai/openpilot), we're also interested in reading and writing as many things as we can (EV charge status, lock/unlocking doors, etc) such that we can build the best vehicle management app ever.

---

if you would like to interact with opendbc, please head over to the [official project](https://github.com/commaai/opendbc/).

### Project Structure
* [`opendbc/dbc/`](opendbc/dbc/) is a repository of [DBC](https://en.wikipedia.org/wiki/CAN_bus#DBC_(CAN_Database_Files)) files
* [`opendbc/can/`](opendbc/can/) is a library for parsing and building CAN messages from DBC files
* [`opendbc/car/`](opendbc/car/) is a high-level library for interfacing with cars using Python
* [`opendbc/safety/`](opendbc/safety/) is the functional safety for all the cars supported by `opendbc/car/`

### Terms

* **port**: refers to the integration and support of a specific car
* **lateral control**: aka steering control
* **longitudinal control**: aka gas/brakes control
* **fingerprinting**: automatic process for identifying the car
* **[LKAS](https://en.wikipedia.org/wiki/Lane_departure_warning_system)**: lane keeping assist
* **[ACC](https://en.wikipedia.org/wiki/Adaptive_cruise_control)**: adaptive cruise control
* **[harness](https://comma.ai/shop/car-harness)**: car-specific hardware to attach to the car and intercept the ADAS messages
* **[panda](https://github.com/commaai/panda)**: hardware used to get on a car's CAN bus
* **[ECU](https://en.wikipedia.org/wiki/Electronic_control_unit)**: computers or control modules inside the car
* **[CAN bus](https://en.wikipedia.org/wiki/CAN_bus)**: a bus that connects the ECUs in a car
* **[cabana](https://github.com/commaai/openpilot/tree/master/tools/cabana#readme)**: our tool for reverse engineering CAN messages
* **[DBC file](https://en.wikipedia.org/wiki/CAN_bus#DBC)**: contains definitions for messages on a CAN bus
* **[openpilot](https://github.com/commaai/openpilot)**: an ADAS system for cars supported by opendbc
* **[comma](https://github.com/commaai)**: the company behind opendbc
* **[comma four](https://comma.ai/shop/comma-four)**: the hardware used to run openpilot

### More resources

* [*How Do We Control The Car?*](https://www.youtube.com/watch?v=nNU6ipme878&pp=ygUoY29tbWEgY29uIDIwMjEgaG93IGRvIHdlIGNvbnRyb2wgdGhlIGNhcg%3D%3D) by [@robbederks](https://github.com/robbederks) from COMMA_CON 2021
* [*How to Port a Car*](https://www.youtube.com/watch?v=XxPS5TpTUnI&t=142s&pp=ygUPamFzb24gY29tbWEgY29u) by [@jyoung8607](https://github.com/jyoung8607) from COMMA_CON 2023
* [commaCarSegments](https://huggingface.co/datasets/commaai/commaCarSegments): a massive dataset of CAN data from 300 different car models
* [cabana](https://github.com/commaai/openpilot/tree/master/tools/cabana#readme): our tool for reverse engineering CAN messages
* [can_print_changes.py](https://github.com/commaai/openpilot/blob/master/selfdrive/debug/can_print_changes.py): diff the whole CAN bus across two drives, such as one without any LKAS and one with LKAS
* [longitudinal maneuvers](https://github.com/commaai/openpilot/tree/master/tools/longitudinal_maneuvers): a tool for evaluating and tuning longitudinal control
* [opendbc data](https://commaai.github.io/opendbc-data/): a repository of longitudinal maneuver evaluations
