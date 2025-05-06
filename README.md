# 🤖 Mobile Robot Simulation

This project simulates the movement of a differential-drive mobile robot navigating toward multiple goals while avoiding obstacles. The robot's motion is controlled by adjusting the angular velocities of its two wheels.

---

## 🚀 Features

- **Goal-Oriented Navigation**: The robot aims to reach as many predefined goals as possible within a set timeframe.
- **Obstacle Avoidance**: Implements basic obstacle detection to prevent collisions and minimize delays.
- **Differential Drive Kinematics**: Simulates realistic movement based on wheel velocities.
- **Custom Graphics**: Visual representation using `graphics.h` for simulation display.

---

## 🛠️ Technologies Used

- **Language**: C++
- **IDE**: Dev-C++
- **Libraries**:
  - `graphics.h`
  - `iostream`
  - `math.h`
  - `conio.h`
  - `fstream`
  - `string`

---

## 📁 Project Structure

- `main.cpp` – Entry point for simulation control and rendering loop.
- `Robot.dev` – Dev-C++ project configuration file.
- `figure.h / figure.cpp` – Contains the `Figure` class for basic shape rendering.
- `obstacle.h / obstacle.cpp` – Handles static obstacle logic and display.
- `goal.h / goal.cpp` – Manages goal points the robot navigates to.
- `dessin.h / dessin.cpp` – Drawing utility functions for the simulation.
- `Obstacle.obs` – Input file defining obstacle positions.
- `position.pts` – Input file defining goal positions.

---

## 🔧 How to Run

1. Open `Robot.dev` in Dev-C++.
2. Ensure all `.h` and `.cpp` files are included in the project.
3. Build and compile the project.
4. Run the executable to start the simulation.

---

## 🔮 Future Improvements

- Add path planning algorithms (A*, Dijkstra).
- Improve obstacle avoidance with simulated sensors.
- Upgrade visual output using modern graphics libraries.
- Port simulation to cross-platform or web-based environments.

---

## 👨‍💻 Author

**Oussama Bek**  
[GitHub Profile](https://github.com/OussamaBek)
