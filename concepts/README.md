# TDD Concept

### The Host System

The host system (often a PC, laptop, or workstation) is the general-purpose
computer where software is developed, compiled, and debugged before being
deployed to the target.

### The Target System

The target system is the actual, often resource-constrained, electronic board or
device where the embedded software ultimately runs. 

### The Cloud

The cloud represents remote, internet-accessible servers and services used to
enhance the development lifecycle and the functionality of embedded systems.

## Challenges in TDD on a Target

1. **Hardware Dependency and Isolation Difficulty:** The most significant hurdle
is the tight coupling of software to hardware peripherals (e.g., ADCs, timers,
communication interfaces). TDD requires developers to perform unit testing,
which necessitates isolating the logic under test. When running tests on the
target, the code inherently interacts with the real hardware, making true
software isolation difficult. To overcome this, developers must create and
maintain test doubles (mocks or stubs) to simulate the hardware's behavior,
which represents an added, non-trivial development effort.

2. **Slow Feedback Loop:** The TDD methodology is severely impacted by the slow
feedback loop. Unlike PC-based development where tests run instantly, in
embedded systems, every change requires a sequence of time-consuming steps:
compiling the application and test code, linking it, and then uploading/flashing
the binary to the target device's limited memory. This process, repeated for
every failed test, significantly slows down the entire cycle, discouraging
adherence to TDD principles and reducing developer productivity. Debugging test
failures on the physical hardware using specialized tools (like JTAG/SWD)
further complicates and extends the time to fix.

3. **Resource and Performance Constraints:** Embedded systems typically operate
with strict resource limitations on both Flash memory (storage) and RAM (runtime
memory). Implementing a full-featured unit test framework, along with all the
necessary test cases and support code (like hardware mocks), often consumes a
critical amount of these limited resources. The overhead of the testing
framework itself can prevent the tests from running successfully or, critically,
alter the performance characteristics of the production code, making it
difficult to test time-critical functions under realistic conditions.

4. **Real-Time and Non-Deterministic Testing:** Many embedded systems are
real-time, requiring deterministic behavior and precise timing. Testing code
related to interrupt service routines (ISRs), concurrency, and specific timing
requirements on the target device is extremely difficult. The act of running the
test harness itself can introduce delays or overhead that invalidate the timing
being tested, leading to non-deterministic and unreliable test results—a core
violation of automated testing standards.

5. **Toolchain and Setup Complexity:** The embedded development environment is
inherently more complex. Setting up a continuous integration (CI) or local
environment that correctly configures the cross-compiler, linker scripts, and
flash utilities to build and execute tests on a specific target architecture
requires specialized knowledge. Ensuring the chosen TDD framework is compatible
with the vendor's software development kit (SDK) and the target operating system
(if present) adds substantial configuration overhead and complexity.

In response to these challenges, many embedded teams adopt a hybrid strategy:
they perform the majority of their unit testing off-target (on a PC using mocks
to simulate hardware) for a fast TDD cycle, reserving the physical on-target
testing for critical integration and system-level verification where the actual
hardware interaction must be confirmed.

## TDD Benefits in Embedded Systems (Concise)

- **Defect Prevention:** TDD catches bugs immediately upon introduction,
drastically cutting down on slow, complex on-target debugging time.

- **Better Design:** It forces decoupling of software from hardware, leading to
clean Hardware Abstraction Layers (HALs). This makes the core logic modular and
portable.

- **Safety Net:** Automated tests provide a constant Regression Test Suite,
allowing developers to perform safe refactoring and maintain a healthy,
long-lived codebase.

- **Executable Docs:** The tests act as reliable, living documentation that
always matches the code's current behavior.

- **Faster Parallel Work:** Core logic can be developed and tested off-target
using mocks while waiting for the physical hardware, speeding up the overall
project timeline.

## Automated Tests

**Basic Definition:** 

Methodology for functional validation of software implementations.

Dynamic analysis tool.

Expected behaviors are defined in code:

- setup
- execution
- verification

A testing framework provides the tools for defining test cases and analyzing
expectations.

Code under test and test code are compiled and generate an executable.

**Multiply Example:**

- [calculator.h](lib/calculator.h)
- [calculator.c](lib/calculator.c)
- [CalculatorTests.cpp](tests/calculatorTests.cpp)
- [Makefile](Makefile)

## How to install cpputest

git clone https://github.com/cpputest/cpputest.git
cd cpputest
mkdir cpputest_build
cmake -B cpputest_build
cmake --build cpputest_build
cd cpputest_build
make install