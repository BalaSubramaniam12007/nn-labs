
# Load dataset
url = 'iris.data'
cols = ['SepalLength', 'SepalWidth', 'PetalLength', 'PetalWidth', 'Species']
df = pd.read_csv(url, names=cols)

# Split features & labels
X = df.iloc[:, 0:4]
y = df.iloc[:, 4]

# Encode labels (multiclass)
y = LabelEncoder().fit_transform(y)


# Train-test split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

# Scaling
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# MLP model
model = MLPClassifier(hidden_layer_sizes=(10,10), max_iter=1000)


# Train
model.fit(X_train, y_train)

# Predict
pred = model.predict(X_test)

# Evaluation
print(confusion_matrix(y_test, pred))
print(classification_report(y_test, pred))