import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler

# Load dataset
df = pd.read_csv("Churn_Modelling.csv")

# Check missing values and duplicates
print(df.isnull().sum())
print(df.duplicated().sum())

# Outlier detection using IQR
num = df.select_dtypes(include='number')
Q1 = num.quantile(0.25)
Q3 = num.quantile(0.75)
IQR = Q3 - Q1
outliers = ((num < (Q1 - 1.5*IQR)) | (num > (Q3 + 1.5*IQR))).sum()
print(outliers)

# Split features and target
X = df[['CreditScore', 'Gender', 'Age','Balance', 'Geography','IsActiveMember', 'EstimatedSalary']]

y = df['Exited']

# Encode categorical data
X['Gender'] = X['Gender'].map({'Male':1, 'Female':0})
X = pd.get_dummies(X, columns=['Geography'], drop_first=True)



# Scale features
scaler = StandardScaler()
X = scaler.fit_transform(X)

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=0)

# Print shapes
print("Train:", X_train.shape)
print("Test:", X_test.shape)