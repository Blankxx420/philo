# Philosophers - @42

<p align="center">
  <img src="https://img.shields.io/badge/Score-100%2F100-success?style=for-the-badge&logo=42" alt="Score 42">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="Language C">
</p>

## 📝 Overview

**Philosophers** is a 42 School project that introduces the basics of **multi-threading** and **concurrent programming**. Based on Edsger Dijkstra’s famous *Dining Philosophers problem*, the objective is to create a simulation where a number of philosophers sit around a table with a bowl of spaghetti and a limited number of forks. 

The core challenge of this project is learning how to manage shared resources using **threads** and **mutexes**, while avoiding synchronization issues like **deadlocks**, **data races**, and **starvation**.

## 🧠 The Problem & Rules

* A number of philosophers sit at a round table. There is a single fork between each pair of philosophers.
* A philosopher needs **two forks** (the one on their left and the one on their right) to eat.
* Philosophers alternate between three states: **Eating**, **Sleeping**, and **Thinking**.
* While eating, they hold their forks. When finished, they put them down and start sleeping. Once they wake up, they start thinking until they can grab forks again.
* If a philosopher doesn't start eating within `time_to_die` milliseconds since the beginning of their last meal (or the start of the simulation), they **die of starvation**, and the simulation stops immediately.

## 🛠️ Technical Implementation

* **One Thread per Philosopher:** Each philosopher runs inside their own independent thread.
* **Mutexes as Forks:** Every fork is protected by a mutex to ensure that two philosophers cannot grab the exact same fork at the exact same time (preventing data races).
* **State Protection:** Crucial variables (like the time a philosopher last ate or the death state flag) are also protected by mutexes to prevent conflicting simultaneous read/write operations.

## 🚀 Installation & Usage

### Compilation

To compile the `philo` executable, run the following command at the root of the repository:

```bash
make
