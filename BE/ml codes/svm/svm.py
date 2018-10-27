from sklearn import datasets
import numpy as np
import pandas as pd
from sklearn import tree
from sklearn import metrics
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC
iris = datasets.load_iris()
X = iris.data[:, [2, 3]]
y = iris.target
print('Class labels:', np.unique(y))

sc = StandardScaler()
sc.fit(X)
X = sc.transform(X)
# split data into train and test

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=0)

clf = SVC(kernel='linear', C=1.0, random_state=0)
clf.fit(X_train, y_train)

# generate evaluation metrics
print "Train - Accuracy :", metrics.accuracy_score(y_train, clf.predict(X_train)) * 100
print "Train - Confusion matrix :\n ",metrics.confusion_matrix(y_train, clf.predict(X_train))
print "Train - classification report :\n ", metrics.classification_report(y_train, clf.predict(X_train))
print "Test - Accuracy :", metrics.accuracy_score(y_test, clf.predict(X_test)) * 100
print "Test - Confusion matrix :\n ",metrics.confusion_matrix(y_test, clf.predict(X_test))
print "Test - classification report :\n", metrics.classification_report(y_test, clf.predict(X_test))

# plots
from sklearn.datasets import make_classification
#from mlxtend.plotting import plot_decision_regions
import matplotlib.pyplot as plt
X, y = make_classification(100, 2, 2, 0, weights=[.5, .5], random_state=0)
# build a simple logistic regression model
plt.plot(X,y)
clf = SVC(kernel='linear', random_state=0)
clf.fit(X, y)
# get the separating hyperplane
w = clf.coef_[0]
a = -w[0] / w[1]
xx = np.linspace(-5, 5)
yy = a * xx - (clf.intercept_[0]) / w[1]
# plot the parallels to the separating hyperplane that pass through the
# support vectors
b = clf.support_vectors_[0]
yy_down = a * xx + (b[1] - a * b[0])
b = clf.support_vectors_[-1]
yy_up = a * xx + (b[1] - a * b[0])
#Plot the decision boundary
#plot_decision_regions(X, y, clf=clf)
# plot the line, the points, and the nearest vectors to the plane
plt.scatter(clf.support_vectors_[:, 0], clf.support_vectors_[:, 1], s=80,
facecolors='none')
plt.plot(xx, yy_down, 'k--')
plt.plot(xx, yy_up, 'k--')
plt.xlabel('X1')
plt.ylabel('X2')
plt.legend(loc='upper left')
plt.tight_layout()
plt.show()
