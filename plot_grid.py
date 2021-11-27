## Python script for plotting grids
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import os
os.chdir("Grids")

# df_x = pd.read_csv("naive_grid_x.csv", header=None)
# df_y = pd.read_csv("naive_grid_y.csv", header=None)

df_x = pd.read_csv("grid_mn_7_x.csv", header=None)
df_y = pd.read_csv("grid_mn_7_y.csv", header=None)

# df_x = pd.read_csv("grid_mn_10_x.csv", header=None)
# df_y = pd.read_csv("grid_mn_10_y.csv", header=None)

# df_x = pd.read_csv("grid_mn_20_x.csv", header=None)
# df_y = pd.read_csv("grid_mn_20_y.csv", header=None)

# df_x = pd.read_csv("grid_mn_10_30_x.csv", header=None)
# df_y = pd.read_csv("grid_mn_10_30_y.csv", header=None)

# df_x = pd.read_csv("grid_mn_30_10_x.csv", header=None)
# df_y = pd.read_csv("grid_mn_30_10_y.csv", header=None)

# df_x = pd.read_csv("grid_mn_50_50_x.csv", header=None)
# df_y = pd.read_csv("grid_mn_50_50_y.csv", header=None)

# df_x = pd.read_csv("grid_mn_100_100_x.csv", header=None)
# df_y = pd.read_csv("grid_mn_100_100_y.csv", header=None)

xx = df_x.iloc[:,:-1].to_numpy()
yy = df_y.iloc[:,:-1].to_numpy()
print(xx)
print(yy)

plt.plot(xx,yy, "c")
plt.plot(xx.transpose(),yy.transpose(), "c")

plt.show()