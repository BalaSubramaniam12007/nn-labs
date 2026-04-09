import numpy as np
import matplotlib.pyplot as plt


# Network size
n_x, n_h, n_y = 2, 2, 1
m = x.shape[1]
lr = 0.1

np.random.seed(2)
w1 = np.random.rand(n_h, n_x)
w2 = np.random.rand(n_y, n_h)

losses = []

# Activation
def sigmoid(z):
    return 1 / (1 + np.exp(-z))

# Training
for _ in range(10000):

    # Forward pass
    A1 = sigmoid(np.dot(W1, X))
    A2 = sigmoid(np.dot(W2, A1))

    # Loss
    loss = -(1/m) * np.sum(y*np.log(A2) + (1-y)*np.log(1-A2))
    losses.append(loss)

    # Backpropagation
    dZ2 = A2 - y
    dW2 = np.dot(dZ2, A1.T) / m

    dZ1 = np.dot(W2.T, dZ2) * A1 * (1 - A1)
    dW1 = np.dot(dZ1, X.T) / m

    # Update weights
    W1 -= lr * dW1


# Loss graph
plt.plot(losses)
plt.xlabel("Epochs")
plt.ylabel("Loss")
plt.show()

# Prediction
print("Predictions:")

A2 = sigmoid(np.dot(W2, sigmoid(np.dot(W1, X))))
print(np.round(A2))