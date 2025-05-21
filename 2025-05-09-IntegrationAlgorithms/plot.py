import matplotlib.pyplot as plt
import numpy as np
# import seaborn as sns
# sns.set_context("poster")

# read data
N, tr, si, r_t, r_s = np.loadtxt("errores.txt", unpack=True)

# plot 
fig, ax = plt.subplots()
ax.plot(N, tr, '-o', label='Trapezoid')
ax.plot(N, si, '-s', label='Simpson')
ax.plot(N, r_t, '-*', label='Richardson trapezoid')
ax.plot(N, r_s, '-+', label='Richardson simpson')
ax.set_xscale('log')
ax.set_yscale('log')
ax.set_xlabel('$N$')
ax.set_ylabel('Errores')
ax.legend()
fig.savefig('errores.pdf')
