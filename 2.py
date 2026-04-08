import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

# Perceptron class
class Perceptron:
    def __init__(self, lr=0.1):
        self.lr = lr
        self.w = None
        self.b = 0
        self.errors = []

    def fit(self, X, y, epochs=10):
        self.w = np.zeros(X.shape[1])
        self.b = 0

        for _ in range(epochs):
            err = 0
            for xi, yi in zip(X, y):
                update = self.lr * (yi - self.predict(xi))
                self.w += update * xi
                self.b += update
                if update != 0:
                    err += 1
            self.errors.append(err)

    def predict(self, X):
        return np.where(np.dot(X, self.w) + self.b >= 0, 1, -1)




# Load dataset
df = pd.read_csv('iris.data', header=None)

# Select data
X = df.iloc[:100, :2].values
y = df.iloc[:100, 4].values

# Convert labels
y = np.where(y == 'Iris-setosa', 1, -1)

# Normalize data
X = (X - X.mean()) / X.std()    #axis=0

# Train-test split

# Train model
model = Perceptron(lr=0.01)
model.fit(X_train, y_train)

# Evaluate
y_pred = model.predict(X_test)
print("Accuracy:", accuracy_score(y_test, y_pred) * 100)

# Plot errors
plt.plot(range(1, len(model.errors)+1), model.errors, marker='o')
plt.xlabel("Epoch")
plt.ylabel("Errors")
plt.show()