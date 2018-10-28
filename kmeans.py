
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd


x1 = [[12,39],[20,36],[28,30],[18,52],[29,54],[33,46],[24,55],[45,59],[45,63],[52,70],[51,66],[52,63],[55,58],[53,23],[55,14],[61,8],[64,90],[69,7],[72,24]]
x2 = np.asarray(x1);

from sklearn.cluster import KMeans
wcss = []		#within-cluster sums of squares
for i in range(1, 11):
    kmeans = KMeans(n_clusters = i, init = 'k-means++', random_state = 42)
    kmeans.fit(x2)
    wcss.append(kmeans.inertia_)
plt.plot(range(1, 11), wcss)
plt.title('The Elbow Method')
plt.xlabel('Number of clusters')
plt.ylabel('WCSS')
plt.show()

# Fitting K-Means to the dataset
kmeans = KMeans(n_clusters = 3, init = 'k-means++', random_state = 42)
y_kmeans = kmeans.fit_predict(x2)

# Visualising the clusters
plt.scatter(x2[y_kmeans == 0, 0], x2[y_kmeans == 0, 1], s = 100, c = 'red', label = 'Cluster 1')
plt.scatter(x2[y_kmeans == 1, 0], x2[y_kmeans == 1, 1], s = 100, c = 'blue', label = 'Cluster 2')
plt.scatter(x2[y_kmeans == 2, 0], x2[y_kmeans == 2, 1], s = 100, c = 'green', label = 'Cluster 3')

plt.scatter(kmeans.cluster_centers_[:, 0], kmeans.cluster_centers_[:, 1], s = 300, c = 'yellow', label = 'Centroids')
plt.title('Clusters of customers')
plt.xlabel('Annual Income (k$)')
plt.ylabel('Spending Score (1-100)')
plt.legend()
plt.show()