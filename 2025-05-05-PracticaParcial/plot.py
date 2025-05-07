import matplotlib.pyplot as plt
import numpy as np
# import seaborn as sns
# sns.set_context("poster")

# read data
x, vr, vn = np.loadtxt("derivatives.txt", unpack=True)

# plot 
fig, ax = plt.subplots()
ax.plot(x, vr, '-o', label='derivada exacta')
ax.plot(x, vn, '-s', label='aproximacion numerica')
ax.set_xscale('log')
ax.set_yscale('log')
ax.set_xlabel('$x$')
ax.set_ylabel('derivada')
ax.legend()
fig.savefig('deriv.pdf')