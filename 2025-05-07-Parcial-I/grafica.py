import matplotlib.pyplot as plt
import numpy as np
# import seaborn as sns
# sns.set_context("poster")

# read data
x, sl = np.loadtxt("PrimosPares1.txt", unpack=True)

# plot 
fig, ax = plt.subplots()
ax.plot(x, sl, '-o', label='error forward')
ax.set_xlabel('$x$')
ax.set_ylabel('Second Largest Number')
ax.legend()
fig.savefig('sl.pdf')