# 🚗 ECU Observability Logger (C++ Simulation)

## 🧠 Overview

This project simulates an **embedded observability and telemetry system** inspired by automotive environments (e.g., QNX-based ECUs).

It models how data flows from a device through logging and telemetry pipelines, with a focus on:

- reliability under failure
- runtime configuration (control plane)
- system observability
- non-blocking behavior

> device → logging → telemetry → retry → observability

---

## ⚙️ Key Features

### 📊 Observability System
- Local logging of system state (`ecu_log.txt`)
- Structured recording of telemetry outcomes (success/failure)
- Clear visibility into system behavior over time

---

### 🔄 Control Plane (Runtime Configuration)
System behavior is controlled via `config.txt`:

- Enable/disable logging
- Enable/disable telemetry
- Adjust send interval
- Set temperature threshold
- Configure retry behavior

No recompilation required.

---

### 📡 Telemetry Pipeline
- Simulated data transmission
- Asynchronous send behavior
- Non-blocking main loop

---

### 🔁 Failure Handling & Retry Logic
- Simulated unreliable transport conditions
- Configurable retry attempts
- Retry delay between attempts
- Final failure detection and logging

---

### 🌡️ State-Based Behavior
- Temperature threshold determines system state:
  - `NORMAL`
  - `HIGH`
- State is included in telemetry and logs

---

## 🧱 Architecture


[ Simulated ECU ]
↓
Main Control Loop
↓
┌───────────────┐
│ │
[ Logger ] [ Telemetry ]
│ │
↓ ↓
ecu_log.txt Retry + Send
↓
Console Output


---

## 💻 Tech Stack

- C++ (modular system design)
- MSYS2 / g++ (build environment)
- File-based logging
- Threading (simulated async behavior)
- Config-driven system control

---

## 🚗 Automotive Relevance

This project reflects patterns used in real vehicle systems:

| Concept | Real System | This Project |
|--------|------------|-------------|
| ECU | Embedded control unit | Main loop |
| QNX/Linux | Embedded OS | C++ runtime |
| Logging system | ECU logs | File logging |
| Telemetry pipeline | ECU → cloud | Retry send logic |
| Observability | Fleet diagnostics | Log + output |

---

## 🚀 How to Run

### Compile

```bash
g++ main.cpp logger.cpp telemetry.cpp config.cpp -o ecu_logger.exe
Run
./ecu_logger.exe
⚙️ Configuration

Edit config.txt:

logging_enabled true
telemetry_enabled true
send_interval_ms 2000
temperature_threshold 75
max_retries 3
retry_delay_ms 500
🧪 Example Behavior
Attempt 1/3: Telemetry send failed: temp=73,state=NORMAL
Retrying in 500 ms...
Attempt 2/3: Telemetry send failed: temp=73,state=NORMAL
Retrying in 500 ms...
Attempt 3/3: Sending telemetry: temp=73,state=NORMAL
[LOG] Telemetry send failed after retries: temp=74,state=NORMAL
🧠 Design Highlights
Separation of concerns (control loop, logging, telemetry)
Config-driven behavior (control plane simulation)
Retry-based resilience (data delivery reliability)
Observability through structured logging
Simulation of real-world embedded constraints
🔥 What This Demonstrates
Embedded-style system design in C++
Telemetry pipelines under unreliable conditions
Runtime control over system behavior
Observability-first architecture
Failure-aware system design
👤 Author

Jay Tranberg
Systems Engineer — Embedded, Observability & Data Platforms
🌐 jaytranberg.com

🚀 Future Enhancements
Local queue / buffering for failed telemetry
Structured logs (JSON / protobuf-style)
HTTP-based telemetry delivery to backend
Ring buffer implementation (embedded pattern)

---

# 💥 What this does for you

If a recruiter opens this:

👉 They instantly see:
- embedded thinking
- telemetry pipeline
- observability
- failure handling

Not:
❌ “random C++ project”

---

# ⚡ Optional power move (HIGHLY recommended)

At the VERY TOP, add one line:

```md
Built as a focused simulation of ECU-level observability and telemetry patterns aligned with modern automotive data architectures (e.g., GM vehicle observability systems).