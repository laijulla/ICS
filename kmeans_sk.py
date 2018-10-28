from sklearn.cluster import KMeans
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
n=19
i=0
colmap = {1: 'y', 2: 'r', 3: 'g'}
X = np.array([[12, 39], [20,36], [28, 30],[18, 52], [29, 54], [33, 46],[24,55],[45,59],[45,63],[52,70],[51,66],[52,63],[55,58],[53,23],[55,14],[61,8],[64,19],[69,7],[72,24]])
kmeans = KMeans(n_clusters=3, random_state=0).fit(X)
print(kmeans.labels_)
kmeans.predict([[0, 0], [80, 80]])
print(kmeans.cluster_centers_)
for i in set(kmeans.labels_):
    index = kmeans.labels_ == i
    plt.plot(X[index,0], X[index,1], 'o')

for i in range(3):
	plt.scatter(kmeans.cluster_centers_[i][0],kmeans.cluster_centers_[i][1],color=colmap[i+1])
plt.xlim(0, 80)
plt.ylim(0, 80)
plt.show()