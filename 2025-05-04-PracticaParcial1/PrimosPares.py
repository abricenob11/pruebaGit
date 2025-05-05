import matplotlib.pyplot as plt
import numpy as np
# import seaborn as sns
# sns.set_context("poster")

# read data
x, n = np.loadtxt("PrimosPares.txt", unpack=True)

# plot 
fig, ax = plt.subplots()
ax.plot(x, n)
ax.set_xlabel('n')
ax.set_ylabel('norma')
ax.legend()
fig.savefig('norma_vs_n.pdf')