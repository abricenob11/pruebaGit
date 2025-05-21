import matplotlib.pyplot as plt
import numpy as np
# import seaborn as sns
# sns.set_context("poster")

# read data
x, sl = np.loadtxt("PrimosPares1.txt", unpack=True)
figsize=(12, 7)
# plot 12 7
fig, ax = plt.subplots(figsize=(12, 7))
ax.plot(x, sl, color='royalblue', linewidth = 2, linestyle = '-', marker = 'o', markersize = 5, label = 'curva')
ax.set_xlabel('$x$', fontsize = 12)
x_margin = 0.1 * x.max()
ax.set_xlim(-x_margin, x.max() + x_margin)
ax.set_yticks(np.arange(0, 22, 2))  # esto controla cada cuanto cambia el eje
ax.set_ylabel('Number', fontsize = 12)
ax.set_title('Second Largest Numbe', fontsize = 14, pad = 20, color = 'red')
ax.legend()
fig.savefig('sl.pdf')
plt.show()