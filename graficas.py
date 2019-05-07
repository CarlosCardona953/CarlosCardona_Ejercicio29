import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d.axes3d import Axes3D, get_test_data
from matplotlib import cm

datos= np.loadtxt("Curvas.dat")
x=np.linspace(0,1,datos.shape[1])

plt.figure(figsize=(5,5))
plt.subplot(1,1)
plt.plot(x,datos[0],label="Tiempo inicial")
plt.plot(x,datos[-1],label="Tiempo final")
plt.legend()
plt.xlabel("Posicion [metros]")
plt.ylabel("Desplazamiento [metros]")


plt.subplot(1,2)
ax = Axes3D(fig)
xx, yy = np.mgrid[0:datos.shape[0], 0:datos.shape[1]]
ax.plot_surface(xx/50, yy/100, datos ,rstride=1, cstride=1, cmap=cm.coolwarm, linewidth=0, antialiased=False)
plt.ylabel("Posicion [metros]")
plt.xlabel("Tiempo [segundos]")

plt.savefig("Curvas.png")