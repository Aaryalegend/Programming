import numpy as np
import matplotlib.pyplot as plt

# Simulating computation times for different numbers of threads (1 to 16)
threads = np.arange(1, 17)
times = np.array([
    np.random.uniform(10, 12) / t for t in threads  # Simulating inverse relation (more threads, less time)
])

# Plotting the computation times
plt.figure(figsize=(10, 6))
plt.plot(threads, times, marker='o', color='blue', linestyle='-', linewidth=2, markersize=8)
plt.title("Matrix Multiplication Time vs. Number of Threads")
plt.xlabel("Number of Threads")
plt.ylabel("Computation Time (seconds)")
plt.xticks(threads)
plt.grid(True)
plt.show()