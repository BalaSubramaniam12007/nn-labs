import numpy as np
import matplotlib.pyplot as plt

# Gaussian RBF
def gaussian_rbf(x, mu, gamma=1):
    return np.exp(-gamma * np.linalg.norm(x - mu)**2)

# XOR data
X1 = np.array([0,0,1,1])
X2 = np.array([0,1,0,1])
y  = np.array([0,1,1,0])

# Centers
mu1 = np.array([0,1])
mu2 = np.array([1,0])

# Transform inputs
f1, f2 = [], []
for i in range(len(X1)):
    point = np.array([X1[i], X2[i]])
    f1.append(gaussian_rbf(point, mu1))
    f2.append(gaussian_rbf(point, mu2))

f1 = np.array(f1)
f2 = np.array(f2)

# Plot (optional but useful for exam)
plt.subplot(1,2,1)
plt.scatter(X1, X2)
plt.title("Original (XOR)")

plt.subplot(1,2,2)
plt.scatter(f1, f2)
plt.title("After RBF")

plt.show()

# Linear model (training)
A = np.column_stack((f1, f2, np.ones(len(f1))))
W = np.linalg.pinv(A).dot(y)

# Predictions
pred = np.round(A.dot(W))

print("Predictions:", pred)
print("Actual:", y)
print("Weights:", W)