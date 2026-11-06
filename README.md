# Xyonix Virtual Memory Manager (VMM) 🚀

Xyonix Virtual Memory Manager (VMM) is a highly optimized, terminal-based Text User Interface (TUI) software built entirely in **pure C** inside the Dev-C++ environment. It is designed to act as a real-time simulator that bridges the gap between low-level computer science theories and hands-on practice by visually demonstrating how memory is allocated, tracked, and freed under the hood.

This interactive tool is perfect for software engineers, students, and low-level system architects who want to intuitively master core C concepts like Stack and Heap behaviors, dynamic allocations, and memory leak prevention without getting lost in abstract textbooks.

---

## 📊 Core Features

- **Live Memory Dashboard:** Boots instantly into a clean, real-time command-line terminal displaying live system resource metrics (e.g., tracking current Stack and Heap utilization percentages).
- **Static Allocation Visualizer:** Watch the Stack memory occupancy scale up dynamically in real-time as you declare variables and strings, with full data persistence verification through direct memory access.
- **Dynamic Allocation Simulator:** Perform runtime heap allocations using low-level calls like `malloc`/`calloc` and watch the system visually map the memory layout.
- **Instant Garbage Clean-up:** Witness exactly how the memory footprint drops down to its baseline the very moment the `free()` function is invoked.
- **Zero-Leak Guarantee:** Features an automated, safe exit routine executing rigorous standard low-level terminal clean-up operations to ensure absolutely no memory is leaked upon shutdown.

---

## 🛠️ How to Compile & Run

Since the source code is written in pure C logic, it is ultra-lightweight, extremely fast, and compatible with any standard C compiler. 

### Prerequisites
Make sure you have a C compiler like GCC installed on your system.

### Manual Compilation
Open your terminal or command prompt, navigate to the project directory, and execute the following commands:

```bash
# Compile the C source code
gcc XyonixVMM.cpp -o XyonixVMM

# Run the compiled binary execution file
./XyonixVMM
```
*(Note: If your file extension is saved as `.c`, simply replace `XyonixVMM.cpp` with `XyonixVMM.c` in the command above.)*

---

## 📦 Instant Run (Pre-Compiled Executable)

Don't want to install a C compiler or compile the code manually? No problem!
1. Navigate to the **"Releases"** section on the right-hand side of this GitHub repository page.
2. Download the pre-compiled executable binary file designed for your operating system.
3. Launch it directly in your terminal to start exploring right away!

---

## ⚙️ Architecture & Technical Stack

- **Language:** Pure C (Compatible with C99/C11 standards)
- **Environment:** Dev-C++ IDE
- **Interface:** Terminal Text User Interface (TUI)
- **Core Concepts Covered:** Static vs. Dynamic Allocation, Runtime Heap Control, Stack Pointers, Pointer De-referencing, Manual Memory Reclamation.

---

## 📄 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details. 

Feel free to use, modify, and distribute this software for educational or personal projects!

---

## 💡 Feedback, Suggestions & Contributions

This project is fully open-source and built in public! If you have any optimization ideas, feature requests, or bugs to report, feel free to open an **Issue** or submit a **Pull Request**. Let's build better low-level educational tools together!

*Developed with ⚡ and precision using C Programming.*
