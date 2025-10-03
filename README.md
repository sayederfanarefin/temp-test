# Minimum Refueling Stops — Multi-language (Python / Java / C)

Implement an algorithm to compute the **minimum number of refueling stops** required to reach a destination.

> ⚠️ **Choose ONE language only** for your submission: **Python**, **Java**, or **C**.  
> Indicate your choice in the `LANGUAGE` file at the root of this repo.

---

## How the Autograder (CI) knows your language

Create a root file named **`LANGUAGE`** containing exactly one of the following (lowercase):

```
python
```
or
```
java
```
or
```
c
```

The GitHub Actions workflow reads this file and runs **only** the tests for that language.  
If the file is missing or invalid, CI will fail with instructions.

---

## Problem Description

A car travels from a starting position (0) to a destination that is `target` miles east of the starting position.  

There are gas stations along the way. Each gas station is represented as `stations[i] = [position_i, fuel_i]`, where:
- `position_i` is the mile marker east of the starting position, and  
- `fuel_i` is the liters of gas available at that station.  

The car has an infinite tank and starts with `startFuel` liters of fuel. It uses **1 liter of gas per mile** driven.  
When the car reaches a gas station, it may stop and refuel, taking **all** the gas from that station.  

Return the **minimum number of refueling stops** the car must make to reach the destination.  
If it cannot reach the destination, return `-1`.  

> **Notes:**
> - If the car reaches a gas station with 0 fuel left, it can still refuel there.  
> - If the car reaches the destination with 0 fuel left, it is still considered to have arrived successfully.  

---

### Example 1
```
Input: target = 1, startFuel = 1, stations = []
Output: 0
Explanation: We can reach the target without refueling.
```

### Example 2
```
Input: target = 100, startFuel = 1, stations = [[10,100]]
Output: -1
Explanation: We cannot reach the target (or even the first gas station).
```

### Example 3
```
Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
Output: 2
Explanation:
- Start with 10 liters of fuel, drive to position 10 (fuel left = 0), refuel 60 → fuel = 60.
- Drive to position 60 (fuel left = 10), refuel 40 → fuel = 50.
- Drive to the target with 50 liters.
We made 2 refueling stops total.
```

---

### Constraints
- `1 <= target, startFuel <= 10^9`  
- `0 <= stations.length <= 500`  
- `1 <= position_i < position_{i+1} < target`  
- `1 <= fuel_i <= 10^9`  

---

## Your Task

Implement the function in **one** of the supported languages:

### Python
- Edit: `python/src/min_refuel.py`
- Function signature:
  ```python
  def min_refuel_stops(target: int, startFuel: int, stations: list[list[int]]) -> int:
      ...
  ```
- Run locally:
  ```bash
  cd python
  python -m venv .venv
  source .venv/bin/activate   # Windows: .venv\Scripts\activate
  pip install -r requirements.txt
  pytest -q
  ```

---

### Java
- Edit: `java/MinRefuelStops.java`
- Method signature:
  ```java
  public static int minRefuelStops(int target, int startFuel, int[][] stations)
  ```

#### Running locally
```bash
cd java
javac MinRefuelStops.java TestMinRefuelStops.java
java -ea TestMinRefuelStops   # note: -ea enables assertions
```

#### IDE Import Instructions
- **VS Code**
  1. Install *Extension Pack for Java*.
  2. Open the repo folder; then open the `java/` subfolder.
  3. Run with:
     ```bash
     javac MinRefuelStops.java TestMinRefuelStops.java
     java -ea TestMinRefuelStops
     ```
- **IntelliJ IDEA**
  1. *File → New → Project from Existing Sources…*, select the `java/` folder.
  2. Set language level to Java 17 (or compatible).
  3. Right-click `TestMinRefuelStops.main()` → *Run*.
- **Eclipse**
  1. *File → Import → Existing Projects into Workspace*.
  2. Select the `java/` folder; ensure a JRE 17+ is configured.
  3. Right-click `TestMinRefuelStops.java` → *Run As → Java Application*.
- **Replit**
  1. Create a *Java* Repl.
  2. Upload `MinRefuelStops.java` and `TestMinRefuelStops.java`.
  3. Run:
     ```bash
     javac MinRefuelStops.java TestMinRefuelStops.java && java -ea TestMinRefuelStops
     ```

#### What to submit for Java
- Set `LANGUAGE` to `java`.  
- Commit your edited `java/MinRefuelStops.java`.  
- Push — CI will run Java tests.

---

### C
- Edit: `c/min_refuel.c`
- Function signature:
  ```c
  int min_refuel_stops(int target, int startFuel, int stations[][2], int n);
  ```
- Build locally:
  ```bash
  cd c
  gcc -O2 -std=c11 -o test_min_refuel min_refuel.c test_min_refuel.c
  ./test_min_refuel
  ```

---

## Submission Checklist
1. Create/update the root **`LANGUAGE`** file with `python`, `java`, or `c`.  
2. Edit only the files for your chosen language.  
3. Commit and push. CI will run tests **only** for your chosen language.  
